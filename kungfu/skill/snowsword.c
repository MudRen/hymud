// snowsword. 【风回雪舞剑法】

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N身形稍退，使出一招 寒芳留照魂应驻",
        "$N不闪不避，一式 晚凝深翠拂平沙",
        "$N使出 攒花染出几霜痕",
        "$N妍然一笑，一式 霜印传神梦也空",
        "$N一个急转，使出 风波不信菱枝弱",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w化为一道金光罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，顿时一阵幽香飘向$n",
});


mapping *action = ({
        ([      "action":
"$N使一招"+BLINK""+HIB"「寒芳留照魂应驻」"NOR+"，手中$w化为一道疾光刺向$n的$l",
                "dodge":                15,
                "parry":                10,
                "damage":               330,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N几个急转，使出"+BLINK""+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
                "dodge":                35,
                "parry":                15,
                "damage":               340,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N淡淡一笑，一式"+BLINK""+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
                "dodge":                10,
                "parry":                15,
                "damage":               335,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w轻轻一抖，一式"+BLINK""+HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招"+BLINK""+HIR"「篱筛破月锁玲珑」"NOR+"只看得$n眼花缭乱，哪里还能招架",
                "dodge":                20,
                "parry":                20,
                "damage":               335,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式"+BLINK""+MAG"「暗香浮动月黄昏」"NOR+"",  
                "dodge":                35,
                "parry":                35,
                "damage":               340, 
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N不闪不避，一式"+BLINK""+HIC"「风波不信菱枝弱」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":                35,
                "parry":                310,
                "damage":               330,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N手中$w轻轻一抖，一式「霜印传神梦也空」幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N手中$w再一抖，只见寒光点点，飘浮不定，罩向$n的$l"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               435,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸"NOR,
                "dodge":                30,
                "parry":                35,
                "damage":               335,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N一式「风波不信菱枝弱」，神色娴雅，蓄势待发，一道剑光澄如秋水、寒似玄冰"NOR,  
                "dodge":                35,
                "parry":                35,
                "damage":               450, 
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;


    
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练风回雪舞剑法。\n");

//        if( (string)me->query_skill_mapped("force")!= "moonforce")
//                return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("你的「碧涛心法」火候太浅。\n");

        if ((int)me->query_skill("zhuyue-whip", 1) < 120)
                return notify_fail("你的「逐月鞭法」火候太浅。\n");
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("snowsword",1);
         lvl = (int)me->query_skill("snowsword", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 30 )
                return notify_fail("你的内力或气不够，没有办法练习风回雪舞剑法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -3);
//        write("你按著所学练了一遍风回雪舞剑法。\n");
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"snowsword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("bitao-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("snowsword",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "bitao-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
		return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;

}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("snowsword",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}
