//huanhe-dao.c.�Ӻյ�
//date:1997.9.11
//by dan
#include <ansi.h>     
inherit SKILL;

mapping * action=({
    ([  "action":
"$N�������һ�С��⹳˪ѩ������$w���������ķ���ն��$n��ͷ��",
        "lian"  :
"$N�������һ�С��⹳˪ѩ������$w���������ķ����ڿ��з��衣",
        "sen"   :8,
        "jibie" :5,
        "dodge" :20,
        "parry" :20,
        "damage" :330,
        "zhaoshi" : "���⹳˪ѩ����",
        "damage_type":"����"
        ]),
 ([  "action":
"$N����һ����ʹ��һ�С�������캥�����Ե�������$w��������$n���ء�",
        "lian"  :
"$N����һ����ʹ��һ�С�������캥�����Ե�������$w�����̳���",
        "sen"   :9,
        "jibie" :3,
        "dodge" :25,
        "parry" :15,
        "damage" :330,
        "zhaoshi" : "��������캥��",
        "damage_type":"����"
        ]),  
 ([     "action":
"$Nʹ��һ�С�������Ȼŵ�������������һ�㣬����$w�������µ���$n��ȥ��",
        "lian"  :
"$Nʹ��һ�С�������Ȼŵ�������������һ�㣬����$w�����������¡�",
        "sen"   :10,
        "jibie" :40,
        "dodge" :30,
        "parry" :0,
        "damage" :340,
        "zhaoshi" : "��������Ȼŵ��",
        "damage_type":"����"
        ]),
  ([    "action":
"$N���ط�����һʽ�����Իӽ𴸡�����$w��ͬ��ɽ�޸�һ����$n��$l��ȥ��",
        "lian"  :
"$N���ط�����һʽ�����Իӽ𴸡�����$w��ͬ��ɽ�޸�һ��������硣",
        "sen"   :11,
        "jibie" :60,
        "dodge" :0,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "�����Իӽ𴸡�",
        "damage_type":"����"
        ]),
   ([  "action":
"$N�ص����գ��������ּ�ת��һ�С���������Ӣ����$w����$n��$l��",
        "lian"  :
"$N�ص����գ��������ּ�ת������һ�С���������Ӣ����",
        "sen"   :12,
        "jibie" :80,
        "dodge" :10,
        "parry" :30,
        "damage" :250,
        "zhaoshi" : "����������Ӣ��",
        "damage_type":"����"
        ]),
    ([  "action":
"$NͻȻ�˵�$n����ǰ��һ�С�˭������¡���$w������Ϣ������$n",
        "lian"  :
"$NͻȻ��ǰһ�ˣ�һ�С�˭������¡���$w������Ϣ��������",
        "sen"   :12,
        "jibie" :100,
        "dodge" :30,
        "parry" :30,
        "damage" :360,
        "zhaoshi" : "��˭����  ��¡�",
        "damage_type":"����"
        ]),
});
string *parry_msg = ({
    "$nһ��$v��һ�С�������캥�������е�$v����һ�����磬�Ŀ���$P��$w��\n",
    "$nһ�С�������Ȼŵ�������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
    "$pʹ��һ�С����Իӽ𴸡������е�$v��������ѩӰ��������$N��$w��\n",
    "$n����һ�С���������Ӣ������������ʧ��һ�Ź�â֮�С�\n",
    "$pʹ��һ�С��⹳˪ѩ������$wֱ��$N��˫�֡�\n",
    "$pǰ��һ����һ�С�˭������¡���$w����$N���ؿڡ�\n",
});

string *unarmed_parry_msg = ({
    "$n˫ȭ�����һ�С����Իӽ𴸡����ͻ�$N�����ţ��Ƶ�$N��;����$w��\n",
    "$n����������һ�С�������캥������$N֮�ؾȡ�\n",
    "$n˫������ܲ�͸�磬ʹ����������Ȼŵ������ס��$N�Ĺ��ơ�\n",
    "$n����Ʈ����ʹ������������Ӣ�����ܿ���$N����һ�С�\n",
    "����$nһ�С��⹳˪ѩ�������ȵ�$N�������ˡ�\n",
    "$nʹ��һ�С�˭������¡�����������$N��$l��\n",
});
     


string query_parry_msg(object weapon)
{   
    if ( objectp( weapon ) )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("���̫���񹦻��̫ǳ��\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("�������Ǭ����Ϊ�������޷�������\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("������Ӻյ����֮����һʱ��������ᡣ\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("�������ȭ��Ϊ�������޷�������\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("���������Ϊ�������޷�������\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("������޽�����Ϊ�������޷�������\n");
}		
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������������޷���ϰ��\n");
	       if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("���̫���񹦻��̫ǳ��\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("�������Ǭ����Ϊ�������޷�������\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("�������ȭ��Ϊ�������޷�������\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("���������Ϊ�������޷�������\n");

		
if (me->query_skill("huanhe-dao", 1) > 251)
{
			if(me->query_skill("sumi-jian", 1) < me->query_skill("huanhe-dao", 1))
		return notify_fail("������޽�����Ϊ�������޷�������\n");
}		
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("������Ӻյ����֮����һʱ��������ᡣ\n");

	
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"huanhe-dao/"+func;
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