// sixiao.c ������Х

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,ob;
	int i,j,skill,level,damage,dmg;
string msg,dodge_skill,*limbs;
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������Хָ����\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
      return notify_fail("�������ֲ���ʹ�á����־���\n");
      
        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("xuantian-zhi", 1) < 100)
                return notify_fail("�����������ָ���𻹲�����ʹ����һ�л������ѣ�\n");



        weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}	

	me->delete("env/brief_message");
	target->delete("env/brief_message");

                skill = me->query_skill("xuantian-zhi");
if (skill > 500) skill=500;
    me->add_temp("apply/damage",  3000);
    me->add_temp("apply/attack",  skill/2);

	message_vision(RED"\n$N�ſھ���һ����Х�����춯�أ����ҿ��� ʹ��һ�С�������Хָ����\n"NOR, me);
  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
if (random(3)==0 && !target->is_busy()) target->start_busy(3);

	message_vision(RED"\n������Х��һָ����һХ�쳾����"NOR, me);
	me->set("SaneJie", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n������Х�ڶ�ָ������Х��������"NOR, me);
	me->set("SaneJie", 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	message_vision(RED"\n������Х����ָ������Х����٣�"NOR, me);
	me->set("SaneJie", 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n������Х����ָ������Х����"NOR, me);
	me->set("SaneJie", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    me->add_temp("apply/damage",  -3000);
    me->add_temp("apply/attack",  -skill/2);

	me->delete("SaneJie");

        limbs = target->query("limbs");
        level = me->query_skill("xuantian-zhi", 1);
        
         target->start_busy(2);
         msg = HIR"$N���$n�Ĺ��ơ�ͻȻ�������������  !!\n"NOR;
         msg += HIR"����������ָ!!����$n���۱����д�Ѩ �³�һ����Ѫ!!��\n"NOR;
             target->add("qi",-(level+100));
             target->add("eff_qi",-(level+100));
        if (userp(target) && target->query("qi") > 50
        && target->query("eff_qi") > 50)
{
	dmg=target->query("qi")/10;
	if (dmg>100000) dmg=100000;
if (target->query("qi")/12 > 20)
             target->add("qi",-dmg);
if (target->query("eff_qi")/12 > 20)
             target->add("eff_qi",-dmg);
}

msg += damage_msg(damage, "����");
message_vision(msg, me, target);

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);



	me->receive_damage("qi", 100);
	me->add("neili", -100);



	me->start_busy(2);
	return 1;
}
