// 追风拳  zhuifeng-quan.c
//   ChangeLog by lin on March 24, 1997

inherit SKILL;

mapping *action = ({
    ([   "action"  :"$N目视对手，使出一招「决眦入归鸟」，左手护胸，右手握拳向$n一击而出。",
         "lian"    :"$N目视前方，使出一招「决眦入归鸟」，左手护胸，右手握拳向空气中一击而出。",
         "zhaoshi" : "「决眦入归鸟」",
         "sen"   : 4,
         "parry" : 10,
         "dodge" : 10,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 220,
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N使出一招「何以有羽翼」，双手成环形，就$n当头打下。",
         "lian"    :"$N使出一招「何以有羽翼」，双手成环形，就空气中当头而下。",
         "zhaoshi" : "「何以有羽翼」",
         "damage" : 330,
         "wound"  : 15, 
         "sen"    : 8,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 20,   
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N轻轻一纵，一招「心随雁飞灭」，身体倒转，双拳向$n脑后击出。",
         "lian"    :"$N轻轻一纵，一招「心随雁飞灭」，身体倒转，双拳向下击出。",
         "zhaoshi" : "「心随雁飞灭」",
         "sen"   : 12,
         "jibie" : 40,
         "parry" : 30,
         "dodge" : 30,
         "damage": 240,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N身形一顿，使出一招「烟鸟栖初定」，双手就往$n的脉门上切了过去。",
         "lian"  :"$N身形一顿，使出一招「烟鸟栖初定」，双手就往空气中切去。",
         "zhaoshi" : "「烟鸟栖初定」",
         "damage": 250,
         "wound" : 15, 
         "sen"   : 16,
         "parry" : 40,
         "dodge" : 40,
         "jibie" : 60,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N两拳前后分开，使出一招「西山鸾鹤群」，右拳直向$n肩部销去。",
         "lian"  : "$N两拳前后分开，使出一招「西山鸾鹤群」，右拳直向空气里销去。",
         "zhaoshi" : "「西山鸾鹤群」",
         "sen"  : 20,
         "jibie": 80,
         "parry" : 50,
         "dodge" : 50,
         "damage": 260,
         "damage_type":  "瘀伤"
    ]),
    ([   "action":"$N使出一招「下窥指高鸟」，右手上指，左手乘势抓住$n的右腕，将$n带了个趔趄。",
         "lian" :"$N使出一招「下窥指高鸟」，右手上指，左手乘势往前抓出。",
         "zhaoshi" : "「下窥指高鸟」",
         "sen"   : 24,
         "jibie" : 100,
         "damage": 270,
         "wound" : 20, 
         "parry" : 60,
         "dodge" : 60,
         "damage_type":  "瘀伤"
    ]),   
    ([   "action":"$N一个横跃而出，使出一招「意欲凌风翔」，两拳向下猛击$n的头部。",
         "lian" :"$N一个横跃而出，使出一招「意欲凌风翔」，两拳向下猛击空气。",
         "zhaoshi" : "「意欲凌风翔」",
         "sen"   : 24,
         "jibie" : 120,
         "damage": 280,
         "wound" : 20, 
         "parry" : 70,
         "dodge" : 70,
         "damage_type":  "瘀伤"
    ]),   
        ([      "zhaoshi": "「伴君赴南山」",
                "action":               
"$N使出一招「伴君赴南山」，左拳击向$n太阳，右脚跨上一步。",
                "lian" :
"$N使出一招「伴君赴南山」，左拳击出，右脚跨上一步。",
                "jibie":          6,
                "limb":"太阳穴",
                "sen"  :      5,
                "dodge":                10,
                "parry":                20,
                "damage":                230,
                "damage_type":  "瘀伤"
        ]),
        ([      "zhaoshi" : "「追月千里」",
                "action":               
"$N一招「追月千里」，连踏上两步，双拳飞击$n头部两侧。",
                "lian" :
"$N一招「追月千里」，连踏上两步，双拳飞击而出",
                "jibie":15,
                "limb":"头部",
                "sen"  :5,
                "dodge":                10,
                "parry":                10,
                "damage":                240,
                "damage_type":  "瘀伤"
        ]),
        ([      "zhaoshi" :" 「踏雪寻梅」",
                "action":               
"$N收拳腰间，一招「踏雪寻梅」，晃到$n身后，「呼」地挥出一拳.",
                "lian" :
"$N收拳腰间，一招「踏雪寻梅」，飞步抢上，「呼」地挥出一拳.",
                "jibie":22,
                "limb":"后心",
                "sen"  : 6,
                "dodge":                20,
                "parry":                10,
                "damage":                250,
                "damage_type":  "瘀伤"
        ]),
        ([      "zhaoshi" : "「反身术」",
                "action":               
"$N退身侧步，让过$n，右拳反击$n后腰。",
                "lian" :
"$N退身侧步，右拳反击而出。",
                "jibie":30,
                "limb":"后腰",
                "sen"  : 6,
                "dodge":                30,
                "parry":                10,
                "wound" :               10, 
                "damage":                340,
                "damage_type":  "瘀伤"
        ]),
        ([      "zhaoshi" : "「连环腿」",
                "action":               
"$N飞身而起，左脚连踢$n上身.",
                "lian" :
"$N飞身而起，左脚连续踢出。",
                "jibie":40,
                "sen"  : 7,
                "limb":"胸前",
                "dodge":                30,
                "parry":         10,
                "damage":                260,
                "damage_type":  "瘀伤"
        ]),
        ([      "zhaoshi" : "「乱风腿」",
                "action":               
"$N双拳连挥，拳中加腿，逼得$n连连后退。",
                "lian" :
"$N双拳连挥，拳中加腿，令人眼花缭乱。",
                "jibie":50,
                "sen"  :5,
                "parry":                35,
                "wound" :               20, 
                "damage":                340,
                "damage_type":  "瘀伤"
        ]),
});

string *parry_msg = ({
    "$n一招「七星会北斗」，双掌齐收，架住了$N.\n",
    "$n撤步转身，躲开了$N的攻击。\n",
});

string *unarmed_parry_msg = ({
    "$n抬臂上格，左拳挥出，化解了$N的攻势.\n",
});




string query_parry_msg(object weapon)
{   
    if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_learn(object me)
{

       if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("你的「碧涛心法」火候太浅。\n");

        if ((int)me->query_skill("baihua-zhang", 1) < 120)
                return notify_fail("你的「百花掌」火候太浅。\n");

        if ((int)me->query_skill("feixian-jian", 1) < 220)
                return notify_fail("你的「飞仙剑法」火候太浅。\n");

        if ((int)me->query_skill("qiongya-bufa", 1) < 220)
                return notify_fail("你的「琼崖身法」火候太浅。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry"  || usage=="cuff";
}

int valid_combine(string combo) { return combo=="baihua-zhang"; }

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
string perform_action_file(string func)
{
	return __DIR__"zhuifeng-quan/"+func;
}