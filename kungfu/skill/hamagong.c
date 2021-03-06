// hamagong.c 蛤蟆功
// By Five
#include <ansi.h>
inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("hamagong", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出",
        "dodge"  : 0,
        "force"  : 310,
        "attack" : 103,
        "parry"  : 21,
        "damage" : 58,
        "lvl"    : 0,
        "damage_type": "震伤" 
]), 
([      "action" : "$N丝毫不动声色，双腿微曲，右掌平伸，左掌运起蛤蟆功的"
                   "劲力，呼的一声推向$n",
        "dodge"  : 0,
        "force"  : 332,
        "attack" : 112,
        "parry"  : 37,
        "damage" : 61,
        "lvl"    : 15,
        "damage_type": "震伤"
]), 
([      "action" : "$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双"
                   "掌便向$n的方向推了出去",
        "dodge"  : 0,
        "force"  : 360,
        "attack" : 122,
        "parry"  : 53,
        "damage" : 72,
        "lvl"    : 30,
        "damage_type": "震伤"
]),
([      "action" : "$N脚步摇摇幌幌，忽然双腿一弯、一登，口中阁的一声叫喝，"
                   "手掌向$n猛然推出",
        "dodge"  : 5,
        "force"  : 410,
        "attack" : 143,
        "parry"  : 67,
        "damage" : 81,
        "lvl"    : 40,
        "damage_type": "震伤"
]), 
([      "action": "$N劲由心生，蛤蟆功内劲迸发，一股热气从丹田中直冲上来，双腿一弯，口中阁的一声叫喝，手掌便朝$n推出",
	"dodge": 15,
	"parry": 20,
	"force": 300,
	"lvl" : 50,
	"damage": 320,
	"damage_type": "瘀伤"
]),
([      "action":"$N猛喝一声，双掌倏向$n$l推出，掌力疾冲而去，劲力十分猛恶，祗隐听得呼呼风响，声音劲急，非同寻常",
	"parry": 15,
	"force": 380,
	"lvl" : 85,
	"damage": 340,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲下身子，“咕”的一声大叫，猛地双掌推出，掌风沉雄凌厉。$n突觉一股排山倒海般的力道撞来，猛迅无伦",
	"dodge": 25,
	"force": 400,
         "parry": 40,
	"lvl" : 110,
	"damage": 340,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲低身子，发掌向$n击去，左掌右掌，连环邀击，双掌连绵而上，掌法愈厉，乘势不住追击，後著凌厉之极",
	"dodge": 35,
	"parry": 40,
	"force": 420,
	"lvl" : 125,
	"damage": 330,
	"damage_type": "瘀伤"
]),
([      "action":"$N“阁”的一声大叫，发劲急推，双掌一上一下，一放一收，斗然击出，朝著$n排山倒海般劈将过来",
	"dodge": 20,
	"force": 400,
	"lvl" : 130,
	"damage": 390,
	"damage_type": "瘀伤"
]),
([      "action":"$N身子蹲下，双掌平推而出，口中咯咯大叫，身子一幌一幌。这一推劲力极大，去势却慢，看来平平无奇，内中却是暗藏极大潜力",
	"dodge": 0,
	"force": 500,
	"parry": 100,
	"lvl" : 145,
	"damage": 350,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲在地下，咕咕咕的叫了几声，内力崩涌，丹田中一股热气激升而上，身子猛跃而起，双掌推出，一股凌厉之极的掌风随之朝$n压到",
	"parry": 80,
	"dodge": 10,
	"force": 540,
	"lvl" : 150,
	"damage": 380,
	"damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出"NOR"",
        "parry": 80,
        "dodge": 140,
        "force": 150,
        "damage" : 300,
        "lvl" : 165,	
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N双手在地上一撑，身子忽地拔起，一跃三尺，落在$n的面前，单掌向$p直劈而下"NOR"",
        "weapon" : "掌缘",
        "parry": 80,
        "dodge": 135,
        "force": 160,
        "damage" : 300,
        "lvl" : 175,
        "damage_type": "割伤"
]),
([      "action": ""+(order[random(13)])+"$N突然伸手在自己脸上猛抓一把，又反足在自己肾上狠踢一脚，一掌击出，中途方向必变，实不知将打何处"NOR"",
        "dodge": 80,
        "parry": 80,
        "force": 100,
        "lvl" : 185,
        "damage" : 350,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"突然之间，$N俯身疾攻，上盘全然不守，微微侧头，一口唾沫往$n$l吐去"NOR"",
        "weapon" : "唾液",
        "dodge": 80,
        "parry": 80,
        "force": 280,
        "damage" : 300,
        "lvl" : 195,
        "damage_type": "刺伤"
]),
([      "action": ""+(order[random(13)])+"$N丝毫不动声色，双腿微曲，右掌平伸，左掌缓缓运起蛤蟆功的劲力，呼的一声推向$n"NOR"",
        "dodge": 80,
        "force": 200,
        "parry": 80,
        "lvl" : 215,
        "damage" : 300,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N默念口诀运气经脉，只觉愈转愈是顺遂，当下一个翻身跃起，咕的一声叫喊，双掌对着$n拍出"NOR"",
        "dodge": 80,
        "force": 250,
        "parry": 80,
        "lvl" : 225,
        "damage" : 350,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"但见$N双腿微曲，双掌会收，然后向$n一上一下，一放一收，斗然击出"NOR"",
        "dodge": 80,
        "force": 460,
        "parry": 80,
        "lvl" : 235,
        "damage" : 460,
        "damage_type": "瘀伤"
]),
([  "action": ""+(order[random(13)])+"$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双掌便向$n的方向推了出去"NOR"",
        "dodge": 80,
        "force": 580,
        "lvl" : 245,
        "parry": 80,
        "damage" : 580,
        "damage_type": "瘀伤"
]),
([  "action": ""+(order[random(13)])+"$N脚步摇摇幌幌的看上去马上就会跌倒，忽然双腿一弯、一登，口中阁的一声叫喝，手掌向$n猛然推出"NOR"",
        "dodge": 85,
        "force": 600,
        "lvl" : 255,
        "parry": 80,
        "damage" : 640,
        "damage_type": "瘀伤"
]),
});

