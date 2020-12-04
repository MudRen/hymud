// cuixin-zhang.c ������ by XiaoYao 4/22/99
// npc skill

#include <ansi.h>
inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


mapping *action = ({
([	"action" : "$Nʹһ�С�������ӿ����˫��Ʈ�Ʋ�������$n$l",
	"force" : 160,
	"dodge" : 2,
	"damage":200+random(100),
	"skill_name" : "������ӿ",
	"lvl" : 0,
        "damage_type" : "����"
]),
([	"action" : "$Nٿ������$n��ǰ��һ�С��ﲨ���ˡ�ֱ��$n��$l",
	"force" : 240,
	"dodge" : 0,
	"damage":200+random(100),
	"skill_name" : "�ﲨ����",
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N������$nһת��һ�С����ײ�����$n$l��������",
	"force" : 320,
	"dodge" : -2,
	"damage":200+random(100),
	"skill_name" : "���ײ���",
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N���ΰ����ڰ��һ�С����羪�ס������ͻ�$n��$l",
	"force" : 400,
	"dodge" : -4,
	"damage":200+random(100),
	"skill_name" : "���羪��",
	"lvl" : 90,
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С���ɳ��Ӱ������������ֱ��$n��$l",
	"force" : 500,
	"dodge" : -6,
	"damage":200+random(100),
	"skill_name" : "��ɳ��Ӱ",
	"lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$Nһ�����ʹ�������Ǵ��ġ����ó�������Ӱ�����Ʋ���$n��$l",
	"force" : 620,
	"dodge" : -8,
	"damage":200+random(100),
	"skill_name" : "���Ǵ���",
	"lvl" : 150,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-baiguzhua"; }

int valid_learn(object me)
{
       if (!me->query("jiuyin/xia") && !me->query("jiuyin/emei"))
               return notify_fail("�����ڲ���ѧϰ�����ơ�\n");
       if( (int)me->query_skill("jiuyin-shenzhang", 1 ) >= 1)
                return notify_fail("ѧ�˾������ƣ���Ҫ�����ƣ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
        level = (int) me->query_skill("cuixin-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if( (int)me->query_skill("cuixin-zhang", 1 ) < 150 )
               return notify_fail("�����ڲ�����ϰ�����ơ�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("cuixin-zhang",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 180)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        //victim->start_busy(3);
        return HIC "��������!!��$N�͵�һ������һ����ת��$n���������$n����ӡ����ȥ��\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "������!! $n����һ��ֻ���ú�ͷһ��һ��Ѫ˿����ǹ���������\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("cuixin-zhang", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 180){
         msg = RED"$N�����㷴�߶���ֱ��$n������������$n�˿�վ�ȣ������������ߣ���$n�ߵ�һʱ�޷����֣�\n"NOR;
         msg += RED"��������!!����$N��Ӱ���ε��߳����ţ�$n�³�һ����Ѫ!!��\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}