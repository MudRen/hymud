//Cracked by Kafei
//hengshan.c 恒山神峰剑 by maco

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「恒山神峰」只能对战斗中的对手使用。\n");

        if( me->query_temp("hengshan") )
                return notify_fail("你已经使出「恒山神峰」了！\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何能施展「恒山神峰」？\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("你的轻功修为未到，难以施展「恒山神峰」的变幻之处！\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("你在剑法上的造诣不足以使出「恒山神峰」！\n");

        if( me->query("neili") <= 200 )
                return notify_fail("你的内力不够施展「恒山神峰」！\n");

        skill = me->query_skill("sword");

	if(random(target->query_skill("parry"))>skill) {
        message_vision(HIW "\n$N意欲使出「恒山神峰」，但是$n严加戒备，全身门户，无不守备綦谨，难以奏效！\n" NOR, me, target);
	me->start_busy(2);

	}
	else{
        message_vision(HIG "\n但见寒光陡闪，$N手中"+weapon->query("name")+HIC"越使越快，有如恒山的高低不平的奇峰，正是"+HIR"「恒山神峰」"NOR+HIC"！\n" NOR, me, target);
	if (random(3)==0) target->start_busy(2);
		        		       me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1500);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        		       me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -1500);
        me->set_temp("hengshan", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);
	}
        me->add("neili", -200);
        me->add("jing", -100);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
if (!me) return;
	weapon = me->query_temp("weapon");

        if ( me->query_temp("hengshan")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你手中没有持剑，「恒山神峰」的攻势便即瓦解！\n" NOR);
		me->delete_temp("hengshan");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「恒山神峰」的攻势！\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if ( (int)me->query("neili") < 400  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「恒山神峰」的威力，好收缓剑招。\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "hengshan-jian" ) {
                tell_object(me, "\n你转而施展其他剑法，无法再以「恒山神峰」攻敌！\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「恒山神峰」的攻势。\n\n" NOR);
		me->delete_temp("hengshan");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{
if (!me) return;
        if ( me->query_temp("hengshan") ) {
                message_vision(HIW"\n$N剑招渐缓，已将一套「恒山神峰」使完！\n" NOR, me);
        me->delete_temp("hengshan");
        }
}
