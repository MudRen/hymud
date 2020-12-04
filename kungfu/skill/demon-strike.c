// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N双掌一错，一招“魔火天焚”幻出漫天掌影拢向$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌纷飞，一招“魔王食飧”直取$n的$l",
                "dodge":                10,
                "parry":                30,
                "damage":                130,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N暴喝一声，双掌连环推出，一招“魔吼天地”强劲的掌风直扑$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出如意地魔连环八掌中的“魔弑森森”，完全将$n的$l笼罩在双掌之下",
                "dodge":                10,
                "parry":                30,
                "damage":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N化掌为刀，一招“乾坤尽魔”，左右掌分砍$n的两处要害",
                "dodge":                20,
                "parry":                30,
                "damage":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N内气上提，全身拔起，一招“魔高和寡”，双掌凌空拍下",
                "dodge":                70,
                "parry":                10,
                "damage":                180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N提气游走，一招“魔海漭漭”，森森掌风无孔不入般地击向$n的$l",
                "parry":                40,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出如意地魔连环八掌中的“璞宇浑魔”双掌携天地魔神之威击向$n的$l",
                "parry":                40,
                "force":                120,
		"damage" :		250,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练如意地魔连环八掌必须空手。\n");

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
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n施展出如意地魔连环八掌，轻描淡写的化解了$N的攻势。\n",
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
        return "只听一声惨嚎，一股鲜血从$n的伤口喷出！\n" ;	
}
}