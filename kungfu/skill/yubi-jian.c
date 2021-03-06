//yubi-jian.c 
//by leonhart 97.7.12
//起舞弄清影，何似在人间，落花人独立，微雨燕双飞，夕阳照雨足，空翠落庭阴
//看取莲花净，应知不染心

#include <ansi.h>

inherit SKILL;

mapping * action=({
    ([  "action":"\n$N手中$w一抖，幻化出几道光影，一招「起舞弄清影」恰似满天风\n"
                 "雪罩向$n。\n",
        "lian"  :"$N手中$w一抖，幻化出满天光影，一招「起舞弄清影」向前推出。\n",
        "sen"   :6,
        "jibie" :10,
        "dodge" :25,
        "parry" :10,
        "wound" :50,
        "damage":250,
        "zhaoshi" : "「起舞弄清影」",
        "damage_type":"刺伤"   ]),
    ([  "action":"\n$N身行飘忽，瞬间来到$n的面前，一招「何似在人间」手\n"
                 "中$w似进似退，直点$n。\n",
        "lian"  :"$N身行飘忽，一招「何似在人间」$w似进似退点出。\n",
        "sen"   :7,
        "jibie" :20,
        "dodge" :15,
        "parry" :25,
        "wound" :50,        
        "damage":265,
        "zhaoshi" : "「何似在人间」",
        "damage_type":"刺伤"    ]),
    ([  "action":"\n$N淡然一笑，竟仿佛$n并不存在，手中$w一声清吟，正是「落花人独立」。\n",
        "lian"  :"$N淡然一笑，手中$w一声清吟，正是「落花人独立」。\n",
        "sen"   :7,
        "jibie" :30,
        "dodge" :15,
        "parry" :15,
        "wound" :80,
        "damage":365,
        "zhaoshi" : "「落花人独立」",
        "damage_type":"刺伤" ]),
    ([  "action":"\n$N脚步游移不定，倒转手中$w，身行如燕直冲而起，再一\n"
                 "式「微雨燕双飞」自上而下直向$n扑来。\n",
        "lian"  :"$N脚步游移不定，倒转手中$w，身行如燕直冲而起，再一\n"
                 "式「微雨燕双飞」自上而下扑去。\n",
        "sen"   :7,
        "jibie" :40,
        "dodge" :35,
        "parry" :25,
        "wound" :80,
        "damage":375,
        "zhaoshi" : "「微雨燕双飞」",
        "damage_type":"刺伤"    ]),
    ([  "action":"\n$N竟仿佛没有在战斗，神情闲适，手中$w自下转上再转而下，划过一道白虹，\n"
                                 "一招「夕阳照雨足」，$n双目为剑光所刺，不住向后倒退。\n",
        "lian"  :"$N神情闲适，手中$w自下转上再转而下，划过一道白虹，\n"
                 "正是一招「夕阳照雨足」。\n",
        "sen"   :7,
        "jibie" :50,
        "dodge" :35,
        "parry" :35,
        "wound" :60,
        "damage":370,
        "zhaoshi" : "「夕阳照雨足」",
        "damage_type":"割伤"    ]),
    ([  "action":CYN"\n$N心底空明，剑随心意，身行傲然拔起，正是「空翠落庭阴」，\n$n为$N气势所逼，不住倒退。\n"NOR,
        "lian"  :CYN"$N心底空明，剑随心意，身行傲然拔起，正是「空翠落庭阴」。\n"NOR,
        "sen"   :7,
        "jibie" :60,
        "dodge" :40,
        "parry" :40,
        "wound" :80,
        "damage":375,
        "zhaoshi" : "「空翠落庭阴」",
        "damage_type":"割伤"    ]),
    ([  "action":"\n$N气定神闲，身子似动非动，微微颔首，似若有所悟，手中$w一招「看取莲花净」。\n"
                 "仿佛$n并不存在一般。\n",
        "lian"  :"$N气定神闲，身子似动非动，微微颔首，似若有所悟，正是一招「看取莲花净」。\n",
                "sen"   :7,
        "jibie" :70,
        "dodge" :45,
        "parry" :45,
        "wound" :90,
        "damage":370,
        "zhaoshi" : "「看取莲花净」",
        "damage_type":"刺伤"    ]),
    ([  "action": CYN"\n\n$N身行瞬然而上，姿势清雅曼妙，如皓月当空，正是一招「应知不染心」"
                                  "手中$w幻成一道光轮，\n方圆几丈为$N剑气笼罩，$n几乎躲无所处。\n\n"NOR,
            "lian" : CYN"$N身行瞬然而上，姿势清雅曼妙，如皓月当空，正是一招「应知不染心」。\n"NOR,
        "sen"   :7,
        "jibie" :80,
        "dodge" :40,
        "parry" :50,
        "wound" :60,
        "damage":90,
        "zhaoshi" : "「应知不染心」",
        "damage_type" : "刺伤"  ]),
});

string *parry_msg = ({
    CYN"\n$n淡然一笑，竟仿佛$N并不存在，手中$v一声清吟，一招「落花人独立」封住$N攻势。\n"NOR,
    CYN"\n$n身行瞬然而上，姿势清雅曼妙，如皓月当空，一招「应知不染心」\n"
        "$v化出一片光影全然封住了$N的攻势。\n"NOR,
    "\n$n手中$v一抖，幻化出满天光影，一招「起舞弄清影」化解了$N的攻势。\n",
});




string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
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
	return usage=="sword" || usage=="parry" ;
}




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

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("bitao-shengong",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");
if ( me->query_skill_mapped("force") == "bitao-shengong")
{
	if( random(10)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIG "「玉影化虹!」$N"HIG"手中$w"HIG"一抖 幻化出几道光影 自上而下刺向$n"HIG"!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(8)==1 || random(level) > 50   )
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIC "$w划过一道白虹！一股鲜血从$n的身子喷出!\n" NOR;
  }
  
}
  
}

string perform_action_file(string func)
{
	return __DIR__"yubi-jian/"+func;
}