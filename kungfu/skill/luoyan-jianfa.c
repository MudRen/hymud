#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action": "$N����$wһ������һ����һʽ������«�ޡ���$n��$lֱ�̶�ȥ��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":200,
                "damage_type":  "����"
        ]),
        ([      "action": "$Nʹ���ط����㽣���еġ�������㡹���У����潣�ƶ�����$n��$l��ȥ��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":210,
                "damage_type":  "����"
        ]),
        ([      "action": "$N���쳤Х,һ�С���Ϻ��족��ɽ��������$n��ȥ��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":220,
                "damage_type":  "����"
        ]),
        ([      "action": "$N����һԾ��һ�С��Ǻ�һ�㡹$w��Ϊ��㺮�ǣ�����$n��",
		        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":230,
                "damage_type":  "����"
        ]),
        ([      "action": "$Nƽ��һ��,һƬ������,һ����Ӱ��������һ�С�«���϶ɡ�!",
		        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":240,
                "damage_type":  "����"
        ]),
        ([      "action": "$N����$w����һȦ��һ�С����·��㡹������$w��Ϊһ��������$n��ȥ!��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":250,
                "damage_type":  "����"
        ]),
         ([      "action": "$Nһ�С�����ʧȺ����$w�������£�����һ����,����$n���ʺ�",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":260,
                "damage_type":  "����"
        ]),
        ([   "action": "$Nһ�С������ϻء�����$w��$n��ȥ����;������һת��$w��ָ��$n��ͷ����",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":270,
                "damage_type":  "����"
        ]),
      ([    "action": "$N����һ��ת��һ�С����㱯������$w��Ϊ������Ӱ������ס$n��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":280,
               "damage_type": "����"
     ]),
      ([    "action": "$Nһ�С���Ӱǧ���$w��Ϊһ�ž��⣬ͻȻ��Ӱ��ɢ,$w��ָ��$n�ʺ�",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":290,
          "damage_type": "����"
      ]),
      ([    "action": "$N��Цһ��,��һ�С����㼸ʱ����$w��ƮƮ����$n������",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":300,
          "damage_type": "����"
      ]),
      ([    "action": "$N��ȻһЦ��һ�С�������𡹣���ʱ����������������޹����$w��ֱ��$n���ķ���ȥ��",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
		"damage":350,
         "damage_type": "����"
        ]),
});

    
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
    return notify_fail("�������������û�а취�����㽣����\n");

        if( me->query_skill("nei-bagua",1) <=50)
                 return notify_fail("�ڰ��Եȼ�������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

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

int practice_skill(object me)
{
        if( (int)me->query("qi") < 50
        ||      (int)me->query("neili") < 30 )
                return 
notify_fail("�����������������û�а취��ϰ���㽣����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -3);
//          write("�㰴����ѧ����һ�����㽣����\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"luoyan-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int level, jiali, time,level2,damage,nlevel;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        nlevel= (int) me->query_skill("luoyan-jianfa",1);
damage= (int) me->query("neili",1)/10;

        if( damage_bonus < 20 ) return 0;
        if( random(5)==0) {
                
                victim->receive_wound("qi", (random(nlevel)+20) / 2 ,me);
                return HIR "$N һ�С�������𡹣���ʱ����������������޹���� ֱ��$n���ķ���ȥ��\n";
        }
        else if( random(damage_bonus/2) > victim->query_str() && random(3)==0) {
                victim->receive_wound("qi", (random(nlevel)+20) / 2,me );
                return HIR "$N һ�С���Ӱǧ�������������Ϊһ�ž��⣬ͻȻ��Ӱ��ɢ,�ѻ���$n�����壡\n";
        }
}



