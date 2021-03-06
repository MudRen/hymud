// bluesea-force.c 南海玄功

#include <ansi.h>
inherit FORCE;

string *dodge_msg = ({
        "$n暗运内力，$N的进攻就如击到气墙上，没有半点效果。\n",
        "$n大喝一声，一股气流直冲而出，硬生生震退了$N。\n",
        "$n身子一转，一股旋风将$N的招数全部化解。\n",
        "$n哼然冷笑，微微移动，内力回旋使$N的进攻差之毫厘。\n",
});



mapping *actionf = ({
([      "action":"$N跨出一步，一指缓缓戳向$n的$l，笼罩了方圆数寸的范围",
        "lvl" : 0,
        "attack": 15,        
        "force" : 200,
        "dodge" : 90,
        "parry" : 88,
        "damage": 170,
        "damage_type":  "刺伤"
]),
([      "action":"$N一声震喝，随即一掌劈出，中途却忽然一指刺向$n的$l",
        "lvl" : 10,
        "force" : 210,
        "attack": 15,
        "dodge" : 110,
        "parry" : 90,
        "damage": 160,
        "damage_type":  "刺伤"
]),
([      "action":"$N疾走数步，左掌掌劈向$n的肩头，右手食却点向$n的$l，",
        "lvl" : 30,
        "force" : 215,
        "attack": 15,
        "dodge" : 85,
        "parry" : 85,
        "damage": 175,
        "damage_type":  "刺伤"
]),
([      "action":"$N深吸一口气，步步进逼，双掌连环劈向$n的$l",
        "lvl" : 50,
        "force" : 220,
        "attack": 14,
        "dodge" : 80,
        "parry" : 90,
        "damage": 180,
        "damage_type":  "瘀伤"
]),
([      "action":"$N身体原地不动，双掌平推，一股掌力凌空奔$n而去",
        "lvl" : 100,
        "force" : 235,
        "attack": 13,
        "dodge" : 80,
        "parry" : 95,
        "damage": 170,
        "damage_type":  "内伤"
]),
([      "action":"$N足下暗和八卦，步法变幻莫测，左右掌连翻出击，攻向$n",
        "lvl" : 200,
        "force" : 200,
        "attack": 15,
        "dodge" : 85,
        "parry" : 115,
        "damage": 165,
        "damage_type":  "震伤"
]),
});

mapping *actionw = ({
([      "action":"$N跨出一步，手中$w缓缓砸向$n，笼罩了方圆数寸的范围",
        "lvl" : 0,
        "force" : 250,
        "attack": 17,
        "dodge" : 10,
        "parry" : 110,
        "damage": 200,
        "damage_type":  "震伤"
]),
([      "action":"$N一声震喝，手中的$w随即横扫$n，中途却忽然刺向$n的$l",
        "lvl" : 30,
        "force" : 260,
        "attack": 16,
        "dodge" : 80,
        "parry" : 110,
        "damage": 220,
        "damage_type":  "刺伤"
]),
([      "action":"$N疾走数步，左掌掌劈向$n的肩头，右手的$w却点向$n的$l，",
        "lvl" : 80,
        "force" : 220,
        "attack": 17,
        "dodge" : 85,
        "parry" : 100,
        "damage": 210,
        "damage_type":  "刺伤"
]),
([      "action":"$N深吸一口气，步步进逼，手中的$w连环劈向$n的$l",
        "lvl" : 150,
        "force" : 225,
        "dodge" : 75,
        "parry" : 120,
        "damage": 205,
        "damage_type":  "瘀伤"
]),
([      "action":"$N身体原地不动，手中的$w一划，一股内力凌空奔$n而去",
        "lvl" : 200,
        "force" : 220,
        "attack": 17,
        "dodge" : 80,
        "parry" : 125,
        "damage": 210,
        "damage_type":  "割伤"
]),
([      "action":"$N足下暗合八卦，步法变幻莫测，手中的$w化作数道光芒，攻向$n",
        "lvl" : 250,
        "force" : 220,
        "attack": 15,
        "dodge" : 60,
        "parry" : 110,
        "damage": 220,
        "damage_type":  "内伤"
]),
});

