// gonggui.c  ͬ���ھ�

#include <ansi.h>
#define XI "��" HIW "������Ϣ" NOR "��"
#define HUI "��" HIW "����" HIR "���" NOR "��"

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        int damage;
        int ap, dp, lvl,j;
         int attack_type;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ͬ���ھ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("kuihua-dafa", 1) < 150 )
                return notify_fail("��Ŀ����󷨲�����죬����ʹ�á�ͬ���ھ�����\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");
               
        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);


        if( (int)me->query("neili") < 300  ) 
                return notify_fail("�������������\n");

        if( (int)me->query_temp("kui_tong") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

if( me->query("eff_qi")<100|| !((int)(me->query("max_qi")/me->query("qi"))>=3.5))
{
        msg = HIR "$N" HIR "���Ӻ������ˣ����ι����쳣����$n"
              HIR "���Ʈ��������\n" NOR;

        ap = me->query_skill("dodge");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                msg += HIR "���$p" HIR "ֻ�ܽ����Ż����������Գ�����\n" NOR;
                target->start_busy(7);

                me->start_busy(1);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "��������û"
                       "���ܵ��κ�Ӱ�졣\n" NOR;
                me->start_busy(2);

        }
        message_vision(msg, me, target);
 msg = HIR "\n$N" HIR "��Хһ������Ȼ������ǰ��һ�о�ֱϮ$n" HIR "Ҫ�����ٶ�֮�죬��"
              "�˼���δ��������δ�š�\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                ap = me->query_skill("kuihua-dafa", 1);
                me->start_busy(2);
                damage=me->query_skill("kuihua-dafa", 1);	
                damage = damage  + random(damage)+100;
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage/2);
                msg +=HIR "��һ���ٶ�֮����ȫ������$n" HIR "������$n" HIR
                                                "��æ�����мܣ����Ǵ���֮�죬���޴Ӷ�����$n" HIR "���"
                                                "һ������Ȼ���С�\n" NOR;
               

        } else
                msg += HIM "$n" HIM "���һ������æ�˺󣬾�Ȼ"
                                "���Ҷ㿪����һ�У�\n" NOR;

        me->add("neili",-200);
        me->start_busy(2);
      message_vision(msg, me, target);        

}
else
{
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
        msg = HIY "$N�����Ƶĳ�������" + HIR "Ψ�ҿ���" +HIY "��$nֻ������ǰһ�����ʺ��ѱ����洩��������" ;
        msg +=  HIW"\nһ��Ѫ����ӿ��������$n��ȫ�������ϣ���\n" NOR;

	message_vision(msg, me, target);

if (target->query("qi") > 300000)
{
target->add("qi",-290000);
target->add("eff_qi",-290000);
}else target->unconcious();
	COMBAT_D->report_status(target);
	} else {
                msg = HIY "$N�����Ƶĳ�������" + HIR "Ψ�ҿ���" +HIY "��$nֻ������ǰһ��������" ;
		msg += HIG"����$p���Ƕ����$P�����һ������\n" NOR;
		me->start_busy(3);
                message_vision(msg, me, target);
	}
	
        me->add_temp("apply/attack", (int)me->query("kuihua-dafa")/2);
        me->add_temp("apply/dodge", -(int)me->query_skill("kuihua-dafa",1)/2);
        me->add_temp("apply/damage",(int)me->query_skill("kuihua-dafa",1)/2);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, (int)me->query_skill("kuihua-dafa",1)/2, (int)me->query_skill("kuihua-dafa",1)/2:), 30);
        me->set_temp("kui_tong", 1);


        me->add("neili", -(int)me->query("neili"));
}
        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
        me->add_temp("apply/attack", - (int)me->query("kuihua-dafa")/2);
        me->add_temp("apply/dodge", (int)me->query_skill("kuihua-dafa",1)/2);
        me->add_temp("apply/damage",-(int)me->query_skill("kuihua-dafa",1)/2);
        me->delete_temp("kui_tong");
        
}

