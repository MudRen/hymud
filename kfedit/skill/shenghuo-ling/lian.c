// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LIAN "「" HIW "敛心令" NOR "」"



inherit F_SSERVER;


string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string final(object me, object target, int damage);

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("shenghuo-ling", 1);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "只能对战斗中的对手使用。\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的兵器不对，不能使用圣火令法之" LIAN "。\n");

        if (skill < 150)
                return notify_fail("你的圣火令法等级不够, 不能使用圣火令法之" LIAN "。\n");

        if (me->query("max_neili") < 500 )
                return notify_fail("你的内力修为不足，不能使用圣火令法之" LIAN "。\n");

        if (me->query("neili") < 300 )
                return notify_fail("你的内力不够，不能使用圣火令法之" LIAN "。\n");

        if (me->query_skill_mapped("sword") != "shenghuo-ling") 
                return notify_fail("你没有激发圣火令法，不能使用圣火令法之" LIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "一个筋斗猛翻至$n" HIW "跟前，陡然使出圣火"
              "令法之敛心令，手中" + weapon->name() + NOR + HIW "忽伸"
              "忽缩，招式诡异无比。\n" NOR;

        damage = me->query_skill("sword");
        
        ap =me->query_skill("sword");
        dp = target->query_skill("dodge");


        if (ap * 11 / 20 + random(ap) > dp || random(3)==0)
        {
                me->add("neili", -50);



       target->receive_wound("qi", (damage*2),me);
       target->receive_damage("jing", damage / 2,me);
       target->receive_wound("jing", damage / 4,me);
       target->start_busy(1);
                msg += HIR "$n" HIR "只见眼前寒光颤动，突"
              "然$N" HIR "双手出现在自己眼前，两处太阳穴顿"
              "时一阵剧痛。\n" NOR;

                       
        }
        else
        {
                me->add("neili", -100);
                msg += CYN "$n" CYN "见眼前寒光颤动，连忙振作精神勉强"
                      "抵挡，向后疾退数步，好不容易闪在了$N" CYN "攻"
                      "击范围之外。\n" NOR;
        }
        
        message_combatd(msg, me, target);
if (me && target)
{
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 500);
message_vision(HIG"\n$N忽然身形一变，只见一大把透骨针，分别袭向$n的七大要穴！\n"NOR,me,target);
msg = HIW"第一枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIM"第二枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = MAG"第三枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = YEL"第四枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIB"第五枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -500);
}
                        me->start_busy(2);
        return 1;
}

