// bawang-qiang.c 【霸王枪法】
//modified by bird at /07/13/2004
//为了让霸王枪在转世后能学


inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N运足精神，使出一招 迎门三不过 ",
        "$N手腕一翻，一式 拨草寻蛇",
        "$N似欲退走，可是忽地一个转身，百忙中使出一招 举火烧天势",
        "$N一个跨步，使一招 灵蛇出洞",
                "$N一按枪把,使出一招 回马枪",
});
string* skill_tail =({
        "，手中$w连续刺向$n面门，哽嗓，前心。",
        "，手中$w一挺刺向$n$l。",
        "，手中$w势若飞瀑刺向$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，手中$w带出一道寒气，由下而上疾挑$n$l",
});

mapping *action = ({
        ([      "action":
"$N使一招"+BLINK""+HIW"「迎门三不过」"NOR"，手中$w连续刺向$n面门，哽嗓，前心",
                "damage":               350,
                "dodge":                5,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招"+BLINK""+HIG"「拨草寻蛇」"NOR"刺向$n$l",
                "damage":               340,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一个跨步，使一招"+BLINK""+HIC"「高山流水」"NOR"，手中$w势若飞瀑刺向$n的$l",
                "damage":               345,
                "dodge":                20,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一按枪把，啪！地一声抖出"+BLINK""+HIM"「五朵枪花」"NOR"。上下左右，虚虚实实刺向$n全身要害",
                "damage":               345,
                "dodge":                10,
                "parry":                15,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N一个斜跨，使个"+BLINK""+HIR"「举火烧天势」"NOR"，手中$w带出一道寒气，由下而上疾挑$n$l",
                "damage":              355,
                "dodge":                20,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招"+BLINK""+HIB"「灵蛇出洞」"NOR"快若闪电，毒辣无比",
                "damage":               335,
                "dodge":                5,
                "parry":                25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使个"+BLINK""+MAG"「飞鸟投林势」"NOR"，身形斜飞，从侧面突出一枪，径刺$n$l",
                "damage":               440,
                "dodge":                15,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N似欲退走，可是忽地一个转身，百忙中使出一招"+BLINK""+RED"「回马枪」"NOR"，$w一挺刺向$n$l",
                "damage":               450,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

       if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("你的太玄神功火候太浅。\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得霸王枪法深奥之极，一时间难以领会。\n");

        if(me->query_skill("sumi-jian", 1) < 150)
                return notify_fail("你的素霓剑法为不够，无法修炼。\n");

        if(me->query_skill("huanhe-dao", 1) < 150)
                return notify_fail("你的煊赫刀修为不够，无法修炼。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "club" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="club") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("bawang-qiang",1);
         lvl = (int)me->query_skill("bawang-qiang", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object

 weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("club",1);
        level2= (int) me->query_skill("taixuan-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("bawang-qiang",1))+50;
if (damage > 1600) damage=1600;
 if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "taixuan-gong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("bawang-qiang",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
else 
        if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>190 
        ) {
        victim->receive_wound("qi", (random(level)+80));
return random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                   "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                   HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                   "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
}


}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("你的内力或气不够。\n");

    if( (string)me->query_skill_mapped("force")!= "taixuan-gong")
     return notify_fail("必须太玄神功才能学。\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得霸王枪法深奥之极，一时间难以领会。\n");

        if(me->query_skill("sumi-jian", 1) < 150)
                return notify_fail("你的素霓剑法为不够，无法修炼。\n");

        if(me->query_skill("huanhe-dao", 1) < 150)
                return notify_fail("你的煊赫刀修为不够，无法修炼。\n");
   me->receive_damage("qi", 32);
   me->add("neili", -6);

   return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bawang-qiang/" + action;
}