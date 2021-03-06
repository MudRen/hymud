#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;



int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,busy;  
        int damage;  
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「日落」?\n");
         
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("请使用青冥玄功!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("你的青冥玄功还不够。。。\n"); 
                
        if( !me->is_fighting() )
            return notify_fail("「日落」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("手中无利器怎能画出「日落」？\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        if( (int)me->query_skill("frht-hammer", 1) < 120)
                return notify_fail("你的封日混天锤等级不够，你怎么能使出「日落」。\n");

        if (me->query("neili") < 600)
                return notify_fail("你内力不继，难以使出「日落」。\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/100+1;
message_vision(HIY"\n$N信步于朝霞黄昏之中，眺望雾中西山，脚步轻盈，灵由神生，使出"+HIR"「日落」"+HIY"一技。\n"NOR,me,target);        
           msg = HIC"\n日，朦胧降于小雾西山，犹有风吹，只为洒脱，衬佳人漫步。\n" NOR;

                message_vision(msg + "\n", me, target);
                
        msg = HIC "“亭下花草，万千，袅袅婷婷，雨露知多少，含香含态醉人，暮香深惹情深......”\n" NOR;
                message_vision(msg, me, target);
 me->add_temp("apply/attack", 50); 
  me->add_temp("apply/damage", 2000); 
if (random(3)==0) target->start_busy(3);
 message_vision(HIG"$n觉，影动雾稀，日落西山，驻足，叹：“惜哉，惜哉...”"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIG"$n眺，叶落花残，侔憔悴，意：“怜哉，怜哉...”"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"$n忆当年，最爱弄玉团酥，幽卧，孤赏霞中日落，悯：“风亭梦魂，幽意何去，唉...”"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);



 me->add_temp("apply/attack", -50); 
  me->add_temp("apply/damage", -2000); 
        me->add("neili", -150);
 
 if ((int)me->query_skill("frht-hammer",1)> 600 || !userp(me))
{
       msg =  HIR "$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！！\n" NOR;
        message_combatd(msg, me,target);                
if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong",1)+ (int)me->query_skill("frht-hammer",1);  
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*6);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
                msg=RED "结果一道寒光从$n当头劈过,带出一地鲜血！\n" NOR;
}
else
{
                msg="$n急忙飞身向后跃出数丈，才勉强躲闪过这致命一击！\n" NOR; 
}
message_combatd(msg, me,target);        
        
}         
 
 
        me->start_busy(2);
        return 1;  

}