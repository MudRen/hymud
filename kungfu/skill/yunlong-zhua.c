// yunlong-zhua.c -云龙爪

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([	"action" : "$N全身拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
	"force" : 150,
        "dodge" : 15,
        "parry" : 10,
	"damage": 120,
	"lvl" : 0,
	"skills_name" : "凶鹰袭兔",
	"damage_type" : "抓伤"
]),
([	"action" : "$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪一前一后拢向$n的$l",
	"force" : 220,
        "dodge" : 20,
        "parry" : 15,
	"damage": 145,
	"lvl" : 10,
	"skills_name" : "雄鹰展翅",
        "damage_type" : "抓伤"
]),
([	"action" : "$N一式「拔翅鹰飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
	"force" : 250,
        "dodge" : 20,
        "parry" : 20,
	"damage": 160,
	"lvl" : 20,
	"skills_name" : "拔翅鹰飞",
        "damage_type" : "内伤"
]),
([	"action" : "$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
	"force" : 290,
        "dodge" : 25,
        "parry" : 20,
	"damage": 180,
	"lvl" : 30,
	"skills_name" : "迎风振翼",
        "damage_type" : "内伤"
]),
([	"action" : "$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
	"force" : 350,
        "dodge" : 30,
        "parry" : 25,
	"damage": 200,
	"lvl" : 40,
	"skills_name" : "飞龙献爪",
        "damage_type" : "内伤"
]),
([	"action" : "$N伏地滑行，一式「顶天立地」，上手袭向膻中大穴，下手反抓$n的裆部",
	"force" : 350,
        "dodge" : 35,
        "parry" : 25,
	"damage": 220,
	"lvl" : 50,
	"skills_name" : "顶天立地",
        "damage_type" : "内伤"
]),
([	"action" : "$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
	"force" : 380,
        "dodge" : 55,
        "parry" : 55,
	"damage": 245,
	"lvl" : 60,
	"skills_name" : "搏击长空",
        "damage_type" : "内伤"
]),
([	"action" : "$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
	"force" : 430,
        "dodge" : 40,
        "parry" : 40,
	"damage": 260,
	"lvl" : 60,
	"skills_name" : "鹰扬万里",
        "damage_type" : "内伤"
]),
([	"action" : "$N忽的拨地而起，使一式「苍龙出水」，身形化作一道闪电射向$n",
	"force" : 470,
        "dodge" : 50,
        "parry" : 50,
	"damage": 280,
	"lvl" : 70,
	"skills_name" : "苍龙出水",
        "damage_type" : "内伤"
]),
([	"action" : "$N微微一笑，使一式「万佛朝宗」，双手幻出万道金光,直射向$n的$l",
	"force" : 470,
        "dodge" : 60,
        "parry" : 60,
	"damage": 350,
	"lvl" : 80,
	"skills_name" : "万佛朝宗",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yunlong-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练云龙爪必须空手。\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("你的云龙神功火候不够，无法学云龙爪。\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学云龙爪。\n");
	if ((int)me->query("max_neili") < 350)
		return notify_fail("你的内力太弱，无法练云龙爪。\n");
	if ((int)me->query_skill("claw",1) <40)
		return notify_fail("你的基本爪法火候不够，无法学云龙爪。\n");
       if (((int)me->query_skill("houquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的猴拳太低了。\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的百花错拳太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)+100) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙手太低了。\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙神功太低了。\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙身法太低了。\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yunlong-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练云龙爪。\n");
       if (((int)me->query_skill("houquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的猴拳太低了。\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的百花错拳太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)+100) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙手太低了。\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙神功太低了。\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-zhua", 1))
               return notify_fail("你的云龙身法太低了。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"yunlong-zhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("yunlong-zhua", 1);
        flvl = me->query("jiali");
        if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (lvl < 100 || flvl < 10 ||  damage_bonus < 60
        )
                return;
if (random(3)==0)
{
victim->apply_condition("zhua_poison", random(me->query_skill("yunlong-zhua",1)/40) + 11 +
			victim->query_condition("zhua_poison"));
victim->receive_wound("qi", (damage_bonus ) / 2, me);
                return HIR "只听$n" HIR "一声惨嚎，看来受到了凝血神爪毒劲的干扰！\n" NOR;
}
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N左手聚成虎爪状! 「凝血神抓」一把抓住$n的"+ xue_name[random(sizeof(xue_name))] +NOR;

           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           return j;
}      
