// dahong.c
// ���ȭ

inherit SKILL;

mapping *action = ({
([      "action"    :"$N˫��һ��ʹ����ʮָ���������׼$n��$l�����ĳ�����",
    "lian"      :"$N˫��һ��ʹ����ʮָ�������������ְ����ִ������",
    "jibie"     :16,      
    "zhaoshi":"��ʮָ�����",
    "sen"       :3,
        "dodge"     :30,
        "parry"     :0,
        "damage"     :145,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ��һ�С��ؽ���ӡ�����Ų����ǲ���һȭ��$n$l��ȥ",
    "lian"      :"$N����ʹ��һ�С��ؽ���ӡ������ϸ��Ħÿһ���仯",
    "jibie"     :48,
    "zhaoshi":"���ؽ���ӡ��",
    "sen"       :3,
        "dodge"     :10,
        "parry"     :20,
        "damage"     :245,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ��һ�С����������������鰴����ȭ�»���ֱ��$n��$l��ȥ",
    "lian"      :"$N�����鰴����ȭ�»�����ᡸ���������ĸо�..",
    "jibie"     :56,  
    "zhaoshi":"����������",
    "sen"       :2,
        "dodge"     :30,
        "parry"     :10,
        "damage"     :150,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ�����ƴ����¡����󲽿�ǰ������ȭ������ȭ��$n��$l��ȥ",
    "lian"      :"$N�󲽿�ǰ������ȭ������ȭ��Ѱ�ҡ��ƴ����¡��ĸо�",
    "jibie"     :64, 
    "zhaoshi":"���ƴ����¡�",
    "sen"       :2,
        "dodge"     :20,
        "parry"     :20,
    "wound"     :10,
        "damage"     :150,
        "damage_type":  "����"
]),
    ([   "action"  :"$Nʹ��һ�С��ڷ������������ֱ�������ƴ�������$n��$l",
         "lian"    :"$Nʹ��һ�С��ڷ������������ֱ����������ǰ������",
         "zhaoshi" : "���ڷ������",
         "sen"   : 6,
         "parry" : 20,
         "dodge" : 15,
         "jibie" : 5,
         "damage": 245,
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nһ�С��ڷ�ɨ�ء������ƻ���Ϊʵ����$n��$l",
         "lian"    :"$Nһ�С��ڷ�ɨ�ء�����������ʵʵ������",
         "zhaoshi" : "���ڷ�ɨ�ء�",
         "damage" : 140,
         "sen"    : 8,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 5,   
         "damage_type":  "����"
    ]),
    ([   "action": "$N˫��һ��ʹ����ӥצ׽ʳ�������η��𣬶�׼$n��$l�����ĳ�",
         "lian"  :"$N˫��һ��ʹ����ӥצ׽ʳ�������η������ߡ�",
         "zhaoshi" : "��ӥצ׽ʳ��",
         "damage":  220,
         "sen"  :  8,
         "parry" : 30,
         "dodge" : 30,
         "jibie":    20,
         "damage_type":  "����"
    ]),
    ([   "action": "$N������������Ƴ���һ�С����ֶ㲽������$n$l",
         "lian"  : "$N������������Ƴ���һ�С����ֶ㲽�������ĳ���",
         "zhaoshi" : "�����ֶ㲽��",
         "sen"  : 6,
         "jibie": 30,
         "parry" : 50,
         "dodge" : 40,
         "wound" : 15, 
         "damage": 245,
         "damage_type":  "����"
    ]),
([      "action"    :"$N��������������һȭ������һ������ȭ�еġ�������ˮ��",
    "lian"      :"$N��������������һ�С�������ˮ����ȴ�ܾ�����Щ����Ҫ��",
    "jibie"     :8,
    "zhaoshi":"��������ˮ��",
    "sen"       :1,
        "dodge"     :10,
    "parry"     :10,
    "damage"     :260,
        "damage_type":  "����"
]),
([      "action"    :"$N˫��һ��ʹ�����������项����׼$n��$l�����ĳ�����",
    "lian"      :"$N˫��һ��ʹ�����������项�������ĳ����ƣ�������ְ����ִ������",
    "jibie"     :16,      
    "zhaoshi":"���������项",
    "sen"       :2,
        "dodge"     :20,
        "parry"     :5,
        "damage"     :265,
        "damage_type":  "����"
]),
([      "action"    :"$N����������һ�С�������ˮ����˫�ֱ�$n��ͷ����ȥ",
    "lian"      :"$Nһ�С�������ˮ����˫��������еĵ��˵�ͷ����ȥ",
    "jibie"     :24,
    "zhaoshi":"��������ˮ��",
    "limb":"ͷ��",
    "sen"       :2,
        "dodge"     :10,
        "parry"     :10,
    "wound"     :10,
        "damage"     :250,
        "damage_type":  "����"
]),
([      "action"    :"$Nһ�С��������ơ�,������$n$l��ȥ...",
    "lian"      :"$Nһ�С��������ơ���������ǰ��ȥ...",
    "jibie"     :32,    
    "zhaoshi":"���������ơ�",
    "sen"       :2,
        "dodge"     :20,
        "parry"     :10,
    "wound"     :5,
        "damage"     :265,
        "damage_type":  "����"
]),
([      "action"    :"$N����һ���������Ƴ���һ�С���������������$n$l",
    "lian"      :"$N���������Ƴ�������һ����������Ƶı仯�����˸�������������..",
    "jibie"     :90,
    "zhaoshi":"������������",
    "sen"       :2,
        "dodge"     :20,
        "parry"     :20,
        "damage"     :270,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ��һ�С�������β�����Ų����ǲ���һȭ��$n$l��ȥ",
    "lian"      :"$N����ʹ��һ�С�������β������ϸ��Ħÿһ���仯",
    "jibie"     :48,
    "zhaoshi":"��������β��",
    "sen"       :5,
        "dodge"     :20,
        "parry"     :20,
    "wound"     :15,
        "damage"     :255,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ��һ�С������붴���������鰴����ȭ�»���ֱ��$n��$l��ȥ",
    "lian"      :"$N�����鰴����ȭ�»�����ᡸ�����붴��������",
    "jibie"     :56,  
    "zhaoshi":"�������붴��",
    "sen"       :5,
        "dodge"     :20,
        "parry"     :20,
    "wound"     :10,
        "damage"     :270,
        "damage_type":  "����"
]),

});

string * parry_msg = ({
    "$nһ�С�˫���ġ���˫�Ʒ��裬$N��ǰһ����ʧȥ��$n����Ӱ��\n",
    "$n������ȭ��һ�С������ġ�������$N��һ����\n",
    "����$nһ�С�Ϭţ�׽ǡ�������һ����������$N�Ĺ��ơ�\n",
});
    

  
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}
int valid_learn(object me)
{
    return 1;
}
int valid_combine(string combo) { return combo=="shizi-zhan"; }

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
	return __DIR__"dahong-quan/"+func;
}


