// meng.c ��Ҷ����衸���Ρ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
object weapon;
int count;
weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) 
        && (string)weapon->query("skill_type") != "throwing")
                return notify_fail("�������ֲ���ʹ�á����Ρ���\n");           

        if( (int)me->query_skill("biye-wu", 1) < 60 )
                return notify_fail("��ı�Ҷ����費����죬����ʹ�á����Ρ���\n");
        if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߣ�����ʹ�á����Ρ���\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á����Ρ���\n");

        msg = CYN "$NĬ��ھ���ʹ����Ҷ�����֮�����Ρ�����������������$n��\n"NOR;


        if (random(me->query_skill("force")) > target->query_skill("force")/3 )
        {
                if (!target->is_busy())
                target->start_busy(2);
                damage = (int)me->query_skill("biyun-xinfa", 1);
                
                damage = damage/2 + random(damage)*2+300;
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage/3);
                
                if( damage < 20 )
                        msg += HIY"���$n�ܵ�$N�����������ƺ�һ��������ȥ����ƣ����\n"NOR;
        else if( damage < 40 )
                        msg += HIY"���$n��$N����������ֻ�������з��ƣ�ֻ��ú���Ϣ��Ϣ��\n"NOR;
        else if( damage < 80 )
                        msg += RED"���$n��$N������һ�������������죬��ʶ��ʼģ��������\n"NOR;
                else
                        msg += HIR"���$n��$N������һ����ǰһ�ڣ����㵹���ۿ���Ҫ���������ˣ�\n"NOR;
                
        }
        else 
        {
                        msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_vision(msg, me, target);
        
        count = (int)me->query_skill("biye-wu") / 60 + 2;
   if( count > 6 ) count = 6;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me)) || me->query("neili",1) < 500  || me->query("qi",1) < 200)
   {
  message_combatd(HIG "$N������һ�գ�����λð�Ĳ���ͣס�ˡ�\n" NOR, me);
     break;
   }
  else

  message_combatd(HIG "$N����Ӱ��$n����������� Ư���ķ� ...\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
 COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0); 
      
  me->receive_damage("qi", 20);
  me->add("neili", -50);
 }
        
        me->start_busy(2);

        return 1;
}
