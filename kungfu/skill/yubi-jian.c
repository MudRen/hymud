//yubi-jian.c 
//by leonhart 97.7.12
//����Ū��Ӱ���������˼䣬�仨�˶�����΢����˫�ɣ�Ϧ�������㣬�մ���ͥ��
//��ȡ��������Ӧ֪��Ⱦ��

#include <ansi.h>

inherit SKILL;

mapping * action=({
    ([  "action":"\n$N����$wһ�����û���������Ӱ��һ�С�����Ū��Ӱ��ǡ�������\n"
                 "ѩ����$n��\n",
        "lian"  :"$N����$wһ�����û��������Ӱ��һ�С�����Ū��Ӱ����ǰ�Ƴ���\n",
        "sen"   :6,
        "jibie" :10,
        "dodge" :25,
        "parry" :10,
        "wound" :50,
        "damage":250,
        "zhaoshi" : "������Ū��Ӱ��",
        "damage_type":"����"   ]),
    ([  "action":"\n$N����Ʈ����˲������$n����ǰ��һ�С��������˼䡹��\n"
                 "��$w�ƽ����ˣ�ֱ��$n��\n",
        "lian"  :"$N����Ʈ����һ�С��������˼䡹$w�ƽ����˵����\n",
        "sen"   :7,
        "jibie" :20,
        "dodge" :15,
        "parry" :25,
        "wound" :50,        
        "damage":265,
        "zhaoshi" : "���������˼䡹",
        "damage_type":"����"    ]),
    ([  "action":"\n$N��ȻһЦ�����·�$n�������ڣ�����$wһ�����������ǡ��仨�˶�������\n",
        "lian"  :"$N��ȻһЦ������$wһ�����������ǡ��仨�˶�������\n",
        "sen"   :7,
        "jibie" :30,
        "dodge" :15,
        "parry" :15,
        "wound" :80,
        "damage":365,
        "zhaoshi" : "���仨�˶�����",
        "damage_type":"����" ]),
    ([  "action":"\n$N�Ų����Ʋ�������ת����$w����������ֱ�������һ\n"
                 "ʽ��΢����˫�ɡ����϶���ֱ��$n������\n",
        "lian"  :"$N�Ų����Ʋ�������ת����$w����������ֱ�������һ\n"
                 "ʽ��΢����˫�ɡ����϶�����ȥ��\n",
        "sen"   :7,
        "jibie" :40,
        "dodge" :35,
        "parry" :25,
        "wound" :80,
        "damage":375,
        "zhaoshi" : "��΢����˫�ɡ�",
        "damage_type":"����"    ]),
    ([  "action":"\n$N���·�û����ս�����������ʣ�����$w����ת����ת���£�����һ���׺磬\n"
                                 "һ�С�Ϧ�������㡹��$n˫ĿΪ�������̣���ס����ˡ�\n",
        "lian"  :"$N�������ʣ�����$w����ת����ת���£�����һ���׺磬\n"
                 "����һ�С�Ϧ�������㡹��\n",
        "sen"   :7,
        "jibie" :50,
        "dodge" :35,
        "parry" :35,
        "wound" :60,
        "damage":370,
        "zhaoshi" : "��Ϧ�������㡹",
        "damage_type":"����"    ]),
    ([  "action":CYN"\n$N�ĵ׿������������⣬���а�Ȼ�������ǡ��մ���ͥ������\n$nΪ$N�������ƣ���ס���ˡ�\n"NOR,
        "lian"  :CYN"$N�ĵ׿������������⣬���а�Ȼ�������ǡ��մ���ͥ������\n"NOR,
        "sen"   :7,
        "jibie" :60,
        "dodge" :40,
        "parry" :40,
        "wound" :80,
        "damage":375,
        "zhaoshi" : "���մ���ͥ����",
        "damage_type":"����"    ]),
    ([  "action":"\n$N�������У������ƶ��Ƕ���΢΢��ף���������������$wһ�С���ȡ����������\n"
                 "�·�$n��������һ�㡣\n",
        "lian"  :"$N�������У������ƶ��Ƕ���΢΢��ף���������������һ�С���ȡ����������\n",
                "sen"   :7,
        "jibie" :70,
        "dodge" :45,
        "parry" :45,
        "wound" :90,
        "damage":370,
        "zhaoshi" : "����ȡ��������",
        "damage_type":"����"    ]),
    ([  "action": CYN"\n\n$N����˲Ȼ���ϣ����������������µ��գ�����һ�С�Ӧ֪��Ⱦ�ġ�"
                                  "����$w�ó�һ�����֣�\n��Բ����Ϊ$N�������֣�$n��������������\n\n"NOR,
            "lian" : CYN"$N����˲Ȼ���ϣ����������������µ��գ�����һ�С�Ӧ֪��Ⱦ�ġ���\n"NOR,
        "sen"   :7,
        "jibie" :80,
        "dodge" :40,
        "parry" :50,
        "wound" :60,
        "damage":90,
        "zhaoshi" : "��Ӧ֪��Ⱦ�ġ�",
        "damage_type" : "����"  ]),
});

string *parry_msg = ({
    CYN"\n$n��ȻһЦ�����·�$N�������ڣ�����$vһ��������һ�С��仨�˶�������ס$N���ơ�\n"NOR,
    CYN"\n$n����˲Ȼ���ϣ����������������µ��գ�һ�С�Ӧ֪��Ⱦ�ġ�\n"
        "$v����һƬ��ӰȫȻ��ס��$N�Ĺ��ơ�\n"NOR,
    "\n$n����$vһ�����û��������Ӱ��һ�С�����Ū��Ӱ��������$N�Ĺ��ơ�\n",
});




string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
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
	return usage=="sword" || usage=="parry" ;
}




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

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("bitao-shengong",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");
if ( me->query_skill_mapped("force") == "bitao-shengong")
{
	if( random(10)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIG "����Ӱ����!��$N"HIG"����$w"HIG"һ�� �û���������Ӱ ���϶��´���$n"HIG"!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(8)==1 || random(level) > 50   )
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIC "$w����һ���׺磡һ����Ѫ��$n���������!\n" NOR;
  }
  
}
  
}

string perform_action_file(string func)
{
	return __DIR__"yubi-jian/"+func;
}