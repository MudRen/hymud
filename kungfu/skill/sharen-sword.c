// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"a",
		"action":		"$N手中的$w在一弹指间已向$n的$l连刺数剑",
		"dodge":		50,
		"parry" :		100,
		"force":		170,
		"damage" :		250,
		"damage_type":	"刺伤"
	]),
	([	"name":			"b",
		"action":		"$N身形一转，手中的$w从左肋下向$n的$l戳了过去",
		"dodge":		50,
		"damage":		270,
		"damage_type":	"刺伤"
	]),
	([	"name":			"c",
		"action":		"$N手腕一抖，$w挟著闪闪剑光逼向$n的$l",
		"dodge":		40,
		"damage" :		250,
		"force" :		120,
		"damage_type":	"刺伤"
	]),
	([	"name":			"d",
		"action":		"$N身形一矮，手中的$w由下往上刺向$n的$l",
		"dodge":		40,
		"damage":		280,
		"damage_type":	"刺伤"
	]),
	([	"name":			"e",
		"action":		"$N手中$w剑光暴长，如千年蛇蝎往$n$l咬去",
		"dodge":		60,
		"damage":		220,
		"damage_type":	"刺伤"
	]),
	([	"name":			"f",
		"action":		"$N手中的$w以无法形容的速度直射$n的$l",
		"dodge":		20,
		"force" :		100,
		"damage":		350,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力不够，没有办法练杀人剑法。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习杀人剑法。\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("你按著所学练了一遍杀人剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("sharen-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
		me->add("shen", -10);
	} else
		me->add("shen", -5);
}
int effective_level() { return 15;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -30;
}
int black_white_ness()
{
	return -20;
}
string perform_action_file(string action)
{
        return __DIR__"sharen-sword/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return "只听一声惨嚎，一股鲜血从$n的伤口喷出！\n" ;	
}
}