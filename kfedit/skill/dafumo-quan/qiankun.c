#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int neili, qi;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ǭ��һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 300 )
                return notify_fail("��Ĵ��ħȭ������죬�޷�ʹ�á�Ǭ��һ������\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("��ľ����湦������죬�޷�ʹ�á�Ǭ��һ������\n");

        if ( (int)me->query("max_neili") < 4000)
                return notify_fail("��������������޷�ʹ�á�Ǭ��һ������\n");
        if ( (int)me->query("neili") < 6000)
                return notify_fail("��������������޷�ʹ�á�Ǭ��һ������\n");
        if (target->query("jiuyin/qiankun"))
                return notify_fail("���Ѿ��������ˣ����Ĺ����ɡ�\n");

        msg = HIY"$NͻȻ�۾�һ��������һ������ʹ��ȫ���������ȭ��$n��ȥ��\n";
        //me->start_perform(6,"��Ǭ��һ����");

	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
                msg += HIR"$nֻ���õ������絶����̴�С�����Ѩ��Ϣ��Ҳ�޷�˳��ͨ�У�\n"NOR;
	        neili = target->query("max_neili")/2;
	        qi = target->query("max_qi")/2;
if (neili>60000) neili=60000;
if (qi>50000) qi=50000;
                target->start_busy(random(4)+1);
                target->set("jiuyin/qiankun",1);
// set for condition
                target->set("qiankun/qi",qi);
                target->set("qiankun/neili",neili);
                target->add("max_qi",-qi);
		target->add("eff_qi",-qi);
                target->add("max_neili",-neili);
                if (target->query("neili")>target->query("max_neili"))
                       target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("force")/50);
		me->add("neili", -100);
        } 
        else {
                msg += HIG"$n���������ң���æ����һ�ԡ�\n" NOR;
		me->add("neili", -100);
        }
        message_vision(msg, me, target);
        me->start_busy(2);

        return 1;
}
