//九天黄泉剑法 BY Cigar 2002.04.19
#include <ansi.h>
inherit SKILL;
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
int yunwu(object me, object victim, object weapon, int damage);
string* skill_head =({
        "$N身形稍退，使出一招 雁回祝融",
        "$N不闪不避，一式 泉鸣芙蓉",
        "$N身形一幌，使出 鹤翔紫盖 ",
        "$N妍然一笑，一式 衡山云雾",
        "$N飞身跃起，使出 石廪书声",
});
string* skill_tail =({
        "，手中$w化为一道无力月光刺向$n的$l。",
        "，手中$w舞出满天剑影罩向$n。",
        "，手中$w不偏一歪，直封$n的$l。",
        "，手中$w如飞，发出点点月光。",
        "，$w从右肩急甩向后，撒出点点微光击向$n$l。",
});

mapping *action = ({
        ([      "name":                 "幻",
                "action":
"$N一抖手中的$w，口中唱诺：蜀道难，难于上青天。瞬间刺出数剑，$n顿时手忙脚乱，分不清虚实",
                "dodge":                10,
                "parry":                20,
                "damage":               335,
                "damage_type":          "刺伤"
        ]),
        
        ([      "name":                 "绕",
                "action":
"$N一剑刺向$n，$n急忙向旁边一闪，\n"
"不料$N一运劲儿，口中吟道：而来四万八千岁，不与秦汉通人烟。手中的$w突然弯了过来，转而刺向$n的$l",
                "dodge":                20,
                "parry":                10,
                "damage":               310,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "缠",
                "action":
"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，嘴中喃喃自语：挥手自兹去，萧萧班马鸣。$N左手剑指已刺向$n的$l",
                "dodge":                20,
                "parry":                20,
                "damage":               315,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "点",
                "action":
"$N一转身，背向$n，低头沉吟：举头望明月，低头思故乡。手中$w从腋下反手刺向$n的$l",
                "dodge":                10,
                "parry":                10,
                "damage":               310,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "劈",
                "action":
"$N举起手中的$w，长啸而歌：飞流直下三千尺，疑是银河落九天。自上而下，劈向$n的$l",
                "dodge":                10,
                "parry":                10,
                "damage":               325,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "砍",
                "action":
"$N身子一侧，手中的$w平着挥出，朗声长吟：醉看风落帽，舞爱月流人。砍向$n的$l",
                "dodge":                15,
                "parry":                15,
                "damage":               315, 
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "刺",
                "action":
"$N向前踏出半步，手中$w中宫直进，低声长吟：红颜弃轩冕，白首卧松云。刺向$n的前心",
                "dodge":                10,
                "parry":                10,
                "damage":               320,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "扑",
                "action":
"$N双脚一顿，低吟道：夫天地者，万物之逆旅。光阴者，百代之过客。身子凌空，头下脚上，手中$w刺向$n的头顶",
                "dodge":                15,
                "parry":                15,
                "damage":               320,
                "damage_type":          "刺伤"
        ]),
   ([   "action":
"$n只觉眼前一闪，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开，一招"+BLINK""+HIM"「九天无恨泣江川」"NOR"已悄然划向$n的后心",
     "dodge":     15,
                "parry":                110,
     "damage":     340,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"飞身跃起，$n抬眼一望，月光失色，但见得$N手中$w舞出满天剑影，"+BLINK""+HIC"[黄泉遮月荒凝神]"NOR"已将$n笼罩",
     "dodge":    15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中$w轻轻一刺，手中$w如幽灵一般,一式"+BLINK""+HIB"[月纹瑕疵掩蝠影]"NOR"无形的点向$n的左肋",
     "dodge":     10,
                "parry":                -5,
     "damage":     335,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w犹似一条柔丝，竟如没半分重量，化成片片雪花，在$n身周飘荡不定，正是一招"+BLINK""+HIW"[风花雪月寒九天]"NOR"",
     "dodge":     10,
                "parry":                5,
    "damage":     350,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"突然之间天地失色，$N身形拖出一道道寒光，使出一招"+BLINK""+HIG"「逐神」"NOR"，$w从上空急甩向后，击向$n$l，正如点点剑影无处不及",
     "dodge":     20,
                "parry":                10,
     "damage":     355,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练衡山剑法。\n");
        if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
                return notify_fail("衡山剑法必须配合回雁心法才能练。\n");

        if ((int)me->query_skill("hengshan-sword", 1) < 220)
                return notify_fail("你的衡山剑法火候太浅。\n");         

   if ((int)me->query_skill("huiyan-xinfa", 1) < 220)
                return notify_fail("你的回雁心法火候太浅。\n");

        if ((int)me->query_skill("luoyan-hand", 1) < 220)
                return notify_fail("你的大落雁手火候太浅。\n");

        if ((int)me->query_skill("qiuyan-nanhui", 1) < 220)
                return notify_fail("你的秋雁南回火候太浅。\n");

        if ((int)me->query_skill("biluo-zhang", 1) < 220)
                return notify_fail("你的碧罗掌火候太浅。\n");           

        if( !(ob = me->query_temp("weapon"))
                || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
                return notify_fail("你的内力或气不够，没有办法练习九天黄泉剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
                return notify_fail("衡山剑法必须配合回雁心法才能练。\n");

        if ((int)me->query_skill("hengshan-sword", 1) < 220)
                return notify_fail("你的衡山剑法火候太浅。\n");         

        if ((int)me->query_skill("huiyan-xinfa", 1) < 220)
                return notify_fail("你的回雁心法火候太浅。\n");
                
        me->receive_damage("qi", 35);
        me->add("neili", -20);
        return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("jiutian-sword",1);     
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("huiyan-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("jiutian-sword",1))+50;

if (damage > 1600) damage=1600;
if ( me->query_skill_mapped("force") == "huiyan-xinfa")
{
        if( random(6)==1 && random(level) > 180)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return HIY "「云雾十三式!!」寒光陡闪，$N猛地反刺中了$n。\n" NOR;
        }
 if (damage_bonus < 60) damage_bonus=60;
        if( random(5)==1 && random(level) > 120)
        {

        victim->receive_wound("qi", damage_bonus );     
        return RED "$N手中的剑越使越快，如梦如幻! 一股鲜血从$n的身上刺出 ！\n" NOR;
  }
}
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "huiyan-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("jiutian-sword",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}




string perform_action_file(string func)
{
return __DIR__"jiutian-sword/" + func;
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

mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = 5;
        int d_e2 = 30;
        int p_e1 = 20;
        int p_e2 = 5;
        int f_e1 = 100;
        int f_e2 = 250;
        int m_e1 = 210;
        int m_e2 = 390;
        int i, lvl, seq, ttl = sizeof(action);
        int level;
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
        if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
        me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 900,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 950,
        "post_action": (: yunwu :),     
        "damage_type":"刺伤"]);
        }



        lvl = (int) me->query_skill("jiutian-sword", 1);
        for(i = ttl; i > 0; i--)
                if(lvl > action[i-1]["lvl"])
                {
                        seq = i; /* 获得招数序号上限 */
                        break;
                }
        seq = random(seq);       /* 选择出手招数序号 */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
                "damage_type" : random(2) ? "割伤" : "刺伤",
        ]);
}