mapping *reverse_action = ({
([      "action": "忽听$N大叫三声，三个筋斗翻将出来，大吼一声，恶狠狠的朝$n扑将上来",
	"dodge": 85,
	"parry": 80,
	"force": 300,
	"damage": 360,
	"damage_type": "跌伤"
]),
([      "action":"但见$N疯势更加厉害，口吐白沫，举头朝$n猛撞",
	"dodge": 85,
	"parry": 85,
	"force": 360,
	"damage": 370,
	"damage_type": "瘀伤"
]),
([      "action":"$N蓦地张口，白牙一闪，已向$n$l咬落，又快又准",
	"parry": 85,
	"dodge": 85,
	"force": 420,
	"damage": 480,
	"weapon": "牙齿",
	"damage_type": "咬伤"
]),
([      "action":"$N一口唾沫急吐，势挟劲风，竟将痰涎唾沫也当作了攻敌利器",
	"parry": 85,
	"dodge": 45,
	"force": 480,
	"damage": 490,
	"weapon":"唾沫",
	"damage_type": "刺伤"
]),
([      "action":"$N忽然张嘴，一口唾沫往$n脸上吐去，发掌击向$n趋避的方位，同时又是一口浓痰吐将过来",
	"parry": 85,
	"dodge": 80,
	"force": 540,
	"damage": 500,
	"weapon" : "浓痰",
	"damage_type": "刺伤"
]),
([      "action":"此时$N所使的招数更是希奇古怪，诡异绝伦，身子时而倒竖，时而直立，忽然一手撑地，身子横挺，一手出掌打向$n$l",
	"parry": 85,
	"dodge": 80,
	"force": 600,
	"damage": 510,
	"damage_type": "瘀伤"
]),
});
int valid_enable(string usage) {
        object me = this_player();
        int lvl;
        lvl = (int)this_player()->query_skill("hamagong", 1);

        if (lvl >= 100)    
                return usage == "strike" || usage == "force" || usage =="parry"  || usage =="unarmed";
        else
                return usage == "force";
	 }
