// qishang ����
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg,str;
        object weapon;
        int i, j, damage;
            int skill, ap, dp, neili_wound, qi_wound;
       if( !target ) target = me->select_opponent();

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�ô��У�\n");


        if( (int)me->query_skill("qishang-cuff", 1) < 250 )
                return notify_fail("�������ȭ��������죬��û�а취ȭ�����ˡ�\n");

        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("�����Ŀǰ������û�а취������һ�С�\n");

        i=random((int)(me->query_skill("qishang-cuff",1)/50));
        if(i<1) i=1;
        if(i>7) i=7;
if (i < 3 && !userp(me))
{
i=2+random(6);        	
}
if (i >= 1 && me->query("neili")>=800)
{
        msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�����" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
skill = me->query_skill("qishang-cuff",1) + me->query_skill("force",1);
	        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
if( random(ap) > dp || !living(target))
        {
                        me->add("neili",-100);

                msg = HIG "$n��$Nȭ��ɨ�У�ֻ��ȫ������ʧȴ��Ԧ�����⼱к��\n"NOR;
                neili_wound = skill + random(skill * 2);
                neili_wound += me->query("jiali");
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");
                if(target->query("neili")<0)
                        neili_wound = 0;
if (neili_wound <10) neili_wound=10;
if (neili_wound >100000) neili_wound=100000;
                target->add("neili", -neili_wound);
                target->receive_wound("qi", neili_wound);
                target->start_busy(2);
                me->start_busy(2 + random(2));
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
}	


if (i >= 2 && me->query("neili")>=800)
{
        msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�ݸγ���" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);
      ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$nǰ������$Nȫ��һ����ֻ��һ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
                qi_wound = skill + random(skill);
                qi_wound += me->query("jiali");
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");
if (qi_wound <10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;

                target->receive_wound("qi", qi_wound);
                target->start_busy(2);
                me->start_busy(2 + random(2));
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
}

if (i >= 3 && me->query("neili")>=800)
{
        msg = HIY "$N" HIY "ŭ��һ����˫ȭ������ʩ�����С�" HIR "���־�" HIY "����˫ȭѸ���ޱ�"
              "��Ϯ��$n" HIY "��\n" NOR;
      //message_vision(msg, me, target);
      ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
             
        if( random(ap) > dp || !living(target))
        {
                damage =skill + random(skill);

                me->add("neili", -160);
                msg += HIG "ֻ��$P" HIG "��һȭ��$p" HIG"���˳�ȥ�����ص�ˤ�ڵ��ϣ���Ѫ��ֹ��\n" NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";

                me->start_busy(2);
        } else 
        {
                msg += HIC "����$p" HIC "�����мܣ�Ӳ�����ĵ�����$P"
                       HIC "��һ�С�\n"NOR;
                me->add("neili", -120);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}

if (i >= 4 && me->query("neili")>=800)
{
     msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�˷ξ�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$N��ȭ���������ף����족��һ������$n���ϣ�\n$nֻ���ú�����˳����ʱ�Ų�������࣡\n"NOR;
                //dodge_decrease = (int)target->query("apply/dodge") / 10;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";

                target->add_temp("apply/dodge", -(i*10));
                target->start_busy(2);
                me->start_busy(2 );
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
message_vision(msg, me, target);
}

if (i >= 5 && me->query("neili")>=800)
{
       msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "���ľ�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);
                msg = HIG "$N����ȭ������ף�$n����$N��ɽ��ʯ��һȭ����ʱ������𣬲���������У�\n"NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
               
                target->add_temp("apply/attack", -(i*10));
                target->start_busy(2);
                me->start_busy(2);
                
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }
message_vision(msg, me, target);
}

if (i >= 6 && me->query("neili")>=800)
{
       msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "���㱾�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 500;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp || !living(target))
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIC "���$N˫ȭ����ʱ��ȴ���������ޡ�\n$n������ּ䣬�ѱ�$N��������ס������лк����ģ�\n"NOR;
                target->start_busy((int)skill/30);
                me->start_busy(2);
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
}


if (i >= 7 && me->query("neili")>=800)
{
        msg = HIY "$N�����˹���ʹ��������ȭ�����ľ��У�"+chinese_number(i)+"���ޱ�ǿ����������Х������$n���ϸ���ҪѨ��\n"+HIC "$n���ᵤ��֮������������ײ����"+chinese_number(i)+"�ɾ���������\n"NOR;
        if (!(me->query("neili")<0)) me->add("neili",-i*30);
        if ((random(me->query_skill("force")) > target->query_skill("force")/2) || !living(target))
        {
                me->start_busy(1);
                target->start_busy(i);
                
                damage = (int)me->query_skill("cuff")*2;
                damage += me->query("jiali");
                damage += random(damage);
                damage /= 2;
                
                target->receive_damage("qi", (int)((i*(2*damage))/2));
                target->receive_wound("qi", (int)((i*damage)/2));
                if (!(target->query("neili")<0)) target->add("neili",-i*20);
     
                msg += HIY"���$n���ܲ�ס$N��"+chinese_number(i)+"�־������������ص�ײ����"+GRN"\n($n"+HIR"���ܵ�������ʵ���ᡣ"+GRN")\n"NOR;
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "($n"+str+")\n";
        } else 
        {
                me->start_busy(4);
                if (!target->is_busy()) target->start_busy(1);
                msg += CYN"����$pæ��������$P��"+chinese_number(i)+"�־�����������֮�����ڻ�֮���Ρ�\n"NOR;
                if (!(target->query("neili")<0)) target->add("neili",-i*50);
        }
        message_vision(msg, me, target);
}
        return 1;
}


