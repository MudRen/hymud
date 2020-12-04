#include <ansi.h>
#include <combat.h> 
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

void attack_1();
void attack_2();
void attack_3();
void finish();
void attack(int n);

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;
        int count;
        int i, attack_time;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (me->query_skill("yinlong-bian",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("��Ĺ��򻹲�����죬����ʹ�÷�����\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return  notify_fail("�������޷�ʹ�÷�����\n");

        if( me->query("neili") < 1500 )
                return notify_fail("�������������\n");


        msg = HIB "ͻȻ֮�䣬" HIB "$N" HIB "����һ��һ�Σ���������,"+ weapon->name() +
              HIB "���Ҽ缱˦��󣬶���"
              HIB "��ͷ����\n" HIB "$n" HIB "���š�" HIB "$N" HIB "������"
              HIB "$n" HIB "���ʮ������,��"+ weapon->name() +
              HIB "˵���㵽��������"
              HIB "��\n������ʸ�ö�������\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 6;
        if (ap / 2 + random(ap * 2) > dp || random(3)==0)
        {
                msg += HIR "���$p" HIR "��$P" HIR
                       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����\n" NOR;
                count = ap / 10;
                if (!target->is_busy()) target->start_busy(3);
                attack_time += random(ap / 50);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���ƺ�����������Ȼ������Ӧ����\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);
        if (attack_time > 9)
                attack_time = 9;

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",3000);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3000);
        //me->start_perform(8,"����");
        msg = HIG "$Nʹ�����������޵ġ�����������һ������ʹ�ĵ�ˮ��©��\n"NOR;

        me->add_temp("apply/dodge",200);
// busy �ڸ��� callout ��������
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("neili", -100);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(3);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(4);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(5);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
      message_vision(HIY"\n$N�������ã��޷�����������\n"NOR, me);
      me->add_temp("apply/dodge",-200);
}

void attack(int n)
{
	object me = this_player();
	object target = offensive_target(me);
	int damage = me->query_skill("yinlong-bian", 1), p;
        object weapon = me->query_temp("weapon");
	string msg, dodge_skill;
        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" )
		return;
	message_vision(HIY"\n$NͻȻ��ջӱ���$n��ȥ��\n"NOR, me, target);
        damage=damage+100;
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
	 {
		message_vision(HIR"���������"+weapon->name()+"������º�$n����һ��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��\n"NOR, me, target);
		damage = damage * n + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
	} else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message_vision(msg, me, target);
	}

}
