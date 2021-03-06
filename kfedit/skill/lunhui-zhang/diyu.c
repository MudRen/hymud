#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage,nd;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
        if((int)me->query("max_neili") < 800 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("neili") < 200 )
                return notify_fail("你的内力不足！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        i=(int)me->query_skill("lunhui-zhang",1)+me->query_skill("staff",1)/2;
        j=(int)me->query_skill("lunhui-zhang",1);

        if(i<60 || j<10)        
                return notify_fail("你的轮回杖级别还不够，使用这一招会有困难！\n");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIY"\n$N口诵佛号，将千年修为注入手中"+weapon->name()+NOR+HIY"顿时间霞光四射，照得$n睁不开眼！\n"NOR,me,target);
        message_vision(HIW"\n                    〓〓我入地狱〓〓 \n"NOR,me,target);
        message_vision(HIC"\n我不入地狱，谁入地狱，不惟入地狱，且常住地狱，
不惟常住地狱，而且庄严地狱。弘发‘五愿’，地狱未空，誓不成佛，众
生度尽，方证菩提。\n"NOR,me,target);
                damage=me->query_skill("buddhism") + me->query_skill("staff") + (me->query_skill("lunhui-zhang")*2) ;
        nd=target->query("qi",1)/3;
        if (nd>15000) nd=15000;
        damage=damage+nd;
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) 
        {
if (damage> 60000) damage=60000;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);         
                me->receive_damage("jing", 100+random(50),me);
                me->receive_damage("qi", 100+random(50),me);
                COMBAT_D->report_status(target);
                COMBAT_D->report_status(me);            
                
        }

        me->add("neili",-180);
        me->start_busy(3);
        return 1;
}

