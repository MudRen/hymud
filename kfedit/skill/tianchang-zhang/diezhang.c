// diezhang.c �쳤���� 

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "���쳤���ơ�"

int perform(object me, object target)
{
	string msg,msg2, *limbs;
	int p,count, damage = 0;
	int arg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
	if( me->query_temp("weapon") )
		return notify_fail("ֻ�п��ֲ���ʩչ���쳤���ơ���\n");

	fskill = "baiyun-xinfa";
	bskill = "strike";


	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"������죬����ʹ��"+PNAME+"��\n");

	arg =(int)(me->query_skill(bskill, 1) / 30);

	if( arg <= 1 )
		return notify_fail("����Ҫ�����вſ���ɡ��쳤���ơ���\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("��������Ϊ����������ʹ�á��쳤���ơ���\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("����������̫��������ʹ�á��쳤���ơ���\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");
if (arg>9) arg=9;
	message_combatd(HIG"$N����һ������һ�����ȣ���������"+ chinese_number(arg) +"�ƣ���������ǰ�У�����������һ������$n��\n\n"NOR, me, target);
	if( random(me->query("combat_exp",1)) > target->query("combat_exp",1)/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			msg2=HIC "$N����" HIC "��"+(count+1)+"�ƣ�\n" NOR;
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg2);
			//message_combatd( replace_string( SKILL_D("tianchang-zhang")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "��\n\n", me, target);
			//damage = damage+100+random(100);
		}
		damage = (500 + me->query("jiali")/100) * damage / 2;
	if (damage > 39999) damage=39999;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);	
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";

                        msg +=HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� \n"
                                           NOR;
		me->add("neili", -30 * arg/2);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(3);
		me->add("neili", -300);
		target->add("neili", -100);
		msg =HIY"\n$n���ͼ��ˣ�˳���Ʒ����һ�����㿪���⹥����\n" NOR;
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˵���Ѫ����ʹ��������

	����Ҫ��
		�쳤�Ʒ�100��
		�����Ʒ�100��
		�����ķ�140��		
		����1500		
HELP
	);
	return 1;
}                                                                                                                                                                                                 