string *usage_skills = ({ "finger", "strike", "staff", "dodge", "dagger" ,
                          "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_combine(string combo) { return combo=="wai-bagua" ; }


mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

      if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("taixuan-gong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("你不先散了别派内功，怎能学？！\n");

	if( (string)me->query("family/family_name")!="雁荡派")
return notify_fail("这门武功要找雁荡派的落雁老人才能学！\n");


      if (me->query_skill("three-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！三才剑法不足!\n");
      
      if (me->query_skill("blood-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！血衣剑法不足!\n");

      if (me->query_skill("doomsword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！寒天吹血剑法不足!\n");

      if (me->query_skill("fy-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！大旗风云剑不足!\n");

      if (me->query_skill("siqi-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！四奇剑法不足!\n");

      if (me->query_skill("qingpingsword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！清平剑法不足!\n");

      if (me->query_skill("sharen-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！杀人剑法不足!\n");

      if (me->query_skill("feixian-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！飞仙剑法不足!\n");
      
      








	
	return 1; 


}

int practice_skill(object me)
{
        return notify_fail("南海玄功博大精深，无法简单的通过练习进步。\n");
}


int ob_hit(object ob, object me, int damage)
{
        string result;
        int ap, dp, mp;

        if ((int)me->query_skill("bluesea-force", 1) < 200
        ||  ! living(me) || (int)me->query("neili") < 500 
        ||  me->query_skill_mapped("parry") != "bluesea-force"
        || random(2)==0)
                return damage;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("bluesea-force", 1);



        if (ap / 2 + random(ap) < dp && random(2)==0)
        {
                //me->add("neili", -300);
        damage=damage/8;
        if (damage < 10) damage=10;
if (userp(ob) && !ob->is_busy()) ob->start_busy(2);
 if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12> 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}
else {
             ob->add("qi",-500);
             ob->add("eff_qi",-500);
}
                switch (random(3))
                {
                case 0:
                        result = HIB "$N" HIB "默运南海玄功，真气护住全身。$n" HIB
                                            "一招击中$N" HIB "，只觉落手处劲力石沉大海，"
                                            "大感惊讶，连忙退回。 \n" NOR;
                        break;
                case 1:
                        result = HIB "$n" HIB "一招攻出，$N" HIB "怒吼一声，不退"
                                            "反进，巨涛般的气墙竟将$n" HIB "这招逼回。\n" NOR;
                        break;
                default:
                        result = HIB "$N" HIB "全身真气流动，一股罡气护住全身，已将$n" HIB "所"
                                            "有进攻招式挡在罡气之外。\n" NOR;
                        break;
                }
         message_vision(result, me, ob);        
        } 

return damage;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) 
{
        int level   = (int) me->query_skill("bluesea-force",1)/10;
        
        if (me->is_busy()
           || ! living(victim)
           || damage_bonus < 80
           || me->query("neili") < 200
           || me->query_skill("bluesea-force", 1) < 250)
        	return 0;


        if (damage_bonus / 2 > victim->query_con() && random(3)==0)
        {
                me->add("neili", -30);
                if (victim->query("qi",1)> 500)
                victim->receive_wound("qi", ((damage_bonus - 88) / 2+1+level));
                if (victim->query("neili",1)> 500)
                victim->add("neili", -((damage_bonus - random(80)) / 2+1+level));

                return random(2) ? HIR "$N" HIR "灌注全身劲力如南海巨涛般袭向$n" HIR "周身大穴，$n" HIR "根本无法抵挡，立受内伤，鲜血狂吐！\n" NOR:
                                   HIR "$n" HIR "硬接$N" HIR "一招，不想对方内力如海浪般袭来，$n" HIR "猛的吐出一口鲜血，看来已受内伤！\n" NOR;
        }        
}



string perform_action_file(string action)
{
        return __DIR__"bluesea-force/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"bluesea-force/exert/" + action;
}

