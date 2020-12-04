// bibo-sword.c from mool
inherit SKILL;

mapping *action = ({
([      "action" : "$N����������һ�С�Ӣ�������Ҷ��С���ƮȻ����$n��ǰ���漴����$w΢�𣬽��⼲����$n��$l",
        "force" : 50,
        "dodge" : 20,
        "damage" : 130,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nб��һ����ʹ��һʽ����Ů�鳤ֻ�޶̡����ӽ��������һ��һ�̵Ĺ�Ӱֱ��$n��$l",
        "force" : 75,
        "dodge" : 15,
        "damage" : 135,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���Ȼ��ȥ��˼�项��$w��Ȼ���������̻ص������У��漴ת����Ȼ��ȥ��\n$n��ʱ�Ÿо�����һ�ɾ��������Լ���$l",
        "force" : 50,
        "dodge" : 25,
        "damage" : 240,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N˫�־ٽ����죬һ�С�����Ⱥ�������塹��$w���������ף����϶�����$n��ȥ",
        "force" : 50,
        "dodge" : 10,
        "damage" : 245,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ�������һЦ������������$w���΢΢һЦ��$nֻ����һ����ȴ��һ����Ӱ\n�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ�����֣���",
        "force" : 50,
        "dodge" : 20,
        "damage" : 350,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���̤ʵ���ҽ���㣬һ�С�һ����ϳ�᡹��$w����һ�Ž�����Ʈ�������ر���$n��$l",
        "force" : 70,
        "dodge" : 5,
        "damage" : 355,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ū������项�������ḧ$w���漴�͵�һ����������ǰһ�ݣ�\nֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
        "force" : 90,
        "dodge" : 5,
        "damage" : 360,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N������ף���ɫ��Ȼ��һ�С�������Թ���˳�����$w�������Ʋ����ش���$n��$l",
        "force" : 80,
        "dodge" : 15,
        "damage" : 370,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������棬һ�С��˽�������������������$wб���»�����$n΢����֣������ɼ䣬\nȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
        "force" : 70,
        "dodge" : 5,
        "damage" : 380,
        "lvl" : 80,
        "damage_type" : "����"
]),
([  "action" : "$N��Ȼ��¶΢Ц��һ�С���������Ц���ա�������$wһ����������Ž�������$n����������·",
        "force" : 80,
        "dodge" : 25,
        "damage" : 390,
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ����$w��һ�С��������������项��$w����һ���������������ƣ�\n$nֻ���õ���ǰһ�ƣ�һ����͵ľ��������Լ�",
        "force" : 90,
        "dodge" : 25,
        "damage" : 390,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����΢��һ�С�������������ϡ�������$w����������һ����������ĺ�����ɲ�Ǽ��ɳ��ʯ��\n$n����һ�Ž���������£�������֧����",
        "force" : 90,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 110,
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if( me->query("max_neili") < 100 )
		return notify_fail("��������������޷�������\n");

	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("��ľ�������Ϊ�������޷�������\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("�����������Ϊ�������޷�������\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("����ͺ�����Ϊ�������޷�������\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("������ɲ�����Ϊ�������޷�������\n");

	if(me->query_skill("longjiao-blade", 1) < 250)
		return notify_fail("��ĸ���ն�޵���Ϊ�������޷�������\n");


	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,n;

	level   = (int) me->query_skill("bibo-sword",1);

	n = sizeof(action);
	for(i=0;i<n;i++)
		if(level >= action[i]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("��ľ�������Ϊ�������޷�������\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("�����������Ϊ�������޷�������\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("����ͺ�����Ϊ�������޷�������\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("������ɲ�����Ϊ�������޷�������\n");

	if(me->query_skill("longjiao-blade", 1) < 250)
		return notify_fail("��ĸ���ն�޵���Ϊ�������޷�������\n");

	if((int)me->query("qi") < 50)
		return notify_fail("��������������̲�������\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"bibo-sword/"+func;
}

string *parry_msg = ({
        "$n����$v����$N��$w��������$N��$w��\n",
       "$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});
string *unarmed_parry_msg = ({
	"$n�����е�$v����Ƿ��겻͸����ס��$N�Ĺ��ơ�\n",
});

int effective_level() { return 11;}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
