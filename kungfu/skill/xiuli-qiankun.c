//xiuli-qiankun.c ����Ǭ�� 5��ȭ��
//by wyh
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N˫�伱�ӳ�һƬ��Ӱ����Ȼһ����Ӱֱ��������һ�С�˫������ɫ����ֱ����$n$l",
                "lian":
"$N˫�伱�ӳ�һƬ��Ӱ����Ȼһ����Ӱֱ��������һ�С�˫������ɫ����ֱ˦��ȥ",
                "zhaoshi":         "˫������ɫ",
                "dodge":                40,
                "sen":                  4,
                "jibie":                  0,
                "parry":                30,
                "force":                70,
                "damage":               260,
                "damage_type":  "����",
                                   ]),
        ([      "action":               
"$N���η�ת��˫�仯��һ����ɫǽ�ڣ�һ�С�������˪�š�����ס��$n�����й���",
                "lian":
"$N���η�ת��һ�С�������˪�š���˫�仯��һ����ɫǽ��",
                "zhaoshi":         "������˪��",
                "dodge":                30,
                "parry":                100,
                "force":                60,
                "sen":                  5,
                "jibie":                 16,
                "damage":               230,
                "damage_type":  "����",
                    ]),
        ([      "action":               
"$N�����Զ٣�����һ�һ�С�������ϼ�ߡ���$n��$l��ȥ",
                "lian":
"$N���Զ٣�����һ�һ�С�������ϼ�ߡ�ֱ�ĳ�ȥ",
                "zhaoshi": "������ϼ��",
                "dodge":               15,
                "sen":                  5,
                "parry":                30,
                "jibie":                 36,
                "force":                50,
                "damage":               240, 
                "damage_type":  "����",
                       ]),
        ([      "action":               
"$N����һ�ڣ���Ȼ�������ߣ��ұ�˳������һ�С����¹ҳ�������$n��ȥ",
                "lian":
"$N����һ�ڣ���Ȼ�������ߣ��ұ�˳������һ�С����¹ҳ��������˳�ȥ",
                "zhaoshi":   "���¹ҳ���",
                "sen":                  6,
                "jibie":                 60,
                "dodge":                20,
                "parry":                50,
                "force":                70,
                "damage":               270,
                "damage_type":  "����",
                     ]),
  ([      "action":               
"$N����΢�Σ�һ�С��ɷ���ҹ�ҡ�����$n����Թ�Ϊ�أ�һƬ��Ӱ˦��$n",
                "lian":
"$N����΢�Σ�һ�С��ɷ���ҹ�ҡ�ֱ˦��ȥ",
                "zhaoshi":         "�ɷ���ҹ��",
                "dodge":                15,
                "sen":                  7,
                "jibie":                 82,
                "parry":                55,
                "force":                100,
                "damage":               280,
                "damage_type":  "����",
                                   ]),
        ([      "action":               
"$N����Ծ��һ�С�Ǳ������������һƬ��Ӱ��$nͷ������",
                "lian":
"$N����Ծ��һ�С�Ǳ������������һƬ��Ӱֱ�ֶ���",
                "zhaoshi":         "Ǳ��������", 
                "dodge":                20,
                "parry":                40,
                "force":                110,
                "sen":                  7,
                "jibie":                  310,
                "damage":               90,
                "damage_type":  "����",
                    ]),

});

string  *parry_msg=({
    "$nһ�С���������ᢡ������������ֻ��������ķ��ǰ������������˳��Ĵ���.\n"
    "��$N�Ĺ��ƾ������˻�ȥ��",
    "$n�����������������������$N��˫�֡�",
    "$n����Ʈ����һ�С����������项Ծ�ڿ��У�˫����裬����һֻ�ʵ����㿪��$N��һ����",
    "$n˫��һ�ϣ�����������ǰ������һ����ǽ����$N�Ĺ��ƾ������˻�ȥ��",
});
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}

int valid_combine(string combo) { return combo=="wuyu-quan"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("������Ǭ��������֡�\n");
    return 1;
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
	return __DIR__"xiuli-qiankun/"+func;
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