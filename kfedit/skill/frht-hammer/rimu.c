// BY cigar 2002.01
 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp,kee_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("hammer",1);
        skill2 = me->query_skill("parry",1);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("���ô�����ô���á���ĺ;���\n");



        if( !me->is_fighting()|| !living(me) )
                return notify_fail("����ĺ;�ֻ����ս����ʹ�á�\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("��ʹ����ڤ����!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("�����ڤ����������������\n"); 


        if( (int)me->query("max_neili") < 800 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("�����ڵ��������㣡\n");

        if( skill < 100)
                return notify_fail("��Ļ���������������! \n");

        if( skill2 < 90)
                return notify_fail("������������! \n");

        if( me->query_skill_mapped("hammer") != "frht-hammer") 
                return notify_fail("�޷�ʹ�á���ĺ;���\n");
 
 msg = HIY "\n$N�ݹ������������������¾��죬�����еء�֮���ƶ�����\n����С���Ǵ���ˣ�ĺ������졣\n\n"NOR;
                message_vision(msg, me, target);
 me->add_temp("apply/attack", 200); 
  me->add_temp("apply/damage", 3000); 

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  me->add_temp("apply/damage", -3000); 
 me->add_temp("apply/attack", -200); 


 msg = HIY "$Ņ������ָ��$n���Ų������ӿ죬��Ѹ�ײ����ڶ�֮��Χ��$n��ת������
\n"HIC"��ʱ��$N���׻��ƿ�硢�������Ѹ��һ���ڿն���
\n\n"HIC"$N�ֳ�"+weapon->query("name")+HIC"ǣ���ſ������ơ����γ�һ���޴��������ס��$n��Χ��һ�С�
\n\n"HIW"          ==== ���¾��죬�����еأ�����ĺ;�����κ� ...�� ====
\n\n"HIY"��ʱ��һ����������"+HIR"���Ρ����"+HIY"�Ļý�֮�У��������������γ�"+HIM"���޿��κλ���ȥ��"+HIY"֮�ơ�\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp",1))+(me->query_str()));
                dp = ((target->query("combat_exp",1))+(target->query_str()));

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp/3 )

                {
 msg = HIR "$n����ڰ��Ļý�������ʧ���Լ�����ʧ�������ϣ������ָп���Ȼ������\n$n�޿��κ�֮�£������Ų���\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 80 + skill + random(skill*2);
if(kee_wound > 38000) kee_wound=38000;
                        if(kee_wound > target->query("qi")) kee_wound = (target->query("qi") + 1);
        target->receive_wound("qi", kee_wound,me);
        target->receive_damage("qi", (kee_wound/2),me);
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(2);
                        me->add("neili",-50);
                }
                else
                {
                        msg = HIG "$n������Χ������һ���������ģ���Цһ�����ӿ�Ų��뿪�����\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(2);
                        me->add("neili",-10);
                }

                return 1;

}


