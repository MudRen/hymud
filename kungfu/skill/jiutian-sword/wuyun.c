//Cracked by Kafei
//yunwu.c �ٱ�ǧ�ú�ɽ����ʮ��ʽ by maco

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ٱ�ǧ�ú�ɽ����ʮ��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("yunwu") )
                return notify_fail("���Ѿ�ʹ�����ٱ�ǧ�ú�ɽ����ʮ��ʽ���ˣ�\n");

        if (!me->query_temp("weapon"))
                return notify_fail("�������޽��������ʩչ���ٱ�ǧ�ú�ɽ����ʮ��ʽ����\n");
        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽��������ʩչ���ٱ�ǧ�ú�ɽ����ʮ��ʽ����\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("����Ṧ��Ϊδ��������ʩչ���ٱ�ǧ�ú�ɽ����ʮ��ʽ���ı��֮����\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("���ڽ����ϵ����費����ʹ�����ٱ�ǧ�ú�ɽ����ʮ��ʽ����\n");

        if( me->query("neili") <= 200 )
                return notify_fail("�����������ʩչ���ٱ�ǧ�ú�ɽ����ʮ��ʽ����\n");

        skill = me->query_skill("sword");


        msg = HIC
"\n$N��ɫ����,���н�â�ó���ʹ�â����������$n����Ȧȥ����һ�С��������¡�\n" NOR;
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
                message_combatd(msg + "\n", me, target, "");
                msg = HIM "$nֻ�����ɽ�����ס�Լ�,��ʱȫ��һ��,��������!!\n" NOR;
                
                message_combatd(msg, me, target, "");
       target->start_busy(2);
                msg=HIM"��һ����ʽ���һ�����紺���µĺ�¶Ϊ֮�ڻ�����$n��̾��"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIC"�ڶ�����ʽ���һ�����������������ޣ���$n�п���"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"��������ʽ���һ�����ƿں���¶��ȸ�������衢���ۣ���$n���Σ�"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"���Ĺ���ʽ���һ����������ñ���谮�����ˡ���$n��ʹ��"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                 
                msg=HIW"�������ʽ���һ�������������ᣬ���������ơ���$n�Ļţ�"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);                 

        me->add_temp("apply/attack",-200	);
        me->add_temp("apply/damage",-3800);
        message_vision(HIC "\n�������ⶸ����$N����"+weapon->query("name")+HIC"ԽʹԽ�죬������ã����Ǻ�ɽ�ɾ���"+HIW"���ٱ�ǧ�ú�ɽ����ʮ��ʽ��"NOR+HIC"��\n" NOR, me, target);
        me->start_busy(1);
        me->set_temp("yunwu", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);

	
	
	
        me->add("neili", -100);
        //me->add("jing", -100);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
if (!me)
return;
if (!me->query_temp("weapon"))
          {
                tell_object(me, "\n������û�гֽ������ٱ�ǧ�ú�ɽ����ʮ��ʽ���Ĺ��Ʊ㼴�߽⣡\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	weapon = me->query_temp("weapon");

        if ( me->query_temp("yunwu")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n������û�гֽ������ٱ�ǧ�ú�ɽ����ʮ��ʽ���Ĺ��Ʊ㼴�߽⣡\n" NOR);
		me->delete_temp("yunwu");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n���"+weapon->name()+"�ѻ٣��޷��������ٱ�ǧ�ú�ɽ����ʮ��ʽ���Ĺ��ƣ�\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( (int)me->query("neili") < 400  ) {
                tell_object(me, "\n���������̲��㣬���Գ������ٱ�ǧ�ú�ɽ����ʮ��ʽ���������������ջ����С�\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "jiutian-sword" ) {
                tell_object(me, "\n��ת��ʩչ�����������޷����ԡ��ٱ�ǧ�ú�ɽ����ʮ��ʽ�����У�\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n������û�к��˹��У������ջ��ˡ��ٱ�ǧ�ú�ɽ����ʮ��ʽ���Ĺ��ơ�\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{

        if ( me->query_temp("yunwu") ) {
                message_vision(HIW"\n$N���н������ѽ�һ�ס��ٱ�ǧ�ú�ɽ����ʮ��ʽ��ʹ�꣡\n" NOR, me);
        me->delete_temp("yunwu");
        }
}
