// aohan-liuejue 傲寒六决 
// 小佳(JIA)  2001.9.26 

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string *act1=({ 
"$N眼露凶光，豁出全身力气将$w使劲砍向$n！", 
WHT"$N"WHT"横刀砍向$n"WHT"，虎虎生威，让人心寒，一招「凉寒一瞥」倒也像模像样！"NOR, 
HIW"$N"HIW"横刀一扫，一股寒气扑面袭来，直劈$n"HIW"！正是傲寒六决之「凉寒一瞥」！"NOR, 
HIW"$N"HIW"猝地把$w"HIW"横挥，寒光一闪，一招「凉寒一瞥」寒绝、霸绝、直截了当地劈向$n"HIW"！"NOR, 
HIW"$N"HIW"猝地把$w"HIW"横刀一扫，简简单单的一刀直可惊天动地，有如狂风暴雨，霸道无匹！\n这一刀刀劲凌厉澎湃，更硬生生把$n"HIW"连连逼向后退，正是傲寒六决之第一决「凉寒一瞥」！"NOR, 
}); 

string *act2=({ 
"$N跳起来用力将$w向$n当头劈下！", 
WHT"$N"WHT"突然跃起，手中$w"WHT"用劲劈向$n"WHT"，似乎是傲寒六决的「冰封三尺」！"NOR, 
HIW"$N"HIW"突然跳到半空，在身子下坠之时$w"HIW"急劈$n"HIW"，一股刀风将$n"HIW"的脸刮得隐隐发痛！"NOR, 
HIW"$N"HIW"突然腾身而起，一招「冰封三尺」，手中$w"HIW"化作一道寒光劈向$n"HIW"！"NOR, 

HIW"$N"HIW"突然腾身而起，手中$w"HIW"赫朝朝$n"HIW"劈下，使的正是傲寒六诀第二诀之「冰封三尺」！\n$n"HIW"但见头上白光闪动，$w"HIW"未至，刀锋寒气已先至，冰封三尺绽放出夺目寒光直逼$n！"NOR, 
}); 

string *act3=({ 
"$N用力将$w向下一挥，砍向$n的$l！", 
RED"$N"RED"面似桃花，婀娜多姿，微微抬起头来朝$n妩媚地一笑！"NOR, 
HIR"$n"HIR"被$N的嫣然一笑迷住了"HIR"，你随之一招「寒雪二月梅」带起一阵刀风，快、狠、准地砍向$n"HIR"！"NOR,  
HIR"$N"HIR"身如疾电挥刀杀下，$w"HIR"在空中划过一道刀光，带着刺骨寒气，横劈$n"HIR"！"NOR, 
HIR"$N"HIR"面似桃花，婀娜多姿，微微抬起头来朝$n妩媚的一笑！$n一楞神之际，却不知已经中了$N的傲寒六诀第三诀之「寒雪二月梅」"HIR"！\n刀势挟着一股香风，扑面而来，霎时满天落花如雨，分向$n"HIR"身上每一关节侵袭！"NOR,
}); 

string *act4=({ 
"$N向后连退了几步，突然又冲了上来一刀砍向$n！", 
MAG"$N连退几步，眼见$n"MAG"跟随而来，突然反手一刀狠狠砍出！"NOR, 
HIM"$N"HIM"抽身回步，反手将$w"HIM"划出一道优美的弧线，一招「桃枝夭夭」急攻$n"HIM"的$l"HIM"！"NOR, 
HIM"$N"HIM"抽身回步，反手将$w"HIM"划出一道优美的弧线，一招「桃枝夭夭」急攻$n"HIM"的$l"HIM"！"NOR, 

HIM"$N"HIM"抽身回步，刀锋一转，使的正是傲寒六诀第四诀之「桃枝夭夭」，横刀扫向$n"HIM"！\n$w"HIM"散发着一般疯狂的光芒，刀招柔若冰雪桃枝，看似无刀，实则刚烈无匹！"NOR, 
}); 

string *act5=({ 
"$N勉强将手支撑于地，双腿紧夹$w挥向$n！", 
YEL"$N"YEL"突然双腿夹刀，双手在地上一撑，运劲劈向$n"YEL"，这招「踏雪寻梅」也有几分貌似！"NOR, 
HIG"$N"HIG"以腿夹刀，飞身而起，使出傲寒六诀第五诀之「踏雪寻梅」，人刀疾飞向$n"HIG"！"NOR, 
HIG"$N"HIG"以腿夹刀，飞身而起，使出傲寒六诀第五诀之「踏雪寻梅」，人刀疾飞向$n"HIG"！"NOR, 
HIG"$N"HIG"飞身跃起，使出傲寒六诀第五诀之「踏雪寻梅」，以腿御刀，刀腿并用，迎异难测！\n$w"HIG"势如破竹地劈出一股森寒无比的气劲，『唰』的一声一股血雾遍洒$n"HIG"的$l"HIG"！"NOR, 
}); 

