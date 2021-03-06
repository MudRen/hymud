// longjiao-blade.c from mool

inherit SKILL;

mapping *action = ({
([  "action" : "$N向前跨上一驳冬一招「离别」，手中$w自左向右向$n的$l缓缓划去",
        "damage":260,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向上跃起，左手刀诀，右手一抖，$w刀光缦妙如瀑，一式「心心相映」直刺$n的$l",
        "damage":280,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「雪涌兰关」，$w闪起数道寒光，自下而上反挑$n的$l",
        "damage":300,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「情感」，手中$w看似横扫实则斜劈，刺向$n的$l",
        "damage":320,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「思念」，$w挽出三个刀花，绵绵不断划向$n的$l",
        "damage":340,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「似海深情」，左手一捏刀诀，右手$w自上而下雷霆万钧般直向$n的$l劈乐下去",
        "damage":310,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「爱意绵绵」，身在半空，$w回抽，反手勾向$n的$l",
        "damage":380,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身影一晃, 绕到$n背后，一招「情意无限」，刀尖向$n的$l疾挑",
        "damage":300,
    "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w斜指，一招「混沌一破」，反身一顿，一刀向$n的$l撩去",
        "damage":350,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「斩妖屠龙」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "damage":360,
        "damage_type" : "割伤"
]),
([      "action" : "$N展身虚步，提腰跃落，一招「劈鲛塔浪」，刀锋化作两股斩向$n",
        "damage":370,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「日月晦明」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "damage":380,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「黯水伏魔」，双手持刃拦腰反切，砍向$n的胸口",
        "damage":390,
        "damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「万劫不复」，上劈下撩，左挡右开，齐齐罩向$n",
        "damage":500,
        "damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jinghai-force", 1) < 10)
                return notify_fail("你的靖海神功火候太浅。\n");
 	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("你的靖海神功修为不够，无法修炼。\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("你的凌霄手修为不够，无法修炼。\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("你的磐恒掌修为不够，无法修炼。\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("你的翩仙步法修为不够，无法修炼。\n");
		
if (me->query_skill("longjiao-blade", 1) > 251)
{
			if(me->query_skill("bibo-sword", 1) < me->query_skill("longjiao-blade", 1))
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");
}		
        return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够无法练习缚龙斩鲛刀法。\n");
	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("你的靖海神功修为不够，无法修炼。\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("你的凌霄手修为不够，无法修炼。\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("你的磐恒掌修为不够，无法修炼。\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("你的翩仙步法修为不够，无法修炼。\n");

if (me->query_skill("longjiao-blade", 1) > 251)
{
			if(me->query_skill("bibo-sword", 1) < me->query_skill("longjiao-blade", 1))
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");
}		
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"longjiao-blade/"+func;
}

int effective_level() { return 11;}

string *parry_msg = ({
        "$n手中$v急点$N的$w，荡开了$N的$w。\n",
       "$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});
string *unarmed_parry_msg = ({
	"$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
