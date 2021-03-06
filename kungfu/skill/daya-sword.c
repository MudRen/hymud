// daya-jian.c
//  大雅古剑法

#include <ansi.h>
#define OO YEL"大雅古剑法"NOR
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";

string* skill_head =({
        "$N手腕一抖，使出一招 「盘庚式」",
        "$N不闪不避，一式 「毕命式」",
        "$N纵身跃起，一招 「罔命式」",
        "$N身化万千，一式 「大畜式」",
        "$N如发狂一般，使出一招 「“比”字诀」",
        "$N一声暴叫，发出一式 「述而式」",
});

string* skill_tail =({
        "，手中$w刺向$n的全身。",
        "，手中$w带起万道银光，向$n的面门点去。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w锋芒直射$n",
        "，看似破绽百出，实则密不可透",
        "，$w带着杀气向$n狂卷而来。",
});

mapping *action = ({
    ([  "action": 
"只见$N手中$w舞动出一片网状，使出"OO"第一式：「盘庚式」，\n"
"将$n周围尽皆罩住。\n",
        "parry_msg" :
"$n使出「“恒”字诀」，口中念道：日月得天而能久照，四时变化而能久成。\n"
"只见$n丝毫不乱，应接不暇，将$N的招式一一截住。",
"parry_power":          10,
 //       "jibie" :15,
        "dodge" :20,
        "parry" :30,
        "zhaoshi":"「盘庚式」",
        "damage":290,
        "damage_type":"割伤"    ]),

    ([  "action":
"只见$N手中$w挥动一股霸道的剑气，正是"OO"第二式：「毕命式」，\n"
"对着$n左右斜劈，凛然有风。",
        "parry_msg"  :
"$n使出「“遁”字诀」，口中念道：刚当位而应，与时行也。\n"
"$n见机而动，向外轻巧地跃开。",
"parry_power":          10,
//        "jibie" :30,
        "dodge" :10,
        "parry" :10,
        "zhaoshi":"「毕命式」",
        "damage":280,
        "damage_type":"割伤" ]),
    ([  "action":
"只见$N手中$w闪出点点剑光，联成一线，正是"OO"第三式：「罔命式」，\n"
"$w带动光线，在$n面前挥舞。",
        "parry_msg"  :
"$n使出「“萃”字诀」，口中念道：乃乱乃萃，其志乱也。\n"
"$n似乎有些散乱，竟尔突然定住，顿时将$N的攻势化解于无形。",
"parry_power":          10,
//        "jibie" :45,
        "dodge" :10,
        "parry" :20,
        "zhaoshi":"「罔命式」",
        "damage":290,
        "damage_type":"割伤"    ]),
    ([  "action":
"只见$N舞动手中$w，正是"OO"第四式：「大畜式」，\n"
"剑光霍霍之中，从一个意想不到的角度突然挑出一剑，向$n的下颚直刺。",
        "parry_msg"  :
"$n使出「“革”字诀」，口中念道：文明以说，大亨以正。\n"
"$n在千钧一发之际，突然不知从什么地方横出一剑，拦住了$N的这一招。",
"parry_power":          10,
//        "jibie" :60,
        "dodge" :10,
        "parry" :30,
        "zhaoshi":"「大畜式」",
        "damage":280,
        "damage_type":"割伤"    ]),
        ([      "action":
"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，正是"OO"\n"
"第五式：「瞽蒙式」，剑锋直向$n左肩刺过去。",
                "parry_msg" :
"$n使出「“比”字诀」，口中念道：舍逆取顺。\n"
"$n低头躲过$N这一招，闪身跃开。",
        "zhaoshi":"「瞽蒙式」",
"parry_power":          10,
//        "jibie":75,
        "dodge":15,
        "parry":40,
        "damage":260,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体在原地游走，脚步散而不乱，正是"OO"第六式：「述而式」，\n"
"手中$w摆动，不时向$n刺出一剑。",
                "parry_msg" :
"$n使出「“需”字诀」，口中念道：刚健而不陷，其义不穷困矣。\n"
"$n无偏不偏，恰恰从$N的攻势中躲了开去。",
        "zhaoshi":"「述而式」",
"parry_power":          10,
//        "jibie":90,
        "dodge":20,
        "parry":20,
        "damage":300,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体十分稳重，正是"OO"第七式：「至诚式」，\n"
"手中$w若有若无，缓缓击出一剑，向$n的肩部搭了过去。",
                "parry_msg" :
"只见$N身体十分稳重，手中$w若有若无，缓缓击出一剑。\n"
"$n急忙撤招回守。",
        "zhaoshi":"「至诚式」",
"parry_power":          10,
//        "jibie":105,
        "dodge":30,
        "parry":20,
        "damage":320,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N使出的正是"OO"第八式：「止戢式」，\n"
"手中$w剑光柔和，隐隐有风雷之声，向$n扑面涌去，令人顿有退避之意。",
                "parry_msg" :
"手中$w剑光柔和，隐隐有风雷之声，令人听来顿有退避之意。",
        "zhaoshi":"「止戢式」",
"parry_power":          10,
//        "jibie":120,
        "dodge":10,
        "parry":50,
        "damage":300,
        "damage_type":"割伤"
        ]),
});

