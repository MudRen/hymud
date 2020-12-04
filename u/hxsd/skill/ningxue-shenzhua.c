// ningxue-shenzhua.c ��Ѫ��ץ

inherit SKILL;

mapping *action = ({
([      "action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ��������̽צ��ץ��$n��$l",
        "dodge": 10,
        "parry": 100,
        "force": 100,
        "damage": 100,
        "lvl" : 0,
        "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�־Ӹ�����һ�С���ӥ���á�ץ��$n��$l",
        "dodge": 15,
        "parry": 180,
        "force": 150,
        "damage": 200,
        "lvl" : 20,
        "damage_type": "����"
]),
([      "action": "$N����һ�С��ڻ����ġ���Ѹ���ޱȵ�ץ��$n��$l",
        "dodge": 10,
        "parry": 200,
        "force": 200,
        "damage": 300,
        "lvl" : 40,
        "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ�С�̩ɽѹ�������������ŷ���ץ��$n��$l",
        "dodge": 10,
        "parry": 300,
        "force": 300,
        "damage": 400,
        "lvl" : 100,
        "damage_type": "����"
]),
([      "action": "$N���־۳ɻ�צ״������һ�С���Ѫ��ץ������ץ��$n��$l",
        "dodge": 10,
        "parry": 50,
        "force": 400,
        "damage": 500,
        "lvl" : 200,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry" ||  usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ѫ��ץ������֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ѫ��ץ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ningxue-shenzhua/" + action;
}

string *parry_msg = ({
        "ֻ�������ϡ�һ������$p���ˡ�\n",
        "�����������һ����$p�����ˡ�\n",
        "���Ǳ�$n������$v�ܿ���\n",
        "����$n����һ�࣬������$v�񿪡�\n",
});

string *unarmed_parry_msg = ({
        "���Ǳ�$p���ˡ�\n",
        "�����$p�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
