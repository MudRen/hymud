// lingxiao-nayun-shou.c
// created : nerd Mar/3/1997

inherit SKILL;

mapping *action = ({
    ([   "action"  :"$Nʹ��һ�С�������ʯ��������ֱ�������ƴ�������$n��$l",
         "lian"    :"$Nʹ��һ�С�������ʯ��������ֱ����������ǰ������",
         "zhaoshi" : "��������ʯ��",
         "sen"   : 6,
         "parry" : 20,
         "dodge" : 15,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 155,
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nһ�С�����ɽ���������ƻ���Ϊʵ����$n��$l",
         "lian"    :"$Nһ�С�����ɽ��������������ʵʵ������",
         "zhaoshi" : "������ɽ����",
         "damage" : 240,
         "wound"  : 15, 
         "sen"    : 8,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 5,   
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nǰ���޳����������һ�С�����ս������$n��$l",
         "lian"    :"$Nǰ���޳����������һ�С�����ս�󡹡�",
         "zhaoshi" : "������ս��",
         "sen"   : 10,
         "jibie" : 15,
         "parry" : 30,
         "dodge" : 20,
         "damage": 170,
         "damage_type":  "����"
    ]),
    ([   "action": "$N˫��һ��ʹ�����������ա������η��𣬶�׼$n��$l�����ĳ�",
         "lian"  :"$N˫��һ��ʹ�����������ա������η������ߡ�",
         "zhaoshi" : "���������ա�",
         "damage":  140,
         "wound" :  15, 
         "sen"  :  8,
         "parry" : 30,
         "dodge" : 20,
         "jibie":    20,
         "damage_type":  "����"
    ]),
    ([   "action": "$N������������Ƴ���һ�С���������������$n$l",
         "lian"  : "$N������������Ƴ���һ�С����������������ĳ���",
         "zhaoshi" : "������������",
         "sen"  : 6,
         "jibie": 30,
         "parry" : 10,
         "dodge" : 40,
         "damage": 160,
         "damage_type":  "����"
    ]),
    ([   "action":"$Nʹ�����������䡹��������������ͬʱ����$n��$l",
         "lian" :"$Nʹ�����������䡹��������������ͬʱ������",
         "zhaoshi" : "���������䡹",
         "sen"   : 8,
         "jibie" : 40,
         "damage": 150,
         "wound" : 20, 
         "parry" : 10,
         "dodge" : 25,
         "damage_type":  "����"
    ]),
    ([   "action": "$N����������һ�С�Χ�����ԡ���������ǰ������$n��$l",
         "lian" : "$N����������һ�С�Χ�����ԡ���һ��������ǰ�ĳ���",
         "zhaoshi" : "��Χ�����ԡ�",
         "sen"    : 8,
         "jibie"  : 50,
         "parry"  : 20,
         "dodge"  : 30,
         "wound"  :15, 
         "damage" : 270,
         "damage_type":  "����"
    ]),
});

string * parry_msg = ({
    "$nһ�С��������䡹��˫�Ʒ��裬$N��ǰһ����ʧȥ��$n����Ӱ��\n",
    "$n������ȭ��һ�С��������ޡ�������$N��һ����\n",
    "����$nһ�С��������󡹣�����һ����������$N�Ĺ��ơ�\n",
});
    

  
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������书������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="hand";
}
int valid_combine(string combo) { return combo=="panheng-zhang"; }

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
	return __DIR__"lingxiao-shou/"+func;
}


