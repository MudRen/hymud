// daya-jian.c
//  ���ŹŽ���

#include <ansi.h>
#define OO YEL"���ŹŽ���"NOR
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";

string* skill_head =({
        "$N����һ����ʹ��һ�� ���̸�ʽ��",
        "$N�������ܣ�һʽ ������ʽ��",
        "$N����Ծ��һ�� ������ʽ��",
        "$N����ǧ��һʽ ������ʽ��",
        "$N�緢��һ�㣬ʹ��һ�� �����ȡ��־���",
        "$Nһ�����У�����һʽ ������ʽ��",
});

string* skill_tail =({
        "������$w����$n��ȫ��",
        "������$w����������⣬��$n�����ŵ�ȥ��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��âֱ��$n",
        "�����������ٳ���ʵ���ܲ���͸",
        "��$w����ɱ����$n��������",
});

mapping *action = ({
    ([  "action": 
"ֻ��$N����$w�趯��һƬ��״��ʹ��"OO"��һʽ�����̸�ʽ����\n"
"��$n��Χ������ס��\n",
        "parry_msg" :
"$nʹ�������㡱�־�����������������µ�����ܾ��գ���ʱ�仯���ܾóɡ�\n"
"ֻ��$n˿�����ң�Ӧ�Ӳ�Ͼ����$N����ʽһһ��ס��",
"parry_power":          10,
 //       "jibie" :15,
        "dodge" :20,
        "parry" :30,
        "zhaoshi":"���̸�ʽ��",
        "damage":290,
        "damage_type":"����"    ]),

    ([  "action":
"ֻ��$N����$w�Ӷ�һ�ɰԵ��Ľ���������"OO"�ڶ�ʽ��������ʽ����\n"
"����$n����б������Ȼ�з硣",
        "parry_msg"  :
"$nʹ�������ݡ��־���������������յ�λ��Ӧ����ʱ��Ҳ��\n"
"$n�����������������ɵ�Ծ����",
"parry_power":          10,
//        "jibie" :30,
        "dodge" :10,
        "parry" :10,
        "zhaoshi":"������ʽ��",
        "damage":280,
        "damage_type":"����" ]),
    ([  "action":
"ֻ��$N����$w������㽣�⣬����һ�ߣ�����"OO"����ʽ��������ʽ����\n"
"$w�������ߣ���$n��ǰ���衣",
        "parry_msg"  :
"$nʹ�������͡��־���������������������ͣ���־��Ҳ��\n"
"$n�ƺ���Щɢ�ң�����ͻȻ��ס����ʱ��$N�Ĺ��ƻ��������Ρ�",
"parry_power":          10,
//        "jibie" :45,
        "dodge" :10,
        "parry" :20,
        "zhaoshi":"������ʽ��",
        "damage":290,
        "damage_type":"����"    ]),
    ([  "action":
"ֻ��$N�趯����$w������"OO"����ʽ��������ʽ����\n"
"�������֮�У���һ�����벻���ĽǶ�ͻȻ����һ������$n�����ֱ�̡�",
        "parry_msg"  :
"$nʹ��������־��������������������˵�����������\n"
"$n��ǧ��һ��֮�ʣ�ͻȻ��֪��ʲô�ط����һ������ס��$N����һ�С�",
"parry_power":          10,
//        "jibie" :60,
        "dodge" :10,
        "parry" :30,
        "zhaoshi":"������ʽ��",
        "damage":280,
        "damage_type":"����"    ]),
        ([      "action":
"ֻ��$N����$w��������֮����������ͣ���������������������"OO"\n"
"����ʽ�������ʽ��������ֱ��$n���̹�ȥ��",
                "parry_msg" :
"$nʹ�������ȡ��־������������������ȡ˳��\n"
"$n��ͷ���$N��һ�У�����Ծ����",
        "zhaoshi":"�����ʽ��",
"parry_power":          10,
//        "jibie":75,
        "dodge":15,
        "parry":40,
        "damage":260,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$N������ԭ�����ߣ��Ų�ɢ�����ң�����"OO"����ʽ��������ʽ����\n"
"����$w�ڶ�����ʱ��$n�̳�һ����",
                "parry_msg" :
"$nʹ�������衱�־���������������ս������ݣ����岻�����ӡ�\n"
"$n��ƫ��ƫ��ǡǡ��$N�Ĺ����ж��˿�ȥ��",
        "zhaoshi":"������ʽ��",
"parry_power":          10,
//        "jibie":90,
        "dodge":20,
        "parry":20,
        "damage":300,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$N����ʮ�����أ�����"OO"����ʽ��������ʽ����\n"
"����$w�������ޣ���������һ������$n�ļ粿���˹�ȥ��",
                "parry_msg" :
"ֻ��$N����ʮ�����أ�����$w�������ޣ���������һ����\n"
"$n��æ���л��ء�",
        "zhaoshi":"������ʽ��",
"parry_power":          10,
//        "jibie":105,
        "dodge":30,
        "parry":20,
        "damage":320,
        "damage_type":"����"
        ]),
        ([      "action":
"ֻ��$Nʹ��������"OO"�ڰ�ʽ����ֹ�ʽ����\n"
"����$w������ͣ������з���֮������$n����ӿȥ�����˶����˱�֮�⡣",
                "parry_msg" :
"����$w������ͣ������з���֮�����������������˱�֮�⡣",
        "zhaoshi":"��ֹ�ʽ��",
"parry_power":          10,
//        "jibie":120,
        "dodge":10,
        "parry":50,
        "damage":300,
        "damage_type":"����"
        ]),
});

