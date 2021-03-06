// shizi-zhan.c
// 十字战

inherit SKILL;

mapping *action = ({
([      "action"    :"$N坐马拉弓，击出一拳，正是一招「混元手」..",
    "lian"      :"$N坐马拉弓，击出一拳「混元手」，却总觉得有些不得要领",
    "jibie"     :8,
    "zhaoshi":"「混元手」",
    "sen"       :3,
        "dodge"     :5,
    "parry"     :0,
    "damage"     :110,
        "damage_type":  "瘀伤"
]),
([      "action"    :"$N双掌一错，使出「虚式冲天炮」，对准$n的$l连续拍出三掌",
    "lian"      :"$N双掌一错，使出「虚式冲天炮」，连续拍出三掌，结果左手把右手打得生疼",
    "jibie"     :16,      
    "zhaoshi":"「虚式冲天炮」",
    "sen"       :1,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :115,
        "damage_type":  "瘀伤"
]),
([      "action"    :"$N吐气扬声，一招「狮子大张口」双手奔$n的头颈抢去",
    "lian"      :"$N一招「狮子大张口」，双手向假象中的敌人的头颈抢去",
    "jibie"     :24,
    "zhaoshi":"「狮子大张口」",
    "limb":"头颈",
    "sen"       :1,
        "dodge"     :0,
        "parry"     :10,
        "damage"     :120,
        "damage_type":  "瘀伤"
]),
([      "action"    :"$N一招「擂拳寸腿」,起手向$n$l拍去...",
    "lian"      :"$N一招「擂拳寸腿」，起手向前拍去...",
    "jibie"     :32,    
    "zhaoshi":"「擂拳寸腿」",
    "sen"       :2,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :110,
        "damage_type":  "瘀伤"
]),
([      "action"    :"$N左掌一翻，右掌推出，一个「劈锤」击向$n$l",
    "lian"      :"$N右掌慢慢推出，左掌一翻，配合右掌的变化",
    "jibie"     :40,
    "zhaoshi":"「劈锤」",
    "sen"       :2,
        "dodge"     :10,
        "parry"     :0,
        "damage"     :125,
        "damage_type":  "瘀伤"
]),
([      "action"    :"$N使出一招「插腿」，脚踩七星步，一拳向$n$l击去",
    "lian"      :"$N慢慢使出一招「插腿」，仔细揣摩每一个变化",
    "jibie"     :48,
    "zhaoshi":"「插腿」",
    "sen"       :1,
        "dodge"     :10,
        "parry"     :15,
        "damage"     :240,
        "damage_type":  "瘀伤"
]),
});

string * parry_msg = ({
    "$n一招「拖步冲锤」，双掌翻舞，$N眼前一花，失去了$n的踪影。\n",
    "$n两手握拳，一招「混元手」，格开了$N的一击。\n",
    "但见$n一招「擂拳寸腿」，跟上一步，化开了$N的攻势。\n",
});
    
int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="strike";
}

int valid_combine(string combo) { return combo=="dahong-quan"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}
int valid_learn(object me)
{
    return 1;
}
string perform_action_file(string func)
{
	return __DIR__"shizi-zhan/"+func;
}