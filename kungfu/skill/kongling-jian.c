// kongling-jian.c
//  ���齣��
inherit SKILL;

mapping *action = ({
        ([      "action":
        "$Nʹһ�С����˹��֡�������$w��һ���������$n��$l",
        "lian" :
        "$Nʹһ�С����˹��֡�������$w��һ�����������ǰ��......",
                "jibie":7,
                "zhaoshi":"�����˹��֡�",
                "sen"  : 3,
                        "damage":330,
                        "dodge":                20  ,
                        "wound":                20   ,
                        "damage_type":  "����"
        ]),
        ([      "action":
        "$Nһ�С����»Ի͡�������Ʈ�����ߣ�����$wն��$n��$l",
                "lian":
        "$Nһ�С����»Ի͡�������Ʈ�����ߣ�����$w�󿪴��ڣ�����Ʈ��......",
                "jiebie":30,
                "zhaoshi":"�����»Ի͡�",
                "sen" : 4,
                        "damage":230,
                        "dodge":                30,
                        "wound":                25 ,
                        "damage_type":  "����"
        ]),
        ([      "action":
        "$N����$w�й�ֱ����һʽ���������š���׼$n�ļ羮Ѩ�̳�һ��",
                "lian":
        "$N����$w�й�ֱ����һʽ���������š���׼��ǰ��б��һ��......",
                "jibie":40,
                "limb":"��ͷ",
                "zhaoshi":"��������",
                "sen": 4,
                        "dodge":30 ,
                "damage":230,
                "wound":30,
                        "damage_type":  "����"
        ]),
        ([      "action":
        "$N��$wƾ��һָ��һ�С�����ָ�ϡ���$w�����Ŵ���$n�ľ���.......",
                "lian":
        "$N��$wƾ��һָ��һ�С�����ָ�ϡ���$w�����Ŵ����Ϸ�.......",
                "jibie":62,
                "zhaoshi":"������ָ�ϡ�",
                "sen": 4,
                "limb":"����",
                        "damage":230,
                        "dodge":                20,
                        "wound":                40,
                        "damage_type":  "����"
        ]),
    ([  "action":"$N�������˸�����������һ�С����ɵ�ɽ��������$w��׼$nһ��",
        "lian"  :"$N�������˸�����������һ�С����ɵ�ɽ��������$w����һ�㡣",
        "sen"   :4,
        "jibie" :20,
        "damage":230,
        "dodge" :20,
        "parry" :10,
        "zhaoshi":"�����ɵ�ɽ��",
        "wound":25,
        "damage_type":"����"    ]),
    ([  "action":"ֻ��$N������ǰ��˫�ֽ���$w��һ�С����չ������$n��ͷ�����¶���һ��",
        "lian"  :"$Nһ��������ʹ��һ�С����չ��������$w����һ�á�",
        "sen"   :5,
        "damage":230,
        "jibie" :30,
        "dodge" :30,
        "zhaoshi":"�����չ��",
        "wound":40,
        "damage_type":"����"    ]),
    ([  "action":"$N����$w��һ�С��ͻ���β������$n��$l����һ��",
        "lian"  :"$N����$w��һ�С��ͻ���β�������ٻ�����",
        "sen"   :5,
        "jibie" :40,
        "damage":230,
        "dodge" :10,
        "parry" :10,
        "zhaoshi":"���ͻ���β��",
        "wound":30,
        "damage_type":"����"    ]),
    ([  "action":"$Nһ�С�����֮�项���߾�����$w����$nӭͷһ��",
        "lian"  :"$Nһ�С�����֮�项������$w���һ����",
        "sen"   :3,
        "damage":230,
        "jibie" :5,
        "dodge" :20,
        "parry" :20,
        "zhaoshi":"������֮�项",
        "wound":35,
        "damage_type":"����"    ]),
    ([  "action":"$N����һ�С��˻�֮΢��������$w��$n��$lһĨ",
        "lian"  :"$N����$w��ʹ��һ�С��˻�֮΢����ǰ˳��һĨ��",
        "sen"   :5,
        "jibie" :10,
        "damage":230,
        "dodge" :30,
        "parry" :0,
        "zhaoshi":"���˻�֮΢��",
        "wound":50,
        "damage_type":"����" ]),
    ([  "action":"ֻ��$N������ǰ��˫�ֽ���$w��һ�С���ɽ��ľ������$n��ͷ�����¶���һ��",
        "lian"  :"$Nһ��������ʹ��һ�С���ɽ��ľ��������$w����һ�á�",
        "sen"   :5,
        "damage":230,
        "jibie" :30,
        "dodge" :15,
        "parry" :20,
        "zhaoshi":"����ɽ��ľ��",
        "wound":50,
        "damage_type":"����"    ]),
    ([  "action":"$N����$w��һ�С���̦���͡�����$n��$l����һ��",
        "lian"  :"$N����$w��һ�С���̦���͡������ٻ�����",
        "sen"   :5,
        "damage":230,
        "jibie" :40,
        "dodge" :10,
        "parry" :15,
        "zhaoshi":"����̦���͡�",
        "wound":60,
        "damage_type":"����"    ]),
        ([      "action":
"$Nʹ���������项��$w���ӽ������ն��$n��$l",
                "lian" :
"$Nʹ���������项��$w���ӣ�ֻ�����������ɷ�Ǿ���......",
                "zhaoshi":"�������项",
                "jibie":20,
                "damage":230,
                "sen" :6,
                "dodge":                30,
                "wound":                60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�С���֮˼֮��������Ʈ�����ߣ�����$wն��$n��$l",
                "lian":
"$Nһ�С���֮˼֮��������Ʈ�����ߣ�����$w�󿪴��ڣ�����Ʈ��......",
                "jiebie":30,
                "zhaoshi":"����֮˼֮��",
                "sen" : 6,
                "damage":230,
                "dodge":                30,
                "wound":                50 ,
        "parry":        10,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һԾ������$wһ�С�������Υ������׼$n������бб�̳�һ��",
                "lian" :
"$N����һԾ������$wһ�С�������Υ����бб�������·���ȥ......",
                "jibie":50,
                "zhaoshi":"��������Υ��",
                "sen"  :7,
                        "dodge":40,
                "limb":"С��",
                "damage":230,
                "wound":40, 
                "damage":330,
                "damage_type":  "����",
        ]),
});

