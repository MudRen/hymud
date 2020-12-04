
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"���겻ɢ",
		"action":		"$Nʹһ�С����겻ɢ��������$w���Ⱪ������$n��$l��ȥ",
		"dodge":		50,
		"force":		170,
			"damage":                100,
		"damage_type":	"����"
	]),
	([	"name":			"����ɭɭ",
		"action":		"$N������ת��һ�С�����ɭɭ������$n��$l",
		"dodge":		70,
		"force":		200,
			"damage":                100,
		"damage_type":	"����"
	]),
	([	"name":			"���Ƶ���",
		"action":		"$N�趯$w��һ�С����Ƶ���Ю�������������$n��$l",
		"dodge":		40,
		"damage":		390,
			"damage":                100,
		"damage_type":	"����"
	]),
	([	"name":			"���ܵظ�",
		"action":		"$N����$w����һ�������������ܵظ�����$n��$l�̳�����",
		"dodge":		40,
		"damage":		340,
		"damage_type":	"����"
	]),
	([	"name":			"��������",
		"action":		"$N����$w���Ⱪ����һ�С��������ǡ���$n$l��ȥ",
		"dodge":		60,
		"damage":		320,
		"damage_type":	"����"
	]),
	([	"name":			"��������",
		"action":		"$N����$w����һ���⻡��ֱָ$n$l��һ�С��������¡���������������ȥ",
		"dodge":		60,
		"damage":		350,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	object ob;
       if( (string)me->query("gender") != "Ů��" )
                return notify_fail("��������������ֻ��Ů�Ӳ��������书��\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����������������\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 30) / 2,me );
                switch(random(3)) {
                        case 0: return "��������������һ�����죬�����ǹ����������\n";
                        case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
                        case 2: return "ֻ����$n��$l��������һ�� ...\n";
                }
        }
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 80
	||	(int)me->query("neili") < 50 )
		return notify_fail("�����������������û�а취��ϰ������������\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
	//write("�㰴����ѧ����һ���������������\n");
	return 1;
}

void skill_improved(object me)
{
	if ( (string)me->query("gender")=="Ů��" )
{
    if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
        tell_object(me,
           RED "\n��ͻȻ����һ������������ͷ��ֻ������ɱ��....\n\n"NOR);
        me->add("shen", -2000);
    } else
    me->add("shen", -200);
}
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
           return __DIR__"ninemoonsword/" + action;
}

int effective_level() { return 8;}

string *parry_msg = ({
        "$nʹ�������������С������𡹣���$N���е�$w��ƫ�˳�ȥ��\n",
	"$n̤��λ�������ţ����е�$v����һ�ã���ס��$N���е�$w��\n",
	"$n��$N����һ�������е�$v˳��$N��$w���£�����$N��$w����ָ��\n",
	"$n���е�$vһ����һ�С��Ŷ��������$v�ó�������Ӱ����ס��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n��͸���⣬һ�С�����̹ǡ���ǿ���Ľ���ֱȡ$N���ʺ�\n",
	"$n����һ����$v��һ��������ֱ��$N������\n",
	"$n�ҽź�̤һ����$v�����֣�������$N�鰴��һ�ɾ���ʹ$Ņ�����֡�\n",
	"$nת��$vͻȻ��Ҹ�´̳���һ�С�ɳ�س�Ы��������$N������$N��æ�����Ա���\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 30;
}

