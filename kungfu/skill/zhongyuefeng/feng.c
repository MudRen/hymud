#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$N����һ����һ�С�ҹ����ӥ�������γ�������ȥ��\n",
        "$N��ʱ���Ѿ�������Ӱ��ԭ���Ǿ������С���ȥ���١���\n",
        "$N�ƺ����Ѿ������ԣ���$n����֮ǰ�����ԡ������ȷɡ���Ծ��֮��\n",
        "$Nһ�С��������������Ȼ��Ч��������$n��\n",
        "$N����һ�����������ұ�ȥ��$n����׷����ֻ��$N�Ѿ�����Ծ����\n"
        "$N��һ�С�������ľ������$n�ֵ��Ǳ�������\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[�������]ֻ����ս����ʹ�á�\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("��ʹ�ú�������!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 50)
                return notify_fail("��ĺ�������������������\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "�������������㡣\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "�����������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"���$P�Լ����˸�ͷ���ۻ���\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
count = (int)me->query_skill("zhongyuefeng") / 50 + 2;
  message_combatd(HIR "$Nһʽ�����������������˷�����ȫ�������ǰһ�ݣ��������硣\n" NOR, me);
if( count > 4 ) count = 4;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIY "$N�������Σ�һ̧һ�� ˲����С�.\n" NOR, me, ob);
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}