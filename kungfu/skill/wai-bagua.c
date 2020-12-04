//wai-bagua.c �����

#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string *parry_msg = ({
        "����ȴ��$n���ð����ķ����ɾ�����������������$N��һ����\n",
        "���Ǳ�$n���б������ð��Ծ������ж����\n",
        "����$n���հ��Է�λ������ת�����е�$p����$Nֻ���޴����֡�\n",
});

string *unarmed_parry_msg = ({
        "����ȴ��$n���ð����ķ����ɾ�����������������$N��һ����\n",
        "$n����һת��˫�ְ��հ��Է�λ�����ʹ��$N���еĹ���ȫ����ա�\n",
        "����$N�о�����޻���һ����������ȫ��$n���ð��Ծ�жȥ��\n",
});

mapping *action=({
([	"action" : "$N˫��һ��ʹ��"+(order[random(13)])+"��Ǭ�־���"NOR"��˫ȭһ��һ�¶�׼$n��$l��������",
        "force" : 60,
        "attack": 20,
        "dodge" : 40,
        "parry" : 5,
        "damage": 114,
        "lvl"   : 0,
	"skill_name" : "Ǭ�־�",
	"damage_type" : "����"
]),
([	"action" : "$N����$nһת���������ߣ�ȭ����磬���಻���ػ���$n�����ǰ���ȭ�е�"+(order[random(13)])+"�����־���"NOR"",
        "force" : 80,
        "attack": 25,
        "dodge" : 43,
        "parry" : 6,
        "damage": 117,
        "lvl"   : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һ��"+(order[random(13)])+"�����־���"NOR"����ȭ���$n��ǰ�أ�һ������ȭѸ�ٺ�ɨ$n��̫��Ѩ",
        "force" : 100,
        "attack": 28,
        "dodge" : 45,
        "parry" : 8,
        "damage": 110,
        "lvl"   : 40,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"�����־���"NOR"��ȭ������������ʽʹ�ϣ���ȭ�Ѵ���ȭ֮�״�������׼$n��$l"+(order[random(13)])+"������"NOR"��һȭ",
        "force" : 120,
        "attack": 35,
        "dodge" : 47,
        "parry" : 11,
        "damage": 170,
        "lvl"   : 60,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��һ��"+(order[random(13)])+"�����־���"NOR"������һ�ͣ����ֻ�����������Ѹ�ײ����ڶ���һȭ����$n���ɲ�",
        "force" : 140,
        "attack": 40,
        "dodge" : 49,
        "parry" : 13,
        "damage": 120,
        "lvl"   : 90,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N��ȭͻȻ�ſ���ȭ�����ƣ�ֱ����Ϊ��ɨ��һ��"+(order[random(13)])+"�����־���"NOR"����$n��$l�к���ȥ",
        "force" : 200,
        "attack": 48,
        "dodge" : 54,
        "parry" : 18,
        "damage": 128,
        "lvl"   : 120,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����־���"NOR"����ʱ�ó�����ȭӰ��������磬����ǵ�Ϯ��$nȫ��",
        "force" : 280,
        "attack": 60,
        "dodge" : 63,
        "parry" : 23,
        "damage": 137,
        "lvl"   : 150,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N΢΢һЦ������"+(order[random(13)])+"�����־���"NOR"������Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n"
	           "˵ʱ����ʱ�죬ֻ��$Nһ��������˫ȭ�ѵ���$n��$l",
        "force" : 290,
        "attack": 62,
        "dodge" : 65,
        "parry" : 25,
        "damage": 140,
        "lvl"   : 180,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
});

int valid_combine(string combo) { return combo=="bluesea-force" ; }
string query_parry_msg(object weapon)
{
        if (weapon)
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{
        return usage == "unarmed" || usage == "cuff" || usage == "parry";
}

int valid_learn(object me)
{

	if( (string)me->query("family/family_name")!="�㵴��")
return notify_fail("�����书Ҫ���㵴�ɵ��������˲���ѧ��\n");

        if ((int)me->query_skill("parry", 1) < 100)
                return notify_fail("��Ļ����мܼ������յĻ������������޷�ѧϰ����ԡ�\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("wai-bagua", 1))
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷��������������ԡ�\n");

        return 1;
}

int practice_skill(object me)
{
        if (me->query_skill("wai-bagua", 1) < 100)
                return notify_fail("���������񹦵��˽���ǳ�������������ж�����\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("������������������񹦡�\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}



mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("wai-bagua",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(3)==1 && random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIG "�������޼�ȭ!!��$N��Ȼ�������ذ��Է�λ���ߣ�˫������ʵʵ������$n��\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(3)==1 && random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIR "Ǭ������!! $n���������Ѫ����ɫ���ɷ�ף�\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("wai-bagua", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(3) == 0 && random(level) > 180){

                switch(random(3))
                {
                case 0:
                        msg =WHT "$n" WHT "���κ�Ȼ���հ��Է�"
                                             "λת����ͣ��$N" WHT "��һ�о�Ȼ"
                                             "�޴����֡�\n" NOR;
                        break;
                case 1:
                        msg =WHT "$n" WHT "�������ð����ķ���"
                                             "�ɾ�����һ�У�$N" WHT "��ʱ����"
                                             "��׼��������������һ����������"
                                             "�ĸо���\n" NOR;
                        break;

                default:
                        msg =WHT "$N" WHT "һ���ۿ�������$n"
                                             WHT "��Ȼ��$n" WHT "����һ��"
                                             "��$N" WHT "�Ĺ������ð����ɾ�"
                                             "�������Ρ�\n"NOR;
                        break;
                }
damage=damage/3;
if (damage<10) damage=10;

        if (me->query("qi") < me->query("max_qi") )
{
if (me->query("qi") < me->query("max_qi"))
             me->add("qi",me->query("qi")/10);
if (me->query("eff_qi") < me->query("max_qi"))
             me->add("eff_qi",me->query("max_qi")/10);
}
msg += "$n��ɫһ��,�ָ���Щ������\n";
//msg += damage_msg(damage, "����");
message_vision(msg, ob, me);
}

            return damage;
}



int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wai-bagua", 1);
        if (lvl < 100) return 0;
        if (lvl < 150) return 20;
        if (lvl < 200) return 40;
        if (lvl < 250) return 50;
        if (lvl < 300) return 60;
        if (lvl < 350) return 70;
        return 80;
}

string perform_action_file(string action)
{
        return __DIR__"wai-bagua/" + action;
}


string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("wai-bagua", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


