//������֮����ȭ
//      ������ʽ��
//           �й�������
//           ������Ϊ��
//           �ۻ����Ⱥ�
//           ǧ���׳ʿ
//           ����������
//           ����Ȱ����    

//wuyu-quan.c.����ȭ 
//date:1997.9.11
//by dan
#include <ansi.h>
inherit SKILL;

mapping *action = ({
    ([   "action"  :"$Nʹ��һ�С��й�����������˫ȭһ���ó���ʮ��ȭӰ��$nȫ����ȥ",
         "lian"    :"$Nʹ��һ�С��й�����������˫ȭһ���ó���ʮ��ȭӰ������ȫ����ȥ",
         "zhaoshi" : "���й���������",
         "sen"   : 8,
         "parry" : 20,
         "dodge" : 20,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 250,
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nһ�С�������Ϊ�᡹���ڿն��𣬺���˫ȭ��$n��ȥ",
         "lian"    :"$Nһ�С�������Ϊ�᡹���ڿն��𣬺���˫ȭ�����л�ȥ",
         "zhaoshi" : "��������Ϊ�᡹",
         "damage" : 250,
         "wound"  : 15, 
         "sen"    : 9,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 30,   
         "damage_type":  "����"
    ]),
    ([   "action"  :"$Nʹ�������ۻ����Ⱥ�һ����ȣ���$nδ�з�Ӧ��˫ȭ��Ϯ$n���ظ�",
         "lian"    :"$Nʹ�������ۻ����Ⱥ�һ����ȣ���$nδ�з�Ӧ��˫ȭ��Ϯ����е��ظ�",
         "zhaoshi" : "���ۻ����Ⱥ�",
         "sen"   : 10,
         "jibie" : 60,
         "parry" : 30,
         "dodge" : 20,
         "damage": 370,
         "damage_type":  "����"
    ]),
    ([   "action": "$N˫ȭһ��ʹ����ǧ���׳ʿ������׼$n����������",
         "lian"  :"$N˫ȭһ��ʹ����ǧ���׳ʿ������׼���������������",
         "zhaoshi" : "��ǧ���׳ʿ��",
         "damage":  280,
         "wound" :  15, 
         "sen"  :  8,
         "parry" : 30,
         "dodge" : 20,
         "jibie":    100,
         "damage_type":  "����"
    ]),
    ([   "action": 
"$N����ȫ����������ȭ��ֻ�����ǽڱ����������һ�С����������㡹Ѹ�͵���$n��ȥ",
         "lian"  : 
"$N����ȫ����������ȭ��ֻ�����ǽڱ����������һ�С����������㡹Ѹ�͵���$n��ȥ",
         "zhaoshi" : "�����������㡹",
         "sen"  : 10,
         "jibie": 120,
         "parry" : 10,
         "dodge" : 40,
         "damage": 320,
         "damage_type":  "����"
    ]),
    ([   "action":"$Nʹ��������Ȱ���� ����������������ͬʱ����$n��$l",
         "lian" :"$Nʹ��������Ȱ���� ����������������ͬʱ������",
         "zhaoshi" : "������Ȱ���� ��",
         "sen"   : 8,
         "jibie" : 140,
         "damage": 300,
         "wound" : 20, 
         "parry" : 10,
         "dodge" : 25,
         "damage_type":  "����"
    ]),   
});

string * parry_msg = ({
    "$nһ�С�����Ȱ���� ����˫�Ʒ��裬$N��ǰһ����ʧȥ��$n����Ӱ��\n",
    "$n������ȭ��һ�С�ǧ���׳ʿ��������$N��һ����\n",
    "����$nһ�С��й���������������һ����������$N�Ĺ��ơ�\n",
});
    
int valid_learn(object me)
{
    if ( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
    {    
        write("������ȭ������֡�\n");
        return 0;
    }
   
    if ( me->query("max_neili") < 200 )
    {   
        write("�������̫�����޷�������ȭ\n");
        return 0;
    }
    return 1;
}

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}

int valid_combine(string combo) { return combo=="xiuli-qiankun"; }

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
	return __DIR__"wuyu-quan/"+func;
}




int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return damage;

        if ((int)me->query_skill("literate", 1)> 5 )	
return damage;

if (me->query("neili") < 500)
return damage;
 if (objectp(weapon = me->query_temp("weapon"))
        )
return damage;

             
  if (random(ap) < dp/2  
  && random(2)==0)
        {

                switch (random(2))
                {
                case 0:
                        result =  HIR "$n" HIR "Ĭ��̫�����ھ���̫����"
                                            "�������ȫ��$N" HIR "ֻ�����й���"
                                            "$n" HIR "����\n����������ͭǽ����һ�㣬"
                                            "˿���������á�\n"NOR;
                        break;
                case 1:
                        result =  HIR "$N" HIR "һ�л���$n" HIR "����"
                                            "����ȴ�������ͭǽ������һ��\n��������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR;
                        break;
                default:
                        result =  HIR "����$n" HIR "һ����Х����������"
                                            "�Ľ�����$N" HIR "��һ�У�\nȴû���ܵ�"
                                            "����˺���\n" NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi")*2)
me->add("qi",damage/5+200);
if ((int)me->query("eff_qi") < (int)me->query("max_qi")*2)
me->add("eff_qi",damage/5+200);
            damage=100;
            j=100;
            damage=-(damage/2);
j=damage;
            return j;

        }

}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                   "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                   HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                   "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
}
}