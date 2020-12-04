// shizi-zhan.c
// ʮ��ս

inherit SKILL;

mapping *action = ({
([      "action"    :"$N��������������һȭ������һ�С���Ԫ�֡�..",
    "lian"      :"$N��������������һȭ����Ԫ�֡���ȴ�ܾ�����Щ����Ҫ��",
    "jibie"     :8,
    "zhaoshi":"����Ԫ�֡�",
    "sen"       :3,
        "dodge"     :5,
    "parry"     :0,
    "damage"     :110,
        "damage_type":  "����"
]),
([      "action"    :"$N˫��һ��ʹ������ʽ�����ڡ�����׼$n��$l�����ĳ�����",
    "lian"      :"$N˫��һ��ʹ������ʽ�����ڡ��������ĳ����ƣ�������ְ����ִ������",
    "jibie"     :16,      
    "zhaoshi":"����ʽ�����ڡ�",
    "sen"       :1,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :115,
        "damage_type":  "����"
]),
([      "action"    :"$N����������һ�С�ʨ�Ӵ��ſڡ�˫�ֱ�$n��ͷ����ȥ",
    "lian"      :"$Nһ�С�ʨ�Ӵ��ſڡ���˫��������еĵ��˵�ͷ����ȥ",
    "jibie"     :24,
    "zhaoshi":"��ʨ�Ӵ��ſڡ�",
    "limb":"ͷ��",
    "sen"       :1,
        "dodge"     :0,
        "parry"     :10,
        "damage"     :120,
        "damage_type":  "����"
]),
([      "action"    :"$Nһ�С���ȭ���ȡ�,������$n$l��ȥ...",
    "lian"      :"$Nһ�С���ȭ���ȡ���������ǰ��ȥ...",
    "jibie"     :32,    
    "zhaoshi":"����ȭ���ȡ�",
    "sen"       :2,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :110,
        "damage_type":  "����"
]),
([      "action"    :"$N����һ���������Ƴ���һ��������������$n$l",
    "lian"      :"$N���������Ƴ�������һ����������Ƶı仯",
    "jibie"     :40,
    "zhaoshi":"��������",
    "sen"       :2,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :125,
        "damage_type":  "����"
]),
([      "action"    :"$Nʹ��һ�С����ȡ����Ų����ǲ���һȭ��$n$l��ȥ",
    "lian"      :"$N����ʹ��һ�С����ȡ�����ϸ��Ħÿһ���仯",
    "jibie"     :48,
    "zhaoshi":"�����ȡ�",
    "sen"       :1,
        "dodge"     :10,
        "parry"     :15,
        "damage"     :240,
        "damage_type":  "����"
]),
});

string * parry_msg = ({
    "$nһ�С��ϲ��崸����˫�Ʒ��裬$N��ǰһ����ʧȥ��$n����Ӱ��\n",
    "$n������ȭ��һ�С���Ԫ�֡�������$N��һ����\n",
    "����$nһ�С���ȭ���ȡ�������һ����������$N�Ĺ��ơ�\n",
});
    
int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}

int valid_combine(string combo) { return combo=="dahong-quan"; }

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
int valid_learn(object me)
{
    return 1;
}
string perform_action_file(string func)
{
	return __DIR__"shizi-zhan/"+func;
}