#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage,damagea,extra,exp;
object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������ɻ�����\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

                
                if(!me->is_fighting())
                return notify_fail("�������ɻ���ֻ����ս����ʹ�ã�\n");
                if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");
                if((int)me->query("neili") < 400 )
                return notify_fail("����������㣡\n");

                if((int)me->query("jing") < 150 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                if((int)me->query_skill("buddhism", 1) < 160)
                return notify_fail("��Ĵ�˷𷨲�����죬ʹ����һ�л������ѣ�\n");                
                if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("����ֻ��ȷ�����������ʹ����һ�л������ѣ�\n");
              

                me->delete("env/brief_message");
                target->delete("env/brief_message");

        exp = (int)me->query("combat_exp"); 
            extra=(int)me->query_skill("lunhui-zhang");
            damagea=random((int)me->query_skill("lunhui-zhang"));
              message_vision(HIR"\n$N����˵��:��Ի�����Ա�ֹ������ɱֹɱ!���ҽ���ʹ�ɱ�䣬����������ͷ�������Щ���֮ͽ��\n"NOR,me,target);
if(random((int)target->query("combat_exp"))/2 < (int)me->query("combat_exp"))
{
              target->receive_damage("qi",damagea);
              target->receive_wound("qi",damagea/2);
              target->receive_damage("jing",damagea/3);
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
                me->add_temp("apply/attack", 200); 
                me->add_temp("apply/damage", 1200); 
                me->add("combat_exp", exp);  
                message_vision(HIY"\n����ѭ������Ӧ��ˬ��\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n�����ֻ֣������©��\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n�������������سɷ�\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n��ת���֣������޳���\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n���ֳ�ת������ң�\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n������ס�����ͼž���\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


                me->add_temp("apply/attack", -200); 
                me->add_temp("apply/damage", -1200); 
                me->add("combat_exp", -exp);  
               damage=(int)me->query_skill("staff")+random((int)me->query_skill("buddhism"));
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIC"\n$n��$N�ĳ���֮�£������Ѿ����˼������磮������\n"NOR,me,target);
              message_vision(HIC"\n$n���������������֪���롣\n"NOR,me,target);
              target->receive_damage("qi",damage,me);
              target->receive_wound("qi",damage/2,me);
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
              me->receive_damage("jing", 30);
              me->add("neili", - 300);
              me->start_busy(3);
return 1;
}

