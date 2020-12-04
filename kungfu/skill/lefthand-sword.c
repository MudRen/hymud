// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"one",
		"action":		"$N��ǰһ��������$w���߰����$n��$l",
		"dodge":		50,
		"damage":		270,
		"damage_type":	"����"
	]),
	([	"name":			"two",
		"action":		"$N����һת������һ�ӣ�����$w����$n��$l",
		"dodge":		50,
		"damage":		220,
		"damage_type":	"����"
	]),
	([	"name":			"three",
		"action":		"$n��ǰһ����$N���е�$w�Ѿ�Ѹ���ޱȵĴ���$n��$l",
		"dodge":		40,
		"force" :		100,
		"damage_type":	"����"
	]),
	([	"name":			"four",
		"action":		"$Nֻ�����أ�����$wһ������$n��$l�̳�һ��",
		"dodge":		40,
		"damage":		240,
		"damage_type":	"����"
	]),
	([	"name":			"five",
		"action":		"$N�ġ����ֽ�����ֻ��[31m��[37m���򵥶���Ч����$n��$l��ȥ",
		"dodge":		60,
		"damage":		280,
		"force" :		100,
		"damage_type":	"����"
	]),
	([	"name":			"six",
		"action":		"$N����$wֱָ$n$l���������˽���������ȥ",
		"dodge":		20,
		"damage":		220,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;


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
		return notify_fail("�����������������û�а취��ϰ���ֽ���\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ�����ֽ�����\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n\n" NOR);
		me->add("bellicosity", 10);
	} else
		me->add("bellicosity", 1);
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -20;
}

string perform_action_file(string action)
{
        return __DIR__"lefthand-sword/" + action;
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