int can_not_hubo() {return 1;}

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");

	if(i<=150)
	{
		if (i > 10 && -(int)me->query("shen") < t * 5) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	||  me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("你不先散了别派内功，怎能学蛤蟆功？！\n");
	return 1;
}

int practice_skill(object me)
{
        object ob;

        if ((int)me->query("jing") < 180)
                return notify_fail("你的精神不够好，没法练习了。\n");

        if ((int)me->query("qi") < 130)
                return notify_fail("你现在实在是太疲惫了。\n");



        if ((int)me->query_skill("force") < 180)
                return notify_fail("你的内功火候不够！\n");

        if ((int)me->query_skill("lingshe-zhangfa",1) < 280)
                return notify_fail("你的灵蛇杖法还不到家，无法使用！\n");

        if ((int)me->query_skill("xiyu-tiezheng",1) < 180)
                return notify_fail("你的西域铁筝音还不到家，无法使用！\n");

        if ((int)me->query_skill("shentuo-zhang",1) < 180)
                return notify_fail("你的神驼雪山掌还不到家，无法使用！\n");
        if ((int)me->query_skill("chanchu-bufa",1) < 180)
                return notify_fail("你的蟾蜍步法还不到家，无法使用！\n");

        if ((int)me->query_skill("lingshe-quan",1) < 180)
                return notify_fail("你的灵蛇拳还不到家，无法使用！\n");
        if ((int)me->query_skill("qixian-wuxingjian",1) < 180)
                return notify_fail("你的七弦无形剑还不到家，无法使用！\n");
        if ((int)me->query_skill("shexing-diaoshou",1) < 180)
                return notify_fail("你的蛇形刁手还不到家，无法使用！\n");
        me->receive_damage("jing", 145);
        me->receive_damage("qi", 120);
        return 1;

}


string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;
	string *power_msg = 
	({
		HIR"$N蹲下身来，运起蛤蟆功，双手平推，吐气扬眉，阁阁阁三声叫喊。这三推之力带有风疾雷迅的猛劲，实是非同小可"NOR,
		WHT"$N阁阁两声怒吼，蹲下身来，呼的双掌齐出，掌力未到，掌风已将地下尘土激起，一股劲风直扑$n面门，势道雄强无比"NOR,
		HIR"$N脸色阴沉，脸颊上两块肌肉微微牵动，两臂弯曲，阁的一声大叫，双手挺出，一股巨力横冲直撞的朝$n推将过来"NOR,
		WHT"$N蹲低身子，口中咕咕咕的叫了三声，双手推出，以蛤蟆功向$n猛攻。$n身周在$P掌力笼罩之下，只激得灰泥弥漫，尘土飞扬"NOR,
	});
	string *reverse_msg = 
	({
		HIM"但见$N招术奇特，怪异无伦，忽尔伸手在自己脸上猛抓一把，忽尔反足在自己臀上狠踢一脚，每一掌打将出来，中途方向必变，实不知打将何处"NOR,
		HIM"$N忽然反手拍拍拍连打自己三个耳光，大喊一声，双手据地，爬向$n，忽地翻身一滚，骤然间飞身跃起，双足向$n连环猛踢"NOR,
		HIM"突然之间，$N俯身疾攻，上盘全然不守，出招怪异无比，将蛤蟆功逆转运用，上者下之，左者右之，招数难以捉摸"NOR,
		HIM"$N全身经脉忽顺忽逆，手上招数虽然走了错道，但是错有错着，出手怪诞，竟教$n差愕难解"NOR,
	});

	level   = (int) me->query_skill("hamagong",1);


//if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("reverse") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && me->query("neili") > 1000)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 600+random(100),
			"damage": 820,
			"damage_type": random(2)?"内伤":"瘀伤"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 280  && random(me->query_skill("strike")) > 300 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 800+random(100),
			"damage": 820+random(20),
			"damage_type": "瘀伤",
			]);
