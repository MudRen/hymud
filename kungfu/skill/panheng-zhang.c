// panheng-zhang.c �ͺ���
// Ffox 98-1-17 5:32

inherit SKILL;
mapping *action = ({
    ([   "action"  :"$N��������ͬʱһ�ܣ�ʹ��һ�С�˶����ʳ������$n�Ŀ���",
         "lian"    :"$N��������ͬʱһ�ܣ�ʹ��һ�С�˶����ʳ�������������ȥ��",
         "zhaoshi" : "��˶����ʳ��",
         "sen"   : 5,
         "parry" : 15,
         "dodge" : 15,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 225,
         "damage_type":  "����"
    ]),
    ([   "action"  :"$N��ȫ�������������ۣ�ʹ��һ�С����Ʋ��꡹����$nӭͷ���¡�",
         "lian"    :"$N��ȫ�������������ۣ�ʹ��һ�С����Ʋ��꡹���������¡�",
         "zhaoshi" : "�����Ʋ��꡹",
         "damage" : 240,
         "wound"  : 15, 
         "sen"    : 10,
         "parry"  : 30,
         "dodge"  : 30,
         "jibie"  : 20,   
         "damage_type":  "����"
    ]),
    ([   "action"  :"$N��ͷ����һ������ʹ��һ�С����м���������Ȼ�ų����ƣ����$nһ������",
         "lian"    :"$N��ͷ����һ������ʹ��һ�С����м���������Ȼ�ų����ƣ����ڿ����",
         "zhaoshi" : "�����м�����",
         "sen"   : 20,
         "jibie" : 40,
         "parry" : 45,
         "dodge" : 45,
         "damage": 255,
         "damage_type":  "����"
    ]),
    ([   "action": "$Nʹ��һ�С����м�ĭ���������������ƣ�ǣ��ȫ����$n�����˻���",
         "lian"  :"$Nʹ��һ�С����м�ĭ���������������ƣ�ǣ��ȫ����ǰ�����˻���",
         "zhaoshi" : "�����м�ĭ��",
         "damage": 270,
         "wound" : 15, 
         "sen"   : 25,
         "parry" : 60,
         "dodge" : 60,
         "jibie" : 60,
         "damage_type":  "����"
    ]),
    ([   "action": "$N����һ�����۰��ֲ���������ӣ�ʹ��һ�С������ڷɡ���һ��������$n��ȥ��",
         "lian"  : "$N����һ�����۰��ֲ���������ӣ�ʹ��һ�С������ڷɡ���һ�������������������",
         "zhaoshi" : "�������ڷɡ�",
         "sen"  : 30,
         "jibie": 80,
         "parry" : 75,
         "dodge" : 75,
         "damage": 285,
         "damage_type":  "����"
    ]),
    ([   "action":"$Nʹ��һ�С���ľ��������˫�ƴ��������ĳ������ƺ��У���$n�������ߡ�",
         "lian" :"$Nʹ��һ�С���ľ��������˫�ƴ��������ĳ������ƺ��У������л�ȥ��",
         "zhaoshi" : "����ľ������",
         "sen"   : 35,
         "jibie" : 100,
         "damage": 300,
         "wound" : 20, 
         "parry" : 90,
         "dodge" : 90,
         "damage_type":  "����"
    ]),   
    ([   "action":"$N˫����ǰƽ�ƣ�ʹ��һ�С��������򡹣��������ӿ�𣬽�$n��÷ɳ����ɿ��⡣",
         "lian" :"$N˫����ǰƽ�ƣ�ʹ��һ�С��������򡹣��������ӿ��",
         "zhaoshi" : "����������",
         "sen"   : 24,
         "jibie" : 120,
         "damage": 380,
         "wound" : 20, 
         "parry" : 70,
         "dodge" : 70,
         "damage_type":  "����"
    ]),   

});

string * parry_msg = ({
    "$nһ�С��������졹�����ƽ�$N�Ŀ���\n",
    "$n˫�����У�ʹ��һ�С�������������ӭͷ��ס$N����һ�С�"
    "$n˫�����������һ��ת�����ɶ����",
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
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}
int valid_combine(string combo) { return combo=="lingxiao-shou"; }

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
	return __DIR__"panheng-zhang/"+func;
}


