//
#include <ansi.h>
inherit SKILL;

#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";

string* skill_head =({
        "$N身形稍退，使出一招 「宫韵」",
        "$N不闪不避，一式 [商韵]",
        "$N身形一幌，使出 [角韵]",
        "$N妍然一笑，一式 「支韵」",
        "$N飞身跃起，使出 [羽韵]",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w舞出满天鞭影罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，$w从右肩急甩向后，陡地击向$n$l。",
});

mapping *action = ({
   ([   "action":
"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开，一招"+BLINK""+HIM"「宫韵」"NOR"已悄然划向$n的后心",
     "dodge":     5,
                "parry":                10,
     "damage":     340,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"飞身跃起，$n抬眼一望，但见得$N手中$w舞出满天鞭影，"+BLINK""+HIC"[商韵]"NOR"已将$n笼罩",
     "dodge":     15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中$w轻轻一抖，手中$w如鬼魅一般,一式"+BLINK""+HIG"[角韵]"NOR"无形的刺向$n的左肋",
     "dodge":     10,
                "parry":                15,
     "damage":     335,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w犹似一条柔丝，竟如没半分重量，身子忽东忽西，忽进忽退，在$n身周飘荡不定，正是一招"+BLINK""+HIW"[羽韵]"NOR"",
     "dodge":     10,
                "parry":                5,
     "damage":     350,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"突然之间，$N身形一闪一晃，疾退数丈，使出一招"+BLINK""+HIB"「支韵」"NOR"，$w从右肩急甩向后，陡地击向$n$l，正如天外游龙，矢矫而至",
     "dodge":     20,
                "parry":                30,
     "damage":     345,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

	if ((int)me->query("max_neili") < 800)
		return notify_fail(HIC"你的内力不够。\n"NOR);

	if ((int)me->query_skill("chuanyun-shou", 1) < 250)
		return notify_fail(HIC"你的穿云不够。\n"NOR);

	if ((int)me->query_skill("tianchang-zhang", 1) < 250)
		return notify_fail(HIC"你的天长掌不够。\n"NOR);
	if ((int)me->query_skill("lingxu-bu", 1) < 250)
		return notify_fail(HIC"你的凌虚步不够。\n"NOR);
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"你的白云心法不够。\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"你的恒山剑法不够。\n"NOR);	
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("柔丝乐鞭必须配合白云心法才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("你必须先找一把鞭子才能练鞭法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够练柔丝乐鞭。\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"你的白云心法不够。\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"你的恒山剑法不够。\n"NOR);	
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("柔丝乐鞭必须配合白云心法才能练。\n");		
		
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("rousi-whip",1);
         lvl = (int)me->query_skill("rousi-whip", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string func)
{
return __DIR__"rousi-whip/" + func;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baiyun-xinfa", 1);

        
            if ( random(8) == 0 || random(level) > 180){
         if (random(3)==0  && !ob->is_busy()) ob->start_busy(2);
         msg = HIG"$N运起白云心法，吐出一口淤血!!。\n"NOR;
         msg += GRN"$N的伤好多了!!。\n"NOR;
if ((int)me->query("qi")<=(int)me->query("max_qi")*2)
{
             me->add("qi",(level+100));
             me->add("eff_qi",(level+100));
}
msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("rousi-whip",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("whip",1);
        level2= (int) me->query_skill("huiyan-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("rousi-whip",1))+50;

if (damage > 1600) damage=1600;

if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "baiyun-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("rousi-whip",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

