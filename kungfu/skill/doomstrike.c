// celestrike.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使出一招「大天星式」，右掌穿出击向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                	"damage":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「大天星式」，左掌化虚为实击向$n的$l",
                "dodge":                10,
                	"damage":                100,
                "parry":                30,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出寒天掌法「小天星式」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                "dodge":                30,
                "parry":                10,
                	"damage":                100,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「雪寒三式」，对准$n的$l连续拍出三掌",
                "dodge":                10,
                	"damage":                100,
                "parry":                30,
                "force":                60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「寒气镇四方」击向$n$l",
                "dodge":                20,
                "parry":                30,
                	"damage":                100,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「风雷七星断」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                70,
                "parry":                10,
                	"damage":                100,
                "force":                180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「气撼九重天」双掌并力推出",
                "parry":                40,
                	"damage":                100,
                "force":                220,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练寒天神掌必须空手。\n");

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("你的内力太弱，无法练寒天神掌。\n");
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
        "$n化掌为刀，一招「碧血五指挑」急切$N拿着$w的手。\n",
        "$n双掌交错，使出一招「童子拜寿」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「兵出无名」拍向$N拿着$w的手。\n",
        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。\n",
        "$n化掌为指，一招「掌指双飞」反点$N的周身要穴。\n",
        "$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。\n",
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
        return __DIR__"doomstrike/" + action;
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