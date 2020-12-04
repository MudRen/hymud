// longjiao-blade.c from mool

inherit SKILL;

mapping *action = ({
([  "action" : "$N��ǰ����һ����һ�С���𡹣�����$w����������$n��$l������ȥ",
        "damage":260,
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֵ���������һ����$w�����������٣�һʽ��������ӳ��ֱ��$n��$l",
        "damage":280,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�ѩӿ���ء���$w�����������⣬���¶��Ϸ���$n��$l",
        "damage":300,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С���С�������$w���ƺ�ɨʵ��б��������$n��$l",
        "damage":320,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����˼���$w����������������಻�ϻ���$n��$l",
        "damage":340,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С��ƺ����项������һ�󵶾�������$w���϶������������ֱ��$n��$l������ȥ",
        "damage":310,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С��������ࡹ�����ڰ�գ�$w�س飬���ֹ���$n��$l",
        "damage":380,
    "damage_type" : "����"
]),
([  "action" : "$N��Ӱһ��, �Ƶ�$n����һ�С��������ޡ���������$n��$l����",
        "damage":300,
    "damage_type" : "����"
]),
([      "action" : "$N����$wбָ��һ�С�����һ�ơ�������һ�٣�һ����$n��$l��ȥ",
        "damage":350,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ն������������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "damage":360,
        "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С��������ˡ������滯������ն��$n",
        "damage":370,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����»�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "damage":380,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С���ˮ��ħ����˫�ֳ����������У�����$n���ؿ�",
        "damage":390,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С���ٲ��������������ã����ҿ�����������$n",
        "damage":500,
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jinghai-force", 1) < 10)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
 	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("��ľ�������Ϊ�������޷�������\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("�����������Ϊ�������޷�������\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("����ͺ�����Ϊ�������޷�������\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("������ɲ�����Ϊ�������޷�������\n");
		
if (me->query_skill("longjiao-blade", 1) > 251)
{
			if(me->query_skill("bibo-sword", 1) < me->query_skill("longjiao-blade", 1))
		return notify_fail("��ı̲�����Ϊ�������޷�������\n");
}		
        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������������޷���ϰ����ն�޵�����\n");
	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("��ľ�������Ϊ�������޷�������\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("�����������Ϊ�������޷�������\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("����ͺ�����Ϊ�������޷�������\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("������ɲ�����Ϊ�������޷�������\n");

if (me->query_skill("longjiao-blade", 1) > 251)
{
			if(me->query_skill("bibo-sword", 1) < me->query_skill("longjiao-blade", 1))
		return notify_fail("��ı̲�����Ϊ�������޷�������\n");
}		
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"longjiao-blade/"+func;
}

int effective_level() { return 11;}

string *parry_msg = ({
        "$n����$v����$N��$w��������$N��$w��\n",
       "$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});
string *unarmed_parry_msg = ({
	"$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
