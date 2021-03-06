#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int hellfirewhip,tonsillit,gouhunshu,times,extra,damage;
        string desc_msg="";
        int bellicosity_num,lhb_level;
	int success_adj, damage_adj;
        object weapon;
        int p;
        string msg,dodge_skill;
        
        hellfirewhip = (int)me->query_skill("hellfire-whip", 1);
        tonsillit = (int)me->query_skill("zhanzhuang-gong", 1);
        gouhunshu = (int)me->query_skill("buddhism", 1);
        damage=hellfirewhip;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「追魂夺魄」？\n");

        if(!me->is_fighting())
                return notify_fail("「追魂夺魄」只能在战斗中使用！\n");
        	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
        bellicosity_num = (int)me->query("bellicosity");
        
        if( hellfirewhip < 80)
                return notify_fail("你的六道烈火鞭级别还不够，无法领悟魂魄的真意！\n");


        
        if( tonsillit < 80)
                return notify_fail("你的站桩功修为不够，无法动人心神！\n");
        
        if( gouhunshu < 80)
                return notify_fail("你的禅宗心法级别还不够，无法勾人魂魄！\n");
                
        //if (bellicosity_num<(tonsillit+gouhunshu)) 
        //        return notify_fail("你杀气不够，想到吸食魂魄不由的瑟瑟发抖!");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                      if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够！\n");
        
        if((int)me->query("qi") < 300 || (int)me->query("jing") <300)
                return notify_fail("先照顾好你自己的魂魄吧！\n");

                
        if( time()-(int)me->query_temp("zhdp_end") < 3 )
                return notify_fail("绝招用多就不灵了！\n");
          
        message_vision(HIC"\n$N突然满面黑气，眼中青光晃动，嘴中长出四个獠牙，手中鞭显出无数冤魂环绕，
  阴风习习，使出了六道烈火鞭失传已久的绝学**追魂夺魄**。\n"NOR,me);
        extra=(int)(bellicosity_num/30);
        me->add_temp("apply/attack", hellfirewhip);
        me->add_temp("apply/damage", 1200);
        if(!target->is_busy())
                target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/attack", -(hellfirewhip));
        me->add_temp("apply/damage", -(1200));
        if( hellfirewhip > 120 && tonsillit > 120 && gouhunshu > 120 )
        {   
                message_vision(HIR"\n$N想起地狱中的烈火，不由的热血上涌，拼命打出一鞭。\n"NOR,me);
 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                message_vision(HIR"\n$N鞭法似乎已经走老，突然鞭头喷出一道烈火，$n无论如何也躲不过去了。\n"NOR,me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);

        }
        if( hellfirewhip > 160 && tonsillit > 160 && gouhunshu > 160 )
        {    
                message_vision(HIR"\n$N仿佛见到无数魂魄缭绕在你的周围，一丝冷笑，大喝一声，六道烈火鞭中
           的精髓在这三式中尽现。\n"NOR,me);
                me->add_temp("apply/attack",hellfirewhip);
                me->add_temp("apply/damage",1200);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                me->add_temp("apply/attack",-(hellfirewhip));
                me->add_temp("apply/damage",-(1200));
                target->receive_damage("qi",damage*3,me); 
                target->receive_damage("jing",damage,me); 
                target->receive_wound("qi",damage*3,me); 
                target->receive_wound("jing",damage,me); 
        }

      if( hellfirewhip > 260 && tonsillit > 260 && gouhunshu > 260 )
        {   
       msg = MAG "$N惨号一声，一口鲜血喷向半空，吃这主人心血一逼，手中长鞭啸声大作，夹着阵阵鬼哭闪电般飞袭$n的胸口七处大穴！\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("hellfire-whip");  //以基本内功和九阳神功的高低，取决杀伤力的大小！
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("buddhism", 1)*5);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
		msg=MAG "结果长鞭在$n胸口三进三出，带出一地鲜血！\n" NOR;
}
else
{
		msg=HIG "但是$n一声轻笑，身形摇晃，避了开去。\n" NOR; 
}
message_combatd(msg, me,target);		           
}
        message_vision(HIR"\n$N双目青光闪烁，冷冷道： 魂魄已去，还不束手就缚！。\n"NOR,me);
        if (random(me->query("combat_exp",1)) < target->query("combat_exp",1)/3){

                message_vision(HIR"\n对方抱元守一，丝毫不为所动！。\n"NOR,me,target);
                me->start_buzy(3);
        }   
        else 
        {   
                message_vision(HIC"\n$N话语刚落，$n魂飞魄散，呆立当场!\n"NOR,me,target);

                target->start_busy(3+random(3));

        }
         me->add("neili", -350);                                
me->start_buzy(2);

        me->set_temp("zhdp_end",time());
        return 1;
}

