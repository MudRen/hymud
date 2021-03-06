//sumi-jian.c.素霓剑法
//date:1997.9.6
//by dan,ysg
#include <ansi.h>     

inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

int yunwu(object me, object victim, object weapon, int damage);
int ruhe(object me, object victim, object weapon, int damage);

mapping * action=({
    ([  "action":
"$N一招「赵客缦胡缨」，手中$w剑意凛然，一股慷慨悲壮之势随着剑身前指而弥散开来，
迅疾无比的刺向$n眉心",
        "lian"  :
"$N宛如荆坷再世，手中$w斜斜挥出，虽说毫无花哨，自有其万夫不当之势，正是一招「赵客缦胡缨」。",
        "sen"   :8,
        "jibie" :10,
        "dodge" :30,
        "parry" :10,
        "force" :20,
        "wound" :10,
        	"damage" :230,
        "zhaoshi" : "「赵客缦胡缨」",
        "damage_type":"刺伤"   ]),
    ([  "action":
"不待$n变招，$N紧接着又一招「十步杀一人」，手中$w如搜魂之剑，如影随形的朝$n身上刺来",
        "lian"  :
"$N展开身法，使出一招「十步杀一人」，手中$w剑芒伸缩不定，化百炼钢为饶指柔。",
        "sen"   :9,
        "jibie" :20,
        "dodge" :35,
        "force" :30,
        "parry" :15,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "「十步杀一人」",
        "damage_type":"刺伤"    ]),
    ([  "action":
"只见剑光一闪，$N使出一招「脱剑膝前横」，空气中只见一道淡淡的剑气闪过，转眼之
间$n只觉眼前剑光闪动，剑气慑人",
        "lian"  :
"$N手中$w一动，使出一招「脱剑膝前横」，只见剑气如山，将空气撕扯得兹兹作响。",
        "sen"   :10,
        "jibie" :40,
        "dodge" :20,
        "parry" :0,
        "force" :30,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "「脱剑膝前横」",
        "damage_type":"刺伤" ]),
    ([  "action":
"$N使出一招「邯郸先震惊」，身随剑走，在空中身形一转，手中$w绽出了无数剑花，刺
向$n的各处穴道",
        "lian"  :
"$N剑尖一颤，一招「邯郸先震惊」，手中$w化作点点青光。",
        "sen"   :11,
        "jibie" :30,
        "dodge" :0,
        "parry" :30,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "「邯郸先震惊」",
        "damage_type":"刺伤"    ]),
    ([  "action": 
"$N反手一挥，一招「不惭世上英」，剑尖斜指，手中$w从一个意想不道的方向直刺$n的咽喉。",
        "lian"  : 
"$N身形一侧，宛如醉卧沙场，但反手令人意想不道的一击，使出的正是一招「不惭世上英」。",
        "sen"   :12,
        "jibie" :100,
        "dodge" :20,
        "parry" :20,
        "force" :30,
        "wound" :40,
        	"damage" :330,
        "zhaoshi" : "「不惭世上英」",
        "damage_type" : "刺伤"  ]),    
});

