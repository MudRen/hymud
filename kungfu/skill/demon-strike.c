// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N˫��һ��һ�С�ħ����١��ó�������Ӱ£��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫�Ʒ׷ɣ�һ�С�ħ��ʳ⸡�ֱȡ$n��$l",
                "dodge":                10,
                "parry":                30,
                "damage":                130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����˫�������Ƴ���һ�С�ħ����ء�ǿ�����Ʒ�ֱ��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ħ���������еġ�ħ߱ɭɭ������ȫ��$n��$l������˫��֮��",
                "dodge":                10,
                "parry":                30,
                "damage":                160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����Ϊ����һ�С�Ǭ����ħ���������Ʒֿ�$n������Ҫ��",
                "dodge":                20,
                "parry":                30,
                "damage":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ᣬȫ�����һ�С�ħ�ߺ͹ѡ���˫���������",
                "dodge":                70,
                "parry":                10,
                "damage":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ߣ�һ�С�ħ�����ݡ���ɭɭ�Ʒ��޿ײ����ػ���$n��$l",
                "parry":                40,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ�������ħ���������еġ�����ħ��˫��Я���ħ��֮������$n��$l",
                "parry":                40,
                "force":                120,
		"damage" :		250,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������ħ�������Ʊ�����֡�\n");

        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nʩչ�������ħ�������ƣ����赭д�Ļ�����$N�Ĺ��ơ�\n",
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
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
    return __DIR__"demon-strike/" + action;
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