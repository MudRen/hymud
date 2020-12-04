// tie@fengyun
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{

        string msg;

        int i, lmt, damage,j ;
        object weapon;
        int ap, dp,qixue,eff_qi,max_qi,qi_pcg;
        
        if( (int)me->query_skill("sword") < 90 ||
            me->query_skill_mapped("sword") != "yujianshu")
                return notify_fail(HIW "你的这门剑法不够！\n"NOR);
        if ((int)me->query("neili",1) < 500)
                return notify_fail("你的内力不够，无法使用「天下有雪」！\n");           

 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("请使用磐石神功!\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("你的磐石神功还不够。。。\n"); 

        if((int)me->query_skill("yujianshu",1) < 150)
                return notify_fail("你的这门武功还不够。。。\n"); 

        weapon = me->query_temp("weapon");
        msg = HIY  "$N长啸一声，剑招顿挟风云之式，剑气猛的暴涨三尺，手中的\n"+ weapon->name()+  "如狂风暴雨般地向$n卷来！\n\n" NOR;
        message_vision(msg,me,target);
                damage = 100+me->query_skill("yujianshu",1) + (int)me->query_skill("panshi-shengong", 1);
                damage = damage - random( target->query_skill("dodge")/3 );
        lmt = random(6)+4;
        		       me->add_temp("apply/attack", 80);    
        me->add_temp("apply/damage", 1800);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIW "$N大喝一声：接第"+chinese_number(i)+"剑！\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -80);    
        me->add_temp("apply/damage", -1800);
//      target->receive_wound("jing", random( damage/20 ));
        target->receive_damage("qi", 20 + random(damage));
        target->receive_wound("qi", 20 + damage);
if ((int)me->query_skill("yujianshu",1)> 380)
{
        message_vision(
                HIW"$N略一提气，运起轻功，拔剑起舞。只见$N足不沾地，手中剑越舞越快，逐渐幻做一团白雾，满堂滚动。\n" NOR, me);
  message_vision(WHT"$N手中宝剑如风般朝$n"WHT"连连刺去，一剑刚落二剑顿起！\n\n"HIC"$n"HIC"被逼得叫苦连连，却躲不开快若无形的剑招!\n"NOR,me,target);
       me->add("neili", -90);
        i = 800+(int)me->query_skill("yujianshu",1)*2;
        j = 800+(int)me->query_skill("yujianshu",1)*3;   
        
        //target->start_busy(random(2));
        target->receive_damage("qi",j,me);
        target->receive_wound("qi", i,me);
        target->add("neili",-j);
     message_vision(WHT"$N轻声吟道：“旧梦与谁同?朔风舞穹空。雪映衬花红，清夜倚熏笼。”\n\n"HIC"$n"HIC"听得一头雾水，以至于忘记身处万分危机之中！\n"NOR,me,target);


}

if ((int)me->query_skill("yujianshu",1)>880)
{
      msg = HIW"\n$N银牙一咬，突然高高纵起，凝聚全身功力，人剑合一，"
                 +"化做一道白光，疾风般扑向$n！\n" NOR;
        ap = me->query_skill("yujianshu", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
                msg += HIW "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
                message_vision(msg, me, target);
         } 
         else {
damage=target->query("max_qi")/2;
if (damage> 15000) damage=15000;
                target->receive_damage("qi",damage,me);
                msg += HIW "$n不料$N如此决绝，为此气势所慑，竟然楞在当地，忘了招架。\n
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target); 
         }
	
}	

        me->add("neili", -280);
        me->start_busy(4);
        return 1;
}

