// liehuo-jian.c �һ�
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С��ĺ���Ʈ����$w�ƻó�ƬƬ���ƣ�����˷�������$n",
        "force" : 170,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 0,
        "skill_name" : "�ĺ���Ʈ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ͨ�˴��������ָ������$n��$n�������ֱܷ�$w����·",
        "force" : 190,
        "dodge" : 10,
        "damage" : 130,
        "lvl" : 19,
        "skill_name" : "��ͨ�˴�",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������һ������$w��һ������������һ�ɺ�������$n��$l",
        "force" : 110,
        "dodge" : 10,
        "damage" : 140,
        "lvl" : 29,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϵ���������ָ��һ�С���������������$w����һ�Ž���������$n��$l",
        "force" : 130,
        "dodge" : 5,
        "damage" : 150,
        "lvl" : 39,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ٵ����������Ծ����أ�����$w�ó�һ��ѩ�׵��ٲ���ɨ��$n��$l",
        "force" : 150,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 59,
        "skill_name" : "���ٵ���",
        "damage_type" : "����"
]),
([      "action" : "$N���Ȱ�����ף�$wƽָ��һ�С�������ɫ��������������ɫ�������Ĵ���$n��$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 79,
        "skill_name" : "������ɫ",
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С��򴨹麣����$w��$n��������裬��$n�ۻ����ң������ڰ����ͻȻͣס����$n��$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 280,
        "lvl" : 99,
        "skill_name" : "�򴨹麣",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
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
        level   = (int) me->query_skill("liehuo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("��������������һ𽣷���\n");
        me->receive_damage("jing", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liehuo-jian/" + action;
}


mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	ap = (int)me->query("combat_exp",1)+(int)victim->query_skill("parry",1);

        dp = victim->query("combat_exp",1);
        if (objectp(weapon1))
                dp += victim->query_skill("dodge");
if (random(me->query_skill("jiuyang-shengong",1)) > 130
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N��������񹦣�ȫ������ԴԴ���ϵ�ӿ��!\n"NOR,me, victim);
me->add("neili",(random(me->query_skill("jiuyang-shengong",1))+180));
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(RED"$N��������񹦣����ϵ��˺��˺ܶ�!\n"NOR,me, victim);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+200);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+200);
}


if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(HIC"$N����Ǭ����Ų�ƣ�����æ�ҵĶ�����������!\n"NOR,me, victim);
me->start_busy(1);
}
        if ( random(ap) > dp/3 
        && me->query("jiuyangok")
        && (int)me->query_temp("shield")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
        ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
				damage_bonus=-damage/3;
                                result = HIM"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
                        }
                        else {
				result = MAG"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
				damage_bonus=-damage/3;
			}
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
				damage_bonus=-damage/2;
			        result = HIG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;                      
			}
                	else {
				result = MAG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;
				damage_bonus=-damage/2;
			}
		}	

	}
if (result)
        message_vision(result,me,victim);
        return damage;
}




mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,nlvl;

        lvl = me->query_skill("jiuyang-shengong", 1);
        nlvl = me->query_skill("liuhuo-jian", 1);

        if (damage_bonus < 50
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
		|| !me->query("jiuyangok") )
		return 0;

        if ((random(3)==0 && damage_bonus / 5 > victim->query_con()) || random(8)==0)
        {
	        me->add("neili", -5);
                victim->receive_wound("qi", (random(nlvl)) / 2+10, me);
                return random(2) ? HIR "ֻ��$N" HIR "�����ھ������ڱŷ�����������ʽ"
                                   "���������ݻ���$n" HIR "����Ԫ��\n" NOR:

                                   HIR "$N" HIR "�����񹦵�Ǳ�������˳�����ͻȻ��$n"
                                   HIR "ֻ�к���һ�����һ����Ѫ��\n" NOR;
        }
}