string *parry_msg = ({
"$n身体一个平移，使出一招「赵客缦胡缨」，手中的$v化作一天剑雨，将$N的攻势湮灭在其中。\n",
"$n剑锋一侧，使出一招「脱剑膝前横」，手中的$v舞得密不透雨，只听见一阵迅疾的兵器
接触之声，磕开了$N的$w。\n",
"$n将手中的$v一抖，一招「邯郸先震惊」，化作点点青光，$N顿觉无从下手，无奈只得收招自保。\n",
"$n反手一招「不惭世上英」，剑锋斜指，划出一道长虹，手中$v一下就荡开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
    "$n双手舞得密不透风，使出「避实就虚」，封住了$N的攻势。\n",
    "$n反手一招「将繁就简」，避开了$N的这一招。\n",
    "$n使出一招「虚敲实应」，架住了$N的攻势。\n",
    "但见$n一招「欲擒故纵」，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{   
    if ( objectp( weapon ) )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping query_action(object me, object weapon)
{
		int d_e1 = 15;
	int d_e2 = 30;
	int p_e1 = 25;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 310;
	int m_e2 = 410;
	int i, lvl,level, seq, ttl = sizeof(action);

        string *msg1,*msg2;
        
  msg1 = ({
		HIW"$N手中$w"+HIW"连连挥舞，声东击西，虚虚实实，幻人耳目，变化古怪之极，$n不禁心下骇然！"NOR,
		HIW"$N手中$w"+HIW"越使越快，一套「百变千幻衡山云雾十三式」有如云卷雾涌，$n不由得目为之眩！"NOR,
		HIW"见$N手上$w"+HIW"剑招变幻，犹如鬼魅，五花八门，层出不穷，$n觉眼前尽是一片剑光飞舞来去！"NOR,
        });
        msg2 = ({
		HIR"但见一点点鲜血从$w"+HIR"下溅了出来，$n腾挪闪跃，竭力招架，始终脱不出$N的剑光笼罩，鲜血渐渐在身周溅成了一个红圈，$N又已刺出一剑！"NOR,
		HIY"$N一剑既占先机，後着绵绵而至，一柄$w"+HIY"犹如灵蛇，颤动不绝，在$n的攻势中穿来插去，只逼得$n连连倒退！"NOR,
		HIY"$n中了一剑，大骇之下，急向後退，$N手中$w"+HIY"已如狂风骤雨般连攻，当真是兔起鹘落，变化快极！"NOR,

        });        
        level   = (int) me->query_skill("sumi-jian",1);
        if ((int)me->query_skill("literate", 1)> 5 && userp(me) )	
return action[random(sizeof(action))];

	if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -30);	
        me->add("neili", -100);	
	me->set_temp("ruhe_finish");	
	me->delete_temp("ruhe_count");	
	me->delete_temp("ruhe_hit");	
        return ([
	"action":HIY"$N左手计算已毕，$w"+HIY"出招，正是泰山派剑法中最高深的绝艺「岱宗如何」，这一剑算准了$n的一切应变後着，实是威力无俦，博大精深"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 520,
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }
	else if((int)me->query_skill("sword",1)> random(300)+100
 	&& me->query("neili") > 200 
	&& me->query_temp("ruhe") && random(2)==0){
        me->add("neili", -20);
        return ([
	"action":YEL"$N$w"+YEL"倏地向$n刺出，连连出剑，每一剑的剑招皆苍然有古意，招数古朴，内藏奇变，正是「五大夫剑」"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(55),
        "skill_name" : "五大夫剑",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
	&& me->query("neili") > 100
	&& me->query_temp("ruhe") && random(2)==0){
        me->add("neili", -10);
        return ([
	"action":HIC"$N陡然向$n连环三剑，$w"+HIC"使得犹似行云流水，大有善御者驾轻车而行熟路之意，将「快活三」剑招发挥得淋漓尽致"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(33),
        "skill_name" : "快活三",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }
else
if(me->query_temp("hengshan") 
	&& random(level) > 160 && random(2)==0){
        me->add("neili", -20);
        return ([
        "action":HIG"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，巧妙无比，似左实右，已点在$n$l"NOR,
        "force" : 700,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 700,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100  && random(2)==0){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N翻身剑，剑诀斜引，锋芒从半空中直泻下来，向$n的$l斩落"NOR,
        "force" : 680,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 750,
        "damage_type":"刺伤"]);
        }
else if(me->query_temp("yunwu") && me->query_temp("yunwu_hit")  && random(2)==0){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"刺伤"]);
        }


    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得素霓剑法深奥之极，一时间难以领会。\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("你的太玄神功火候太浅。\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("你的袖里乾坤修为不够，无法修炼。\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("你的五狱拳修为不够，无法修炼。\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("你的飒沓身法修为不够，无法修炼。\n");

		if (me->query_skill("sumi-jian", 1) > 251)
{
			if(me->query_skill("huanhe-dao", 1)+100 < me->query_skill("sumi-jian", 1))
		return notify_fail("你的煊赫刀修为不够，无法修炼。\n");
}	
			if(me->query_skill("huanhe-dao", 1) < 100)
		return notify_fail("你的煊赫刀修为不够，无法修炼。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够无法练习。\n");
	       if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("你的太玄神功火候太浅。\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("你的袖里乾坤修为不够，无法修炼。\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("你的五狱拳修为不够，无法修炼。\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("你的飒沓身法修为不够，无法修炼。\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");
			if(me->query_skill("huanhe-dao", 1) < 100)
		return notify_fail("你的煊赫刀修为不够，无法修炼。\n");

if (me->query_skill("sumi-jian", 1) > 251)
{
			if(me->query_skill("huanhe-dao", 1)+100 < me->query_skill("sumi-jian", 1))
		return notify_fail("你的煊赫刀修为不够，无法修炼。\n");
}		

	
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"sumi-jian/"+func;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，太玄内劲"
                                   "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                   HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                   "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
}
}



int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
		CYN"不料$N左手屈指连算，已算准了$n的腾挪方位，又即挺剑出招！\n"NOR,
		CYN"但是$n的武功门路已被$N算得清清楚楚，眼见已避开$N的招数，"+weapon->name()+CYN"竟又直逼而至！\n"NOR,
        });
if (!victim) return 0;
if (!me) return 0;
if (!weapon) return 0;
if (!damage) return 0;
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
if (!victim) return 0;
if (!me) return 0;
victim->start_busy(2);
//if (victim=me) return 0;
if (victim && me
&& !me->query_temp("dsauto")
&& !me->is_busy())
{
victim->start_busy(2);
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
	   }
}

int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n见$n伤口中一道血箭如涌泉般向上喷出，原来$p中剑后内力未消，将鲜血逼得从伤口中急喷而出，既诡异，又可怖。\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+30);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}