string *act6=({ 
HIY"$N"HIY"潜运冰心决，心若冰心，以气御刀，$w"HIY"骇然将四周寒气凝聚成一巨大雪刀，狠狠劈下！\n刀势足有毁天灭地的威力，赫然是傲寒六决之最高境界「冷刃冰心」！"NOR, 
HIY"$N"HIY"潜运冰心决，心若冰心，以气御刀，$w"HIY"骇然将四周寒气凝聚成一巨大雪刀，狠狠劈下！\n刀势足有毁天灭地的威力，赫然是傲寒六决之最高境界「冷刃冰心」！"NOR, 
HIY"$N"HIY"潜运冰心决，心若冰心，以气御刀，$w"HIY"骇然将四周寒气凝聚成一巨大雪刀，狠狠劈下！\n刀势足有毁天灭地的威力，赫然是傲寒六决之最高境界「冷刃冰心」！"NOR, 
HIY"$N"HIY"潜运冰心决，心若冰心，以气御刀，$w"HIY"骇然将四周寒气凝聚成一巨大雪刀，狠狠劈下！\n刀势足有毁天灭地的威力，赫然是傲寒六决之最高境界「冷刃冰心」！"NOR, 
HIY"$N"HIY"潜运冰心决，心若冰心，以气御刀，$w"HIY"骇然将四周寒气凝聚成一巨大雪刀，狠狠劈下！\n刀势足有毁天灭地的威力，赫然是傲寒六决之最高境界「冷刃冰心」！"NOR, 
}); 

mapping *action=({ 
(["action" : "", 
"skill_name" : "凉寒一瞥", 
  "extra_damage" : 50, 
"damage_type" : "割伤", 
"lvl" : 0, 
]), 
(["action" : "", 
"skill_name" : "冰封三尺", 
    "extra_damage" : 60, 
"damage_type" : "割伤", 
"lvl" : 1, 
]), 
(["action" : "", 
"skill_name" : "寒雪二月梅",  
   "extra_damage" : 70, 
"damage_type" : "割伤", 
"lvl" : 2, 
]), 
(["action" : "", 
"skill_name" : "桃枝夭夭", 
  "extra_damage" : 80, 
"damage_type" : "割伤", 
"lvl" : 2, 
]), 
(["action" : "", 
"skill_name" : "踏雪寻梅", 
  "extra_damage" : 90, 
"damage" : 0, 
"damage_type" : "割伤", 
"lvl" : 3, 
]), 
(["action" : "", 
  "skill_name" : "冷刃冰心", 
  "extra_damage" : 180, 
"damage" : 100, 
"damage_type" : "割伤", 
"lvl" : 4, 
]), 
}); 

string hit_msg1=HIB"一阵寒气过后，$n登时有如冻在了冰块中一般，全身僵硬，举步唯艰！\n"NOR; 
string hit_msg2=HIB"$n骤觉被刀中寒气一侵，全身登时僵止不动，连血液都被凝固！\n"NOR; 

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); } 

int valid_learn(object me) 
{ 
object ob;
if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");

        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("你的磐石神功修为不够。\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("你的快活十三掌修为不够。\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("你的泰山剑法不够。\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("你的风神诀不够。\n");
        if( me->query_skill("shiba-pan", 1) < 200)
                return notify_fail("你的泰山十八盘不够。\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀。\n");

       if ((int)me->query_skill("blade", 1) >= 100) 
               return 1; 
       else if ((int)me->query_skill("blade", 1) < 100) 
               return notify_fail("你的基本刀法太差了，练不了傲寒六决。\n"); 
} 

int practice_skill(object me) 
{ 
       object weapon; 
if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");
        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("你的磐石神功修为不够。\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("你的快活十三掌修为不够。\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("你的泰山剑法不够。\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("你的风神诀不够。\n");
       if (!objectp(weapon = me->query_temp("weapon")) 
       || (string)weapon->query("skill_type") != "blade") 
               return notify_fail("你使用的武器不对。\n"); 
       if ((int)me->query("qi") < 60) 
               return notify_fail("你的体力不够，练不了傲寒六决。\n"); 
       me->receive_damage("qi", 50); 
       return 1; 
} 

mapping query_action(object me, object weapon) 
{ 
       int i, level,lvl,lvll; 
string *act; 
mapping nac; 
       level   = (int) me->query_skill("aohan-liujue",1); 
lvll   = (int) me->query_skill("aohan-liujue",1); 
if (level<100) lvl=0; 
else if (level<250) lvl=1; 
else if (level<350) lvl=2; 
else if (level<550) lvl=3; 
else lvl=4; 
       for(i = sizeof(action); i > 0; i--) 
               if(level > action[i-1]["lvl"]) 
{ 
        if (level> 300) level=300;
switch(random(6)) 
{ 
case 0:nac=action[0];nac["action"]=act1[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 1:nac=action[1];nac["action"]=act2[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 2:nac=action[2];nac["action"]=act3[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 3:nac=action[3];nac["action"]=act4[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 4:nac=action[4];nac["action"]=act5[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 5: 
if (lvll > 700 && random(3)==0) {nac=action[4];nac["action"]=act6[lvl];nac["damage"]=level+nac["extra_damage"];break;} 
else {nac=action[0];nac["action"]=act1[lvl];nac["damage"]=level;break;} 
} 
return nac; 
} 
} 

mixed hit_ob(object me, object victim, int damage_bonus) 
{ 
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("panshi-shengong",1);
damage= 50+ (int) me->query("neili",1)/20;
damage2=random(me->query_skill("aohan-liujue",1))+50;
if (damage > 1000) damage=1000;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "panshi-shengong")
{
if (victim->query("qi")>= damage )
{
victim->apply_condition("cold_poison",5);
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage/2);
}
        return hit_msg2; 
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("aohan-liujue",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return hit_msg1;
}


} 


string perform_action_file(string action)
{
        return __DIR__"aohan-liujue/" + action;
}




