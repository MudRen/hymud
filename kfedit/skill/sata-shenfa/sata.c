#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$N����һ�ݣ�ʹ��"YEL"����ɽ�ơ�"NOR"���ܿ�����һ�С�\n",
        "$n��һ����$Nʹ��"HIR"���ƻ��ơ�"NOR"һ�����$Nͷ��Խ����\n",
        "$Nһ�����ã�һ��"HIC"���ƺ��ơ�"NOR"�������������Ӱ�Ӷ�û�ˡ�\n",
        "$N����һ�㣬һ��"HIG"�������ơ�"NOR"�ڿն���$n��һ����\n",
        "����$Nʹһ��"HIY"���ƽ��ơ�"NOR"����������Ʈ�˿�ȥ��$n��һ����\n",
        "ֻ��$N����һ�ɼ��磬�������ڷ�������ǡ����������е�"HIW"�������ơ�"NOR"��\n"
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



        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");

        if((int)me->query_skill("taixuan-gong",1) < 50)
                return notify_fail("���̫����������������\n"); 

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
count = (int)me->query_skill("sata-shenfa") / 60 + 2;
if( count > 5 ) count = 5;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N�ľ���һ�ɼ��磬�������ڷ����\n" NOR, me);
     break;
   }
  else

  message_combatd(HIG "$Nһ�������,��$n������������ ...\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
 COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}