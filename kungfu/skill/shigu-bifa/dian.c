// dian.c ʯ�Ĵ�Ѩ�ʷ����㡹�־�
// Last Modified by sir 11.1.2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "���㡹�־�"
int perform(object me, object target)
{
	object weapon;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "dagger")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	fskill = "wuzheng-xinfa";
	bskill = "shigu-bifa";


	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"����죬ʹ����"+PNAME+"��\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������������ʹ�á��㡹�־���\n");

	msg = HIC"$Nʹ��ʯ�Ĵ�Ѩ�ʷ����㡹�־������������Ӱ����$n�����ȥ�����ź�����������$n��ȫ��ҪѨ��$n�������У�ƴ����ܣ���ʱ�������ҡ�\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P���б�������$p�Ĵ�Ѩ��$pֻ��΢΢һ�飬Ѹ���ж��糣��\n"NOR;
					me->start_busy(2);
			me->add("neili", -50);
		} else {
			msg +=  HIG "���$p��$P���м���Ѩ��������ʧ�룬���ڵ�������֪���Ӧ�ԣ� \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill,1) / 50) + 3);
			me->add("neili", -50);
		}
	} else {
		msg +=HIY"����$p������$P����ͼ������㣬һ������$P�ı�����ȫ��Ӧ�����硣\n" NOR;
		me->start_busy(2);
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);

if (me && target)
	{
me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 900);

	msg = HIY "$Nһ��"HIG"��ָ�㽭ɽ��"NOR"��������$n������Ѩ!" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N��ǰ����һ�����������ս�⣬ʹ��"CYN"����ƿէ�ơ�"NOR"������$n�ĵز�Ѩ! " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N������ҵ�һ�Σ�ʹ��"BLU"������ͻ����"NOR"���ź����������$n������Ѩ! " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "$N����Ծ��һʽ"MAG"����ҫ������"NOR"�����������Ӱ����$n�����ȥ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "Nʹ��һ��"HIW"��ң�����项"NOR"ͦ���й�ֱ�����ʼ��������;��Ȼת�����ϱ���޷��� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -900);
		me->start_busy(2);
}

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч�� /
		���ͶԷ�����

	����Ҫ��
		�����ķ�50��
		ʯ�Ĵ�Ѩ�ʷ�40��
		����300
HELP
	);
	return 1;
}

