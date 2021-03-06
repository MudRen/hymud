// bibo-sword.c from mool
inherit SKILL;

mapping *action = ({
([      "action" : "$N漫步提腰，一招「英雄潇洒我独行」，飘然来至$n面前，随即手中$w微震，剑尖疾点向$n的$l",
        "force" : 50,
        "dodge" : 20,
        "damage" : 130,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N斜跨一步，使出一式「儿女情长只恨短」，挥剑舞出两道一长一短的光影直刺$n的$l",
        "force" : 75,
        "dodge" : 15,
        "damage" : 135,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「翩然离去不思归」，$w骤然出鞘又立刻回到剑鞘中，随即转身翩然离去。\n$n这时才感觉到有一股劲气逼向自己的$l",
        "force" : 50,
        "dodge" : 25,
        "damage" : 240,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手举剑向天，一招「傲立群雄无所惧」，$w带起阵阵惊雷，自上而下向$n剁去",
        "force" : 50,
        "dodge" : 10,
        "damage" : 245,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N施展出「倾城一笑万人醉」，手握$w颔首微微一笑，$n只看得一呆，却见一道剑影\n犹如龙游般袭向自己的$l，而自己却没看清$N何时出的手！！",
        "force" : 50,
        "dodge" : 20,
        "damage" : 350,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚踏实，右脚虚点，一招「一曲奏毕愁肠结」，$w带着一团剑花，飘浮不定地逼向$n的$l",
        "force" : 70,
        "dodge" : 5,
        "damage" : 355,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「处子弄箫亦多情」，左手轻抚$w，随即猛地一弹，右手向前一递，\n只见一道闪烁不定的剑影迅速刺向$n的$l",
        "force" : 90,
        "dodge" : 5,
        "damage" : 360,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身低首，神色黯然，一招「闻声哀怨断人肠」，$w剑尖游移不定地刺向$n的$l",
        "force" : 80,
        "dodge" : 15,
        "damage" : 370,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N坐手掩面，一招「彼将离兮泪涟涟」，右手$w斜向下划出，$n微觉奇怪，正迟疑间，\n却见$N手中的$w已反挑而上，直刺自己的咽喉",
        "force" : 70,
        "dodge" : 5,
        "damage" : 380,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([  "action" : "$N忽然面露微笑，一招「随音而舞笑开颜」，右手$w一闪，舞出三团剑花刺向$n的上中下三路",
        "force" : 80,
        "dodge" : 25,
        "damage" : 390,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手食指疾点$w，一招「箫音有情人无情」，$w发出一声龙吟，余音缭绕，\n$n只觉得的胸前一闷，一阵刚猛的劲气迫向自己",
        "force" : 90,
        "dodge" : 25,
        "damage" : 390,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手微震，一招「箫声响毕情两断」，手中$w急颤，发出一阵震耳欲聋的轰鸣，刹那间飞沙走石，\n$n已在一团剑光的笼罩下，正勉力支撑着",
        "force" : 90,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 110,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if( me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，无法修炼。\n");

	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("你的靖海神功修为不够，无法修炼。\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("你的凌霄手修为不够，无法修炼。\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("你的磐恒掌修为不够，无法修炼。\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("你的翩仙步法修为不够，无法修炼。\n");

	if(me->query_skill("longjiao-blade", 1) < 250)
		return notify_fail("你的缚龙斩鲛刀修为不够，无法修炼。\n");


	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,n;

	level   = (int) me->query_skill("bibo-sword",1);

	n = sizeof(action);
	for(i=0;i<n;i++)
		if(level >= action[i]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if(me->query_skill("jinghai-force", 1) < 250)
		return notify_fail("你的靖海神功修为不够，无法修炼。\n");

	if(me->query_skill("lingxiao-shou", 1) < 250)
		return notify_fail("你的凌霄手修为不够，无法修炼。\n");

	if(me->query_skill("panheng-zhang", 1) < 250)
		return notify_fail("你的磐恒掌修为不够，无法修炼。\n");

	if(me->query_skill("xian-steps", 1) < 250)
		return notify_fail("你的翩仙步法修为不够，无法修炼。\n");

	if(me->query_skill("longjiao-blade", 1) < 250)
		return notify_fail("你的缚龙斩鲛刀修为不够，无法修炼。\n");

	if((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练碧波剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"bibo-sword/"+func;
}

string *parry_msg = ({
        "$n手中$v急点$N的$w，荡开了$N的$w。\n",
       "$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});
string *unarmed_parry_msg = ({
	"$n把手中的$v舞的是风雨不透，封住了$N的攻势。\n",
});

int effective_level() { return 11;}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
