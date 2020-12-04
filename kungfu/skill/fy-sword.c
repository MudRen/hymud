// fy-sword.c
inherit SKILL;

mapping *action = ({
        ([      "action":
"$Nʹ��һ�С��������ա������е�$w����һ��Բ������$n��$l����",
                "dodge":                30,
                "damage":               150,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���������ĳ�һ�ƣ������е�$wʹ��һ�С��һ����ơ���ն��$n��$l",
                "dodge":                10,
                "damage":               170,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�ˮ�����ɡ�������������ˮ������$w���������ն��$n��$l",
                "dodge":                50,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һʽ�ġ������ķ�����׼$n��$l�̳�һ��",
                "dodge":                20,
                	"damage":                100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$w���μ������У�һ�С�����������$n��ȥ",
                "dodge":                60,
                	"damage":                100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫���ս���ʹ��һ�С���Ŀ�ѻԡ�����$n��$l",
                "dodge":                100,
                "damage":               240,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���н�����һ�Σ�$w��Ϊһ����⣬ʹ����������ġ�����$n��$l",
                "dodge":                100,
                "damage":               300,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취��������ƽ�����\n");

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
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 5 )
                return  notify_fail("�����������������û�а취��ϰ������ƽ�����\n"
);
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        //write("�㰴����ѧ����һ�������ƽ�����\n");
        return 1;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n�Թ����أ�$vֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С�ɽ�����ܡ�����ȫ�������$v�γɵĽ�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v�����̳�����ס$N��ȫ�����ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return -10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}
string perform_action_file(string action)
{
        return __DIR__"fy-sword/" + action;
}
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return "ֻ��һ���Һ���һ����Ѫ��$n���˿������\n" ;	
}
}