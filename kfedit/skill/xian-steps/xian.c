
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N�������ˣ�����ֻ������һת������һ�������$n����ӹ���\n",
	"$n��ǰһ������Ȼ��$N��Ӱ�Ӷ��Ҳ����ˡ�\n��Ȼ��ͷ������һ��ĸ���µ����Ц����\nԭ��$N����һͷ����������ɿ��⻬���ȥ��\n",
	"$N�ҽ�̤�˸��鲽��˫��һ�񣬶�ʱ�˷���𣬾�Ȼ��$nͷ��Խ�˹�ȥ��\n",
	"$N����һ�㣬���η�ҡֱ�ϣ�ȴ�ڰ����һ��ת�ۣ���ƮƮ��������$n���\n",
	"$N���Ų�æ��������������ˮ������һƮ...��һƮ����ܵ�����߿��⡣\n",
	"$N����΢�ʣ�˳��һ�ư�����������֮����\n����մ��$n�����ϵ�һ�������������Եõؽ��仯�⡣\n",
	"$NͻȻ���һ��������������$nһ��֮�䣬Ц�úϲ�£������˿�����\n"
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[��ң�ɲ�]ֻ����ս����ʹ�á�\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "jinghai-force")
                return notify_fail("��ʹ�þ�����!\n");

        if((int)me->query_skill("jinghai-force",1) < 50)
                return notify_fail("��ľ����񹦻�����������\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "�������������㡣\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "�����������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIG+dodge_msg[random(sizeof(dodge_msg))]+NOR;
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
count = (int)me->query_skill("xian-steps") / 60 + 2;
if( count > 5 ) count = 5;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N������������ˮ������һ����硣\n" NOR, me);
     break;
   }
  else

  message_combatd(HIG "$N����΢�ʣ�˳��һ�� ...\n" NOR, me, ob);
 COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }
        return 1;
}
