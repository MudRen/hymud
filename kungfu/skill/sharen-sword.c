// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"a",
		"action":		"$N���е�$w��һ��ָ������$n��$l��������",
		"dodge":		50,
		"parry" :		100,
		"force":		170,
		"damage" :		250,
		"damage_type":	"����"
	]),
	([	"name":			"b",
		"action":		"$N����һת�����е�$w����������$n��$l���˹�ȥ",
		"dodge":		50,
		"damage":		270,
		"damage_type":	"����"
	]),
	([	"name":			"c",
		"action":		"$N����һ����$wЮ�������������$n��$l",
		"dodge":		40,
		"damage" :		250,
		"force" :		120,
		"damage_type":	"����"
	]),
	([	"name":			"d",
		"action":		"$N����һ�������е�$w�������ϴ���$n��$l",
		"dodge":		40,
		"damage":		280,
		"damage_type":	"����"
	]),
	([	"name":			"e",
		"action":		"$N����$w���Ⱪ������ǧ����Ы��$n$lҧȥ",
		"dodge":		60,
		"damage":		220,
		"damage_type":	"����"
	]),
	([	"name":			"f",
		"action":		"$N���е�$w���޷����ݵ��ٶ�ֱ��$n��$l",
		"dodge":		20,
		"force" :		100,
		"damage":		350,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("�������������û�а취��ɱ�˽�����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

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
		return notify_fail("�����������������û�а취��ϰɱ�˽�����\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ��ɱ�˽�����\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("sharen-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
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
        return "ֻ��һ���Һ���һ����Ѫ��$n���˿������\n" ;	
}
}