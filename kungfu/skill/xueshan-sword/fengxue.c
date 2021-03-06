#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object ob;
        object weapon;
        string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        skill = me->query_skill("xueshan-sword",1);
        ob=me->query_temp("weapon");
        if( !target ) target = offensive_target(me); 

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"「风"HIW"雪"HIC"回剑」"NOR+"只能对战斗中的对手使用。\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n"); 

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够，还不能运用"+HIC"「风"HIW"雪"HIC"回剑」"NOR+"。\n");

        if((int)me->query_skill("xueshan-sword",1) < 150)
                return notify_fail("你的雪山剑法不够娴熟，使不出"+HIC"「风"HIW"雪"HIC"回剑」"NOR+"！\n");

        if((int)me->query("neili") < 220)
                return notify_fail("你内力还现在不够。 \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        msg = HIC "$N回剑旋舞，剑势不断加快，剑气呼啸四散，如片片雪花遇风，飘然而出。\n形成一个雪花形旋涡，将$n裹在内里。\n";
        if(random(me->query_skill("sword",1)+me->query_skill("xueshan-sword",1)+me->query_skill("dodge",1)) > ((int)target->query_skill("dodge",1))) {
                msg +=HIG "$n只觉得四周压力越来越大，道道暗流缠绕周身，几乎动弹不得。\n" NOR;
                target->start_busy( (int)me->query_skill("xueshan-sword",1) / 50+2);
                me->add("neili", -100);
        } else {
                msg +=HIR "可是$n运足内力，雪花顿时全部溶解，一片不剩，脱出重围。\n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
if (skill>=300)
{
  msg = HIW 
    "\n$N长啸一声,使出「万梅飘零」,手中兵器疾卷,掀起万朵雪花向前铺天盖地的撒去。\n"
    "在白茫茫的一片中,忽然出现万朵梅花形剑花,穿透雪幕,朝四面八方狂射而出。\n" NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp || random(3)==0)
        {
            if(userp(me))
        msg = HIC 
    "无数梅花光华,幻出道道剑气,将$n全身上下罩得严严实实。$n身在其中,\n"
    "只觉剑光束束,在自己身上丝丝划过,一时全身剧痛,鲜血飞溅得到处都是。如同凌迟之刑,\n"
    "惨不堪言。\n" NOR; 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
target->apply_condition("cold_poison",50);
target->apply_condition("ill_shanghan",50);
target->apply_condition("ice_poison",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);
        }
        else
        {
            if(userp(me))
            msg = "可是$n轻捷地往旁边一闪，避过了这一剑。\n"NOR;
        }
}        
if (skill>=600)
{
	me->add_temp("apply/damage",500);
	if (!target->is_busy()) target->start_busy(2);
weapon=me->query_temp("weapon");
         msg = HIW "天雪九点！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "老枝横斜！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "暗香疏影！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "岭上双梅！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "梅雪争春！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "暗影浮香！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);	
	me->add_temp("apply/damage",-500);
}	


        return 1;
}