string *daya= ({
HIR"$N���ſھ�����꫸꣬��󼹭ʸ������ܲ�£�����ʱ�ġ�\n"NOR,
HIB"$N���ſھ��������ڸ٣��������ɡ�\n"NOR,
HIC"$N���ſھ�������������֮������\n"NOR,
RED"$N���ſھ������ܾ�����������ġ�\n"NOR,
YEL"$N���ſھ����ս���ʵ�Թ⣬������¡�\n"NOR,
BLU"$N���ſھ�������ɪ�����۴�ʦ��\n"NOR,
WHT"$N���ſھ���־�ڵ������ڵ£������ʣ������ա�\n"NOR,
HIW"$N���ſھ����������ʣ�ԨԨ��Ԩ���ƺ����졣\n"NOR
});

int practice_skill( object me )
{
        string msg;
                object target;
//
                if ((int)me->query_skill("daya-sword", 1) < 200)
        return notify_fail("���Ž�����Ϊ̫��,���޷������侫�衣\n"); 
        if( (int)me->query("qi") < 125
        ||      (int)me->query("neili") < 150 )
                return notify_fail("�����������������û�а취��ϰ���ŹŽ�����\n");
        me->receive_damage("qi", 25);
        me->add("neili", -35);
    if( me->query("max_neili")<2000 )
        return notify_fail("��������������ϰ�˽�����\n");

        //message_vision(daya[random(sizeof(daya))], me, target);
    return 1;
}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취ѧ��\n");

     if( (string)me->query_skill_mapped("force")!= "wuzheng-xinfa")
     return notify_fail("���������ķ���������\n");

if ((int)me->query_skill("wuzheng-xinfa", 1) < 290)
		return notify_fail("��������ķ���򲻹���\n");

if ((int)me->query_skill("wuyun-jian", 1) < 290)
		return notify_fail("����������ҽ���򲻹���\n");

	if ((int)me->query_skill("pomopima-jian", 1) < 290)
		return notify_fail("�����ī���齣��򲻹���\n");

	if ((int)me->query_skill("piaoyibu", 1) < 290)
		return notify_fail("���Ʈ�ݲ�����򲻹���\n");

	if ((int)me->query_skill("jiangjun-zhang", 1) < 290)
		return notify_fail("����Ὣ��ʫ�ȷ���򲻹���\n");

	if ((int)me->query_skill("xuantian-zhi", 1) < 290)
		return notify_fail("�����������ָ��򲻹���\n");

	if ((int)me->query_skill("shigu-bifa", 1) < 290)
		return notify_fail("���ʯ�Ĵ�Ѩ�ʷ���򲻹���\n");



        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return action[random(sizeof(action))]["parry_msg"];
}

string perform_action_file(string action)
{
	return __DIR__"daya-sword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int i, level;
        object target;
object weapon;
	int jiali, time,level2,damage,damage2;

        level   = (int) me->query_skill("daya-sword",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("wuzheng-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("daya-sword",1))+50;

        dam = (int) me->query("max_neili");
if (damage_bonus < 30) damage_bonus=30;
if (damage > 1600) damage=1600;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "wuzheng-xinfa")
{
dam=dam/12;
	if (dam>1800) dam=1800;
        victim->receive_damage("qi",dam);
        victim->receive_wound("qi", dam);
        return daya[random(sizeof(daya))]+HIR"��������ৡ�һ�����������һ��紵������Ȼ��$nѪð���ɣ���$N�������ˣ�\n"NOR; 
        //return HIR"��������ৡ�һ�����������һ��紵������Ȼ��$nѪð���ɣ���$N�������ˣ�\n"NOR; 
}
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus+10 );	
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
  }


}



int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("daya-sword", 1);

        if( damage < 10 ) return 1;
          
            if ( random(12) == 0 || random(level) > 180){
         ob->start_busy(2);
         msg = RED"$N���$n�Ĺ��ơ�ͻȻ��Хһ�� !!\n"NOR;
         msg += RED"������������!!����$n����һ�� �³�һ����Ѫ!!��\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
i=ob->query("qi")/12;
if (i> 8000) i=8000;
if (ob->query("qi")/12 > 20)
             ob->add("qi",-i);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-i);
}

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}