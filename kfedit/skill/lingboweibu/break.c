// break.c ������
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
  if( !target ) target = offensive_target(me);
if( !me->is_fighting() )
      return notify_fail("�������ϡ�ֻ����ս����ʹ�á�\n");
if( (int)me->query("qi") < 100 )
      return notify_fail("�����������\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("�������������\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("�������������\n");
        if((int)me->query_skill("beiming-shengong",1) < 100 && (int)me->query_skill("bahuang-gong", 1)<100)
                return notify_fail(HIY "��ı�ڤ�񹦻�˻�����Ψ�Ҷ�����Ϊ������\n" NOR);

	if((int)me->query_skill("lingboweibu",1) < 50)
		return notify_fail("����貨΢������Ϊ����, ����ʹ����һ���� !\n");
	
	if((int)me->query_skill("dodge") < 50)
		return notify_fail("����Ṧ��Ϊ������ Ŀǰ����ʹ��! \n");

 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ϡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");




        if( me->query("gender") == "Ů��")
               msg = HIW "\n$N" HIW "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ� "
                     "$N" HIW "�����������������ζ�ʱ��ӯ�ޱȣ�"
                     "΢���貨���������ң���ַ��ӵ����쾡����\n" NOR;

        else   msg = HIC "\n$N" HIC "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�                    "
                     "ֻ��$N" HIC "��̬Ʈ�ݣ�Ӱ���ҷɣ����ζ�ʱ��"
                     "ӯ�ޱȣ��������ң���ַ��ӵ����쾡����\n" NOR;

        message_combatd(msg, me, target);

count = (int)me->query_skill("lingboweibu") / 40 + 2;
   if( count > 6 ) count = 6;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N������ٿ��һת������ͣס�˽Ų���\n" NOR, me);
     break;
   }
  else
  message_combatd( MAG "\n$N" MAG "����������ʩչ�����ϣ�������Σ���⽻��!\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -30);
 }
    me->start_busy(2);
    return 1;
}

