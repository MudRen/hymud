//���ٻ��ơ�baihua-zhang.c
// cglaem...12/08/96.
//menpai skill

inherit SKILL;

mapping *action = ({
	([	"action":		"$NǳǳһЦ��һ�С����ڷɻ������Ρ��������޵�����$n��$l",
		"damage":350,
		"damage_type":	"����",
	]),
	([	"action":		"$N����һ�٣��������⡣$n����������\n����$N������ָ��ֱ��$n˫Ŀ�����ǡ��ٻ��ơ�֮ɱ�֡�һ֦���ӳ�ǽ����",
		"damage":390,
		"damage_type":	"����",
                        "weapon":		"������",
	]),
	([	"action":		"ֻ��$N��ȻһЦ��˫�Ʒ��ɣ�һ�С������һ���ӳ�졹�����������",
		"damage":230,
		"damage_type":	"����",
	]),
	([	"action":		"$N����һ�ڣ���Ȼ�������ߣ�����˳��һ�С��ƾ�֦ͷ����������$n��$l��ȥ",
		"damage":360,
		"damage_type":	"����",
	]),
            ([	"action":		"ֻ��$N˫�����գ���ɫ���أ�һ�С��˻��������޻���ȫ������$n��$l",
		"damage":300,
		"damage_type":	"����",
	]),
});

int valid_learn(object me)
{

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("���ٻ��Ʊ�����֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}
int valid_combine(string combo) { return combo=="zhuifeng-quan"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"baihua-zhang/"+func;
}