string *daya= ({
HIR"$N念着口诀：载戢戈，载蠹弓矢，我求懿德，肆于时夏。\n"NOR,
HIB"$N念着口诀：若网在纲，有条不紊。\n"NOR,
HIC"$N念着口诀：彰善潸恶，树之风声。\n"NOR,
RED"$N念着口诀：绳衍纠谬，格其非心。\n"NOR,
YEL"$N念着口诀：刚健笃实辉光，日新其德。\n"NOR,
BLU"$N念着口诀：鼓琴瑟，以役大师。\n"NOR,
WHT"$N念着口诀：志于道，据于德，依于仁，游于艺。\n"NOR,
HIW"$N念着口诀：盹盹其仁，渊渊其渊，浩浩其天。\n"NOR
});

int practice_skill( object me )
{
        string msg;
                object target;
//
                if ((int)me->query_skill("daya-sword", 1) < 200)
        return notify_fail("大雅剑法修为太差,你无法领悟其精髓。\n"); 
        if( (int)me->query("qi") < 125
        ||      (int)me->query("neili") < 150 )
                return notify_fail("你的内力或气不够，没有办法练习大雅古剑法。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -35);
    if( me->query("max_neili")<2000 )
        return notify_fail("你内力不足以练习此剑法！\n");

        //message_vision(daya[random(sizeof(daya))], me, target);
    return 1;
}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法学。\n");

     if( (string)me->query_skill_mapped("force")!= "wuzheng-xinfa")
     return notify_fail("必须无争心法才能练。\n");

if ((int)me->query_skill("wuzheng-xinfa", 1) < 290)
		return notify_fail("你的无争心法火候不够。\n");

if ((int)me->query_skill("wuyun-jian", 1) < 290)
		return notify_fail("你的五韵七弦剑火候不够。\n");

	if ((int)me->query_skill("pomopima-jian", 1) < 290)
		return notify_fail("你的泼墨披麻剑火候不够。\n");

	if ((int)me->query_skill("piaoyibu", 1) < 290)
		return notify_fail("你的飘逸步法火候不够。\n");

	if ((int)me->query_skill("jiangjun-zhang", 1) < 290)
		return notify_fail("你的裴将军诗杖法火候不够。\n");

	if ((int)me->query_skill("xuantian-zhi", 1) < 290)
		return notify_fail("你的玄天无情指火候不够。\n");

	if ((int)me->query_skill("shigu-bifa", 1) < 290)
		return notify_fail("你的石鼓打穴笔法火候不够。\n");



        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return action[random(sizeof(action))]["parry_msg"];
}

string perform_action_file(string action)
{
	return __DIR__"daya-sword/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int i, level;
        object target;
object weapon;
	int jiali, time,level2,damage,damage2;

        level   = (int) me->query_skill("daya-sword",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("wuzheng-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("daya-sword",1))+50;

        dam = (int) me->query("max_neili");
if (damage_bonus < 30) damage_bonus=30;
if (damage > 1600) damage=1600;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "wuzheng-xinfa")
{
dam=dam/12;
	if (dam>1800) dam=1800;
        victim->receive_damage("qi",dam);
        victim->receive_wound("qi", dam);
        return daya[random(sizeof(daya))]+HIR"你听到「唰」一声轻响好像凉一阵风吹过，忽然间$n血冒三丈，被$N剑气所伤！\n"NOR; 
        //return HIR"你听到「唰」一声轻响好像凉一阵风吹过，忽然间$n血冒三丈，被$N剑气所伤！\n"NOR; 
}
	if( random(12)==1 || random(level) > 180)
	{

        victim->receive_wound("qi", damage_bonus+10 );	
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
  }


}



int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("daya-sword", 1);

        if( damage < 10 ) return 1;
          
            if ( random(12) == 0 || random(level) > 180){
         ob->start_busy(2);
         msg = RED"$N面对$n的攻势。突然长啸一声 !!\n"NOR;
         msg += RED"「五韵七弦音!!」。$n两眼一花 吐出一口鲜血!!。\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
i=ob->query("qi")/12;
if (i> 8000) i=8000;
if (ob->query("qi")/12 > 20)
             ob->add("qi",-i);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-i);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}