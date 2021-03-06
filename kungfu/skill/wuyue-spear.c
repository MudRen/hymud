//wuyue-club 五岳神枪
/*
五岳神枪    dodge  0    parry  -10    damage  25
开国武成王黄飞虎的成名枪法，有百折不会之势
令人难以招架，威力也不可小视
*/

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N使出一招 「泰山压顶」",
        "$N运足精神，好一招 「华岳插云」",
        "$N一个虎跳使出个 「衡峰溪绕」",
        "$N神态悠闲，一招 「五岳朝宗」",
        "$N人枪合一，突然一招 「太室参佛」",
        "$N一口气抖出五朵枪花，暗喝一声 「恒岭悬空」",
});

string* skill_tail =({
        "，手中$w向$n劈头改脑直扫了下来。",
        "，手中$w若有若无地刺向$n$l。",
        "，$N手中$w势若飞瀑刺向$n的$l。",
        "，手中$w轻妙地划向$n的$l。",
        "，枪枪不离$n要害。",
        "，手中$w带出一道利闪直奔$n$l。",
});

mapping *action = ({
        ([      "action":
"$N使一招"+BLINK""+HIM"「泰山压顶」"NOR"，手中$w向$n劈头改脑直扫了下来",
                "damage":               340,
                "dodge":                15,
                "parry":                15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招"+BLINK""+HIC"「华岳插云」"NOR"挑向$n",
                "damage":               340,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w势若飞瀑刺向$n的$l，好一招"+BLINK""+HIG"「衡峰溪绕」"NOR"",
                "damage":               345,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N 一口气抖出五朵枪花，暗喝一声"+BLINK""+HIB"「五岳朝宗」"NOR"。枪枪不离$n要害",
                "damage":               350,
                "dodge":                10,
                "parry":                15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N一个虎跳使个"+BLINK""+HIY"「太室参佛」"NOR"，手中$w带出一道利闪直奔$n$l",
                "damage":               340,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N腾空飞气，人枪合一，$w只落$n$l，正是一招"+BLINK""+HIW"「恒岭悬空」"NOR"",
                "damage":               340,
                "dodge":                5,
                "parry":                25,
                "damage_type":  "刺伤"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力不够，没有办法练五岳神枪。\n");

if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
     return notify_fail("必须寒冰真气才能学。\n");

if ((int)me->query_skill("hanbing-zhenqi", 1) < 200)
                 return notify_fail("你的寒冰真气火候不够，无法学。\n");

        if( me->query_skill("zhongyuefeng", 1) < 200)
                return notify_fail("你的中岳神风修为不够。\n");

        if( me->query_skill("songshan-jian", 1) < 200)
                return notify_fail("你的嵩山奇峰剑修为不够。\n");

        if( me->query_skill("songshan-sword", 1) < 200)
                return notify_fail("你的嵩山剑法修为不够。\n");
                
        if( me->query_skill("fuguanglueying", 1) < 200)
                return notify_fail("你的浮光掠影修为不够。\n");

        if( me->query_skill("poyun-hand", 1) < 200)
                return notify_fail("你的破云手修为不够。\n");
                
        if( me->query_skill("songyang-strike", 1) < 200)
                return notify_fail("你的大嵩阳掌修为不够。\n");           

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="club") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("wuyue-spear",1);
         lvl = (int)me->query_skill("wuyue-spear", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        object ob;
      if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
     return notify_fail("必须寒冰真气才能学。\n");

if ((int)me->query_skill("hanbing-zhenqi", 1) < 200)
                 return notify_fail("你的寒冰真气火候不够，无法学。\n");
        if( me->query_skill("zhongyuefeng", 1) < 200)
                return notify_fail("你的中岳神风修为不够。\n");

        if( me->query_skill("songshan-jian", 1) < 200)
                return notify_fail("你的嵩山奇峰剑修为不够。\n");

        if( me->query_skill("songshan-sword", 1) < 200)
                return notify_fail("你的嵩山剑法修为不够。\n");
                
        if( me->query_skill("fuguanglueying", 1) < 200)
                return notify_fail("你的浮光掠影修为不够。\n");

        if( me->query_skill("poyun-hand", 1) < 200)
                return notify_fail("你的破云手修为不够。\n");
                
        if( me->query_skill("songyang-strike", 1) < 200)
                return notify_fail("你的大嵩阳掌修为不够。\n");           

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");
        if( (int)me->query("qi") < 30 
        ||    (int)me->query("neili") < 50  )
                return notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -35);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wuyue-spear/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("hanbing-zhenqi",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("wuyue-spear",1))+50;
if( random(8)==0 
     && me->query_skill("wuyue-spear",1) > 290) {
        victim->start_busy(3);
        victim->apply_condition("cold_poison", victim->query_condition("cold_poison") + random(4));
        return HIC"$n突然全身一冷！无法动弹，竟已受了极重的寒冰真气！\n"NOR;
}

if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "hanbing-zhenqi")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("wuyue-spear",1)) > 50 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("wuyue-spear",1);
        level2= (int) me->query_skill("wuyue-spear",1);
        skill = me->query_skill("wuyue-spear", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("wuyue-spear",1);
damage2= (int) ob->query("neili",1)/10;
if (random(6)==0 && level2>=290 && (me->query_skill_mapped("club") == "wuyue-spear"))
{
j = -damage/2; 
if (damage2> 5000)      damage2=5000;
msg = HIC"$N"+HIC+"使出寒冰真气 !$n全身一冷！无法动弹！ \n" +NOR;
ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
  ob->start_busy(3);
           message_vision(msg, me, ob);
  
}


           return j;
}      