else        if (random(me->query_str()) > 30 && 
            random(level) > 120 &&
            me->query("max_neili") > 3000 &&
            me->query("neili") > 1300 ) {
                me->add("neili", -50);
                return ([
                "action": HIC "$N蹲低身子，两眼微闭，口中咕咕咕的叫了三声，双掌向$n缓缓推出！激得灰泥弥漫，尘土飞扬" NOR,
                "dodge" : 80,
                "parry": 80,
                "damage": 800,
                "force": 850,
                "damage_type": "瘀伤"]);
        }
//	}

	//if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("hmg_dzjm") && me->query_temp("powerup") && random(me->query_skill("force",1)) > 180 && me->query("neili") > 1000 )
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 650+random(100),
			"damage": 620,
			"damage_type": random(2)?"内伤":"瘀伤"
			]);
		else if ( me->query_temp("hmg_dzjm") && random(me->query_skill("force",1)) > 180  && random(me->query_skill("strike",1)) > 180 && me->query("neili") > 1000 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 100,
			"parry": 100,
			"force": 630+random(100),
			"damage": 620+random(20),
			"damage_type": "瘀伤",
			]);
	//}
	else if ( me->query_temp("hmg_dzjm") )
		return reverse_action[random(sizeof(reverse_action))];
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,nlvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);
        nlvl= (int) me->query_skill("hamagong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出!$n头一昏，不知所措 ！\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(3)==0 )
{
        victim->receive_damage("qi", random(nlvl)/2);
        victim->receive_wound("qi", random(nlvl)/2);
 return HIR "$N倒转经脉对着$n张口一咬!$n伤口一凉，鲜血喷出！\n";
}
	if( damage_bonus/2 > victim->query_str() && random(3)==0 ) {
if(me->query_skill("hamagong", 1)>150 && !me->query_temp("weapon"))
{

		victim->receive_wound("qi", (random(nlvl)/2 )+1 );
		return HIM " "+ victim->name()+"喘息未定，又觉一股劲风扑面而来,吐出了一大口鲜血！\n" NOR;

	}
        lvl = me->query_skill("hamagong", 1);

        if (damage_bonus < 50
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon"))
                return 0;

        if (damage_bonus / 6 > victim->query_con() && random(2)==0)
        {
                me->add("neili", -5);
                victim->receive_wound("qi", (random(nlvl)) / 2+1);
                return WHT "$n" WHT "硬承下$N" WHT "一掌，霎时全"
                       "身一颤，经脉受震，喷出一口鲜血！\n" NOR;
        }
}
}
string exert_function_file(string func)
{
        return __DIR__"hamagong/exert/" + func;
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/perform/" + action;
}
mapping curing_msg(object me)
{
        return ([
"apply_short" :me->name()+"用头支在地上，双脚并拢，撑向天空。",
"start_self" :HIW"你倒转身体，以头支地，双脚并拢，撑向天空，运起蛤蟆功逆转心法疗伤。\n"NOR,
"on_self" :HIM"你倒运气息，真气逆走，感觉伤势大有起色。\n"NOR,
"start_other" :HIM""+me->name()+"脸色阴沉，头下脚上倒立着，周身上下散布着一股黑气。\n"NOR,
"finish_self" :HIW"你感到全身真气通畅无阻，怪叫一声，猛得跃起。\n"NOR,
"finish_other" :me->name()+"像蛤蟆一样怪叫一声，突然跃起，黑气也随之渐渐散去。\n",
"unfinish_self" :"你正在逆转真气疗伤，突然感到真气乱窜，吓出一身冷汗，只能停了下来。\n",
"unfinish_other":me->name()+"猛然睁开双眼，缓缓站起，但脸色更加阴沉。\n",
"halt_self" :"你将逆走的真气压回丹田，双脚着地，站了起来。\n",
"halt_other" :me->name() +"将黑气吸回体内，站了起来，伤势似乎看上好了不少。\n",
        ]);
}
