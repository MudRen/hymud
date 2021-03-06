#include <combat.h> 
#include <weapon.h> 


inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,busy;    
        int damage,wound;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展朝霞落日?\n");  
        if( !me->is_fighting() )
                return notify_fail("朝霞落日只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("手中无利器怎能画出朝霞落日？\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("你的白云心法还不够。。。\n"); 
        if( (int)me->query_skill("canxin-jian", 1) < 180 ) 
                return notify_fail("你的残心剑法还未练成，不能使用[朝霞落日]！\n"); 
        if (me->query("neili") < 300)
                return notify_fail("你内力不继，难以使出朝霞落日。\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/60;
        message_vision(HIY"\n$N信步于朝霞黄昏之中，眺望雾中西山，脚步轻盈，灵由神生，使出"+HIR"「朝霞落日」"+HIY"一技。\n"NOR,me,target);        
        msg = HIC"\n日，朦胧降于小雾西山，犹有风吹，只为洒脱，衬佳人漫步。\n" NOR;
		        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 2500);
                message_vision(msg + "\n", me, target);
                
                msg = HIC "“亭下花草，万千，袅袅婷婷，雨露知多少，含香含态醉人，暮香深惹情深......”\n" NOR;
                message_vision(msg, me, target);
                target->start_busy(2);
                msg=HIG"$n觉，影动雾稀，日落西山，驻足，叹：“惜哉，惜哉...”"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIG"$n眺，叶落花残，侔憔悴，意：“怜哉，怜哉...”"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"$n忆当年，最爱弄玉团酥，幽卧，孤赏霞中日落，悯：“风亭梦魂，幽意何去，唉...”"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -2500);
      
        
 if ((int)me->query_skill("canxin-jian",1)> 360)
{ 
	if (random(2)==0) target->start_busy(2);
   me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3800);
        message_vision(HIW"\n$N集中精神，施展心剑的「迅雷五剑」，向$n发动会心攻击！\n"NOR,me,target);
        msg= RED"$N手中$w晃动，「白虹贯日」使将出来，剑招奇变横生，$n瞧得心惊神眩，不知$N究竟出了多少招"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=GRN"$N手上$w慢慢点出，突然间在空中一颤，一招「苍松迎客」，剑刃暗发嗡嗡之声，$w来路如鬼如魅，顷刻间竟然已绕到了$n背后"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg="$N$w如云雾变化，正是一招「天绅倒悬」，极尽诡奇之能事，动向无定，不可捉摸，$n觉一阵眼花缭乱，顿感穷於应付！ "NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=BLU"$N突然间身子往斜里窜出，使出「有凤来仪」，听$w陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=MAG"$N全不理会对方攻势来路，使出一招「鹤翔紫盖」，变化莫测地攻向$n，剑势竟无丝毫迹象可寻"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        

        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3800);
}              
        
        me->add("neili", -150);

        me->start_busy(3);
        return 1;  

}