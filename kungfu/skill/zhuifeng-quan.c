// ׷��ȭ  zhuifeng-quan.c
//   ChangeLog by lin on March 24, 1997

inherit SKILL;

mapping *action = ({
    ([   "action"  :"$NĿ�Ӷ��֣�ʹ��һ�С���������񡹣����ֻ��أ�������ȭ��$nһ��������",
         "lian"    :"$NĿ��ǰ����ʹ��һ�С���������񡹣����ֻ��أ�������ȭ�������һ��������",
         "zhaoshi" : "�����������",
         "sen"   : 4,
         "parry" : 10,
         "dodge" : 10,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 220,
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nʹ��һ�С�������������˫�ֳɻ��Σ���$n��ͷ���¡�",
         "lian"    :"$Nʹ��һ�С�������������˫�ֳɻ��Σ��Ϳ����е�ͷ���¡�",
         "zhaoshi" : "������������",
         "damage" : 330,
         "wound"  : 15, 
         "sen"    : 8,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 20,   
         "damage_type":  "����"
    ]),
    ([   "action"  :"$N����һ�ݣ�һ�С���������𡹣����嵹ת��˫ȭ��$n�Ժ������",
         "lian"    :"$N����һ�ݣ�һ�С���������𡹣����嵹ת��˫ȭ���»�����",
         "zhaoshi" : "�����������",
         "sen"   : 12,
         "jibie" : 40,
         "parry" : 30,
         "dodge" : 30,
         "damage": 240,
         "damage_type":  "����"
    ]),
    ([   "action": "$N����һ�٣�ʹ��һ�С������ܳ�������˫�־���$n�����������˹�ȥ��",
         "lian"  :"$N����һ�٣�ʹ��һ�С������ܳ�������˫�־�����������ȥ��",
         "zhaoshi" : "�������ܳ�����",
         "damage": 250,
         "wound" : 15, 
         "sen"   : 16,
         "parry" : 40,
         "dodge" : 40,
         "jibie" : 60,
         "damage_type":  "����"
    ]),
    ([   "action": "$N��ȭǰ��ֿ���ʹ��һ�С���ɽ��Ⱥ������ȭֱ��$n�粿��ȥ��",
         "lian"  : "$N��ȭǰ��ֿ���ʹ��һ�С���ɽ��Ⱥ������ȭֱ���������ȥ��",
         "zhaoshi" : "����ɽ��Ⱥ��",
         "sen"  : 20,
         "jibie": 80,
         "parry" : 50,
         "dodge" : 50,
         "damage": 260,
         "damage_type":  "����"
    ]),
    ([   "action":"$Nʹ��һ�С��¿�ָ���񡹣�������ָ�����ֳ���ץס$n�����󣬽�$n���˸�����",
         "lian" :"$Nʹ��һ�С��¿�ָ���񡹣�������ָ�����ֳ�����ǰץ����",
         "zhaoshi" : "���¿�ָ����",
         "sen"   : 24,
         "jibie" : 100,
         "damage": 270,
         "wound" : 20, 
         "parry" : 60,
         "dodge" : 60,
         "damage_type":  "����"
    ]),   
    ([   "action":"$Nһ����Ծ������ʹ��һ�С���������衹����ȭ�����ͻ�$n��ͷ����",
         "lian" :"$Nһ����Ծ������ʹ��һ�С���������衹����ȭ�����ͻ�������",
         "zhaoshi" : "����������衹",
         "sen"   : 24,
         "jibie" : 120,
         "damage": 280,
         "wound" : 20, 
         "parry" : 70,
         "dodge" : 70,
         "damage_type":  "����"
    ]),   
        ([      "zhaoshi": "���������ɽ��",
                "action":               
"$Nʹ��һ�С��������ɽ������ȭ����$n̫�����ҽſ���һ����",
                "lian" :
"$Nʹ��һ�С��������ɽ������ȭ�������ҽſ���һ����",
                "jibie":          6,
                "limb":"̫��Ѩ",
                "sen"  :      5,
                "dodge":                10,
                "parry":                20,
                "damage":                230,
                "damage_type":  "����"
        ]),
        ([      "zhaoshi" : "��׷��ǧ�",
                "action":               
"$Nһ�С�׷��ǧ�����̤��������˫ȭ�ɻ�$nͷ�����ࡣ",
                "lian" :
"$Nһ�С�׷��ǧ�����̤��������˫ȭ�ɻ�����",
                "jibie":15,
                "limb":"ͷ��",
                "sen"  :5,
                "dodge":                10,
                "parry":                10,
                "damage":                240,
                "damage_type":  "����"
        ]),
        ([      "zhaoshi" :" ��̤ѩѰ÷��",
                "action":               
"$N��ȭ���䣬һ�С�̤ѩѰ÷�����ε�$n��󣬡������ػӳ�һȭ.",
                "lian" :
"$N��ȭ���䣬һ�С�̤ѩѰ÷�����ɲ����ϣ��������ػӳ�һȭ.",
                "jibie":22,
                "limb":"����",
                "sen"  : 6,
                "dodge":                20,
                "parry":                10,
                "damage":                250,
                "damage_type":  "����"
        ]),
        ([      "zhaoshi" : "����������",
                "action":               
"$N����ಽ���ù�$n����ȭ����$n������",
                "lian" :
"$N����ಽ����ȭ����������",
                "jibie":30,
                "limb":"����",
                "sen"  : 6,
                "dodge":                30,
                "parry":                10,
                "wound" :               10, 
                "damage":                340,
                "damage_type":  "����"
        ]),
        ([      "zhaoshi" : "�������ȡ�",
                "action":               
"$N��������������$n����.",
                "lian" :
"$N���������������߳���",
                "jibie":40,
                "sen"  : 7,
                "limb":"��ǰ",
                "dodge":                30,
                "parry":         10,
                "damage":                260,
                "damage_type":  "����"
        ]),
        ([      "zhaoshi" : "���ҷ��ȡ�",
                "action":               
"$N˫ȭ���ӣ�ȭ�м��ȣ��Ƶ�$n�������ˡ�",
                "lian" :
"$N˫ȭ���ӣ�ȭ�м��ȣ������ۻ����ҡ�",
                "jibie":50,
                "sen"  :5,
                "parry":                35,
                "wound" :               20, 
                "damage":                340,
                "damage_type":  "����"
        ]),
});

string *parry_msg = ({
    "$nһ�С����ǻᱱ������˫�����գ���ס��$N.\n",
    "$n����ת���㿪��$N�Ĺ�����\n",
});

string *unarmed_parry_msg = ({
    "$ņ���ϸ���ȭ�ӳ���������$N�Ĺ���.\n",
});




string query_parry_msg(object weapon)
{   
    if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_learn(object me)
{

       if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("��ġ������ķ������̫ǳ��\n");

        if ((int)me->query_skill("baihua-zhang", 1) < 120)
                return notify_fail("��ġ��ٻ��ơ����̫ǳ��\n");

        if ((int)me->query_skill("feixian-jian", 1) < 220)
                return notify_fail("��ġ����ɽ��������̫ǳ��\n");

        if ((int)me->query_skill("qiongya-bufa", 1) < 220)
                return notify_fail("��ġ������������̫ǳ��\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry"  || usage=="cuff";
}

int valid_combine(string combo) { return combo=="baihua-zhang"; }

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
	return __DIR__"zhuifeng-quan/"+func;
}