string *parry_msg = ({
        "$nʹ��һ�С��罫���ơ������е�$v��������ѩӰ����ס��ȫ����\n",
        "$nʹ�������֡��������ΰ���$w���ִ̳�����ʱ�߽���$N�Ĺ��ơ���\n",
        "$nʹ��һ�С���ñ��ʫ�������е�$vƮ���������ճ���㽣�����ε�$N�������۾�����\n",
        "$n���е�$vһ����һ�С���֪��ĺ������$N����練����ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��һ�С��罫���ơ�����ס��$N�Ĺ��ơ�\n",
        "$n����һ�С���ñ��ʫ���������˻���һ�Ż�Ӱ��\n",
        "$nʹ��һ�С���֪��ĺ��������Ϊ��������$N��硣��\n",
        "$n˫��һ�ӣ������Ƴ����ȵ�$N�������ˡ�\n",
});




string query_parry_msg(object weapon)
{   
    if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if( me->query("max_neili") < 100 )
		return notify_fail("��������������޷��������齣����\n");

	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("��Ĵ��ȭ������\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("���̫�泤ȭ������\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("�������ķ�������\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");
						
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,n;

	level   = (int) me->query_skill("kongling-jian",1);

	n = sizeof(action);
	for(i=0;i<n;i++)
		if(level >= action[i]["lvl"])
			return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("��Ĵ��ȭ������\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("���̫�泤ȭ������\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("�������ķ�������\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");

	if((int)me->query("qi") < 50)
		return notify_fail("����������������齣����\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"kongling-jian/"+func;
}

