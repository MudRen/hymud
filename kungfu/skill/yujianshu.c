//modified by vikee
//2000.10
inherit SKILL;
#include <ansi.h>;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string type() { return "martial"; }
string martialtype() { return "skill"; }
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int ruhe(object me, object victim, object weapon, int damage);
string* skill_head =({
        "$N身形稍退，使出一招 「御剑生风」",
        "$N于朦朦胧胧中，使出一招 「御剑如虹」",
        "$N四处游走，一招 [御剑成龙]",
        "$N神态悠闲，一招 「御剑行空」",
        "$N中宫直进，突然一招 「御剑无影」",
        "$N双脚一顿，笔直跃起，一招 「御剑飞腾」",
});

string* skill_tail =({
        "，手中$w不停地颤抖着",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，手中$w去势飘忽不定，只看得$n眼花缭乱",
        "，手中$w带起点点寒光，指向$n前胸穴道",
});

mapping *action = ({
                ([      "name":                 "御剑生风",
                "action":
"$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势"+BLINK""+HIC"「御剑生风」"NOR"果然是无孔不入",
                "dodge":                5,
                "parry":                10,
                "damage":                350,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "御剑如虹",
                "action":
"$N手中$w带起点点寒光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势"+BLINK""+HIM"「御剑如虹」"NOR"亦真亦幻，实是难防",
                "dodge":                15,
                "parry":                15,
                "damage":               340,
                "damage_type":          "震伤"
        ]),
        ([      "name":                 "御剑成龙",
                "action":
"$N在$n四周游走，一招"+BLINK""+HIY"[御剑成龙]"NOR",手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
                "dodge":                15,
                "parry":                10,
                "damage":               335,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "御剑行空",
                "action":
"$N仗起手中$w，带出点点寒光，罩住$n的胸腹，只等$n的破绽。\n"
"这招"+BLINK""+HIR"「御剑行空」"NOR"直如细雨般紧密，$n实在不知$w将要指向自己身上何处",
                "dodge":                25,
                "parry":                10,
                "damage":               335,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "御剑无影",
                "action":
"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招"+BLINK""+HIB"「御剑无影」"NOR"令人耳目一新。$n只觉浑身一紧，$w已刺到了$l",
                "dodge":                15,
                "parry":                15,
                "damage":               335,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "御剑飞腾",
                "action":
"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$w却突然转向了$n的左足！这招"+BLINK""+HIG"「御剑飞腾」"NOR"确实神鬼莫测",
                "dodge":                10,
                "parry":                15,
                "damage":               345,
                "damage_type":          "刺伤"
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");

        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("你的磐石神功修为不够。\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("你的快活十三掌修为不够。\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("你的泰山剑法不够。\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("你的风神诀不够。\n");
        if( me->query_skill("aohan-liujue", 1) < 200)
                return notify_fail("你的傲寒六决不够。\n");

        if( me->query_skill("shiba-pan", 1) < 200)
                return notify_fail("你的泰山十八盘不够。\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一柄剑才能练习剑法。\n");
        return 1;
}

int practice_skill(object me)
{
        object ob;
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("yujianshu");

        if (dod<swo/2)
                return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你体质欠佳，强练御剑术有害无益。\n");
        if ((int)me->query("neili") < 55)
                return notify_fail("你内力不足，强练御剑术有走火入魔的危险。\n");
        if( me->query_skill("aohan-liujue", 1) < 200)
                return notify_fail("你的傲寒六决不够。\n");
                
        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("你的磐石神功修为不够。\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("你的快活十三掌修为不够。\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("你的泰山剑法不够。\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("你的风神诀不够。\n");

        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一柄剑才能练习剑法。\n");

        me->receive_damage("qi", 30);
        me->add("neili", -35);

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword"||usage=="parry";
}


mapping query_action(object me, object weapon)
{
        int d_e1 = 15;
        int d_e2 = 30;
        int p_e1 = 25;
        int p_e2 = 15;
        int f_e1 = 100;
        int f_e2 = 250;
        int m_e1 = 310;
        int m_e2 = 410;
         int level;
         object target;
         mapping pre;
         string *skill, a, b;
        int i, lvl, seq, ttl = sizeof(action);
        if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -30);   
        me->add("neili", -100); 
        me->set_temp("ruhe_finish");    
        me->delete_temp("ruhe_count");  
        me->delete_temp("ruhe_hit");    
        return ([
        "action":HIY"$N左手计算已毕，$w"+HIY"出招，正是泰山派剑法中最高深的绝艺「岱宗如何」，这一剑算准了$n的一切应变後着，实是威力无俦，博大精深"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 820,
        "post_action": (: ruhe :),      
        "damage_type":  "刺伤"]);
        }
        else if((int)me->query_skill("sword",1)> random(300)+100
        && me->query("neili") > 200 
        && me->query_temp("ruhe")){
        me->add("neili", -20);
        return ([
        "action":YEL"$N$w"+YEL"倏地向$n刺出，连连出剑，每一剑的剑招皆苍然有古意，招数古朴，内藏奇变，正是「五大夫剑」"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 800+random(55),
        "skill_name" : "五大夫剑",
        "post_action": (: ruhe :),      
        "damage_type":  "刺伤"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
        && me->query("neili") > 100
        && me->query_temp("ruhe")){
        me->add("neili", -10);
        return ([
        "action":HIC"$N陡然向$n连环三剑，$w"+HIC"使得犹似行云流水，大有善御者驾轻车而行熟路之意，将「快活三」剑招发挥得淋漓尽致"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 800+random(33),
        "skill_name" : "快活三",
        "post_action": (: ruhe :),      
        "damage_type":  "刺伤"]);
        }
                 level   = (int) me->query_skill("yujianshu",1);
         lvl = (int)me->query_skill("yujianshu", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
        
}
/*mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/
string perform_action_file(string action)
{
        return __DIR__"yujianshu/" + action;
}

 



int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
                CYN"不料$N左手屈指连算，已算准了$n的腾挪方位，又即挺剑出招！\n"NOR,
                CYN"但是$n的武功门路已被$N算得清清楚楚，眼见已避开$N的招数，"+weapon->name()+CYN"竟又直逼而至！\n"NOR,
        });
if (!victim) return 0;
if (!me) return 0;
if (!weapon) return 0;
if (!damage) return 0;
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
if (!victim) return 0;
if (!me) return 0;
victim->start_busy(2);
//if (victim=me) return 0;
if (victim && me
&& !me->query_temp("dsauto")
&& !me->is_busy())
{
victim->start_busy(2);
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
           }
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("panshi-shengong",1);
damage= 50+(int) me->query("neili",1)/20;
damage2=random(me->query_skill("yujianshu",1))+50;

if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "panshi-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("yujianshu",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}