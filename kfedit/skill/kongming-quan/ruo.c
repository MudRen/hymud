#include <ansi.h>

#define RUO "��" HIG "��������" NOR "��"
#define PO "��" HIC "���" HIW "��" HIC "��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	int level;
	string msg;
        object weapon;
        int damage;
        int skill;
        string wname;
        int ap, dp;
        
        string *limb, type, result, str;
        level=(int)me->query_skill("kongming-quan",1);

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(RUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("kongming-quan", 1)) < 100)
                return notify_fail("��Ŀ���ȭ������죬����ʩչ" RUO "��\n");


        if ((int)me->query("neili", 1) < 100)
                return notify_fail("�����ڵ�����̫��������ʩչ" RUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = WHT "$N" WHT "ʹ������ȭ��" HIG "��������" NOR + WHT "����˫��"
              "���²�������ת���⣬��ͼ����$n" WHT "�Ĺ��ơ�\n" NOR;

        me->add("neili", -50);
        if (random(level) > (int)target->query_skill("parry", 1) / 3)
        {
		msg += HIR "���$n" HIR "��$N" HIR "��ȭ����ǣ�ƣ��м�"
                       "������ȫȻ�޷�������\n" NOR;
		target->start_busy(level / 16 + 3);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "����ͼ������"
                       "�㣬ȫ��Ӧ�����硣\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
if (skill>300 && me && target)
{
	
        msg = HIC "\n$N���һ����������$n���ϣ�˫��ͬʱ��������һ�С������۶�����\n"NOR;
   if (random(me->query_skill("force")) > target->query_skill("force")/2 || random(3)==0)
        {
                me->start_busy(1);

                damage = (int)me->query_skill("kongming-quan", 1) + (int)me->query_skill("force",1);
                //(����Ƽ���+�����ڹ�)

                damage = damage/2 + random(damage/2)+300 ;

                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->start_busy(3);
                me->add("neili", -100);

                msg += HIR"���$n��$N���������㣬һ��֮�£���Ȼ���˵ֵ���\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);

                msg += CYN"����$pʶ����$P��һ�У�ббһԾ�ܿ���\n"NOR;
		message_combatd(msg, me, target);
        }	
}	
if (skill>500 && me && target)
{
   damage = (int)me->query_skill("kongming-quan", 1)+500;
        damage += random(damage);

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        msg = HIC "\n$N" HIC "˫ĿԲ�������ֶ�Ȼһ����׶�ʱ�ܳ�һ��" NOR + MAG
              "�Ϲ�" HIC "��ֱ��$n" HIC "ǰ�ء�\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "����$P" HIR "�����������Ѹ��֮��"
                                           "��$n" HIR "��αܵã���ʱ���Ͼ�����"
                                           "���ߣ�\n" NOR;
        } else
        {
                msg += CYN "$p" CYN "���Ʋ����æ����ݿ����ߣ��ܿ���$P"
                       CYN "���С�\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        msg += "\n" HIC "������$N" HIC "�������һ̧��ƾ���黮�˵�" HIY "��â" HIC
               "�����϶��·���$n" HIC "�󾱡�\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "ֻ����һ�飬�ѱ�$N" HIR
                                           "���л������У���ʱȫ��̱��Ż��һ����"
                                           "Ѫ��\n" NOR;
        } else
        {
                msg += CYN "����$p" CYN "˿����Ϊ$P"
                       CYN "�����������񵲣����Ƚ���һ�мܿ���\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("force");
        msg += "\n" HIC "���ڴ�ʱ��ȴ��$N" HIC "˫����Ȼ��Ȧ��ƽ�ƶ�������ʱ���"
               HIW "����" HIC "ֱϮ$n" HIC "��\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "��$N" HIR "���͹�֮�£���"
                                           "���������мܣ�������һ����÷���ˤ��"
                                           "��ȥ��\n" NOR;
        } else
        {
                msg += CYN "Ȼ��$p" CYN "�������������һ�񣬱㽫$P"
                       CYN "�����������Ρ�\n" NOR;
        }
        me->start_busy(2);
        message_combatd(msg, me, target);
 

}

if (skill>600 && me && target)
{
    message_vision(HIR "\n$Nŭ��һ�����վ�ȫ����ͻȻ����㹥��ȭ���ơ����������У�\n\n" NOR, me, target);

        me->add_temp("apply/attack",100);
        me->set_temp("lianhuan",1);

        message_vision(HIW"��һ�У�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"�ڶ��У�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-100);

        message_vision( HIC"\n������$NͻȻ�ڿշ���ʹ��һ��ԧ�������ȣ����ȷ�۵糸��������$n\n",me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 || random(2)==0)
        {
                if( ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("cuff") + me->query_skill("force"))*2/3) )
                {
                        message_vision(HIR"ֻ��$Nһ���ҽУ����������������Ŀڡ�����$nһ������ͻȻƽƽ�ɳ����ڵ�һ�죬���������������֮�⣬ֱͦͦ�����ڵ��£���Ҳ������\n\n"NOR, target,target );
                        target->receive_wound("qi", (int)me->query_skill("force")*3, me);
                        target->receive_damage("qi", (int)me->query_skill("force")*3,  me);
                }
                else
                {
                        damage = random(((int)me->query_skill("cuff"))+me->query("jiali"))*( 1 + random(me->query_skill("kongming-quan")*2) ) ;
                        if(damage > 44500) damage = 44500;
                        if(damage < 1300) damage = 1300;

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", (int)me->query_skill("strike"), me);

                        limb = target->query("limbs");
                        type = "����";
                        message_vision(HIY"ֻ��$Nһ���ҽУ���������������$P"+limb[random(sizeof(limb))]+"�������$P��ˤ�˸���ͷ��\n"NOR,target);

                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                me->start_busy(1+random(2));
        }
        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("unarmed")*2/3) && random(5) == 1 )
        {
                message_vision(HIR"$N�;��þ�����������֪�����æ���������$n���˸��գ��װ��Լ����ص���һ�ӡ�\n\n"NOR, target,me );
                //me->receive_damage("qi", 30+random(50),  me);
                me->start_busy(1+random(2));
                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision( HIG"$N�ۼ���һ���������ͣ�����˫��һ�㣬Ծ���ĳߣ��㿪��$n��һ�У�����Ҳ����һ���亹��\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1);
        }

        me->delete_temp("lianhuan");

        me->start_busy( 2);

}	
	return 1;
}
