//posui.c �������
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        object weapon;
                int extra;
        object weapon1;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
 return notify_fail("��Ҫ��˭ʩչ��������ա���\n");
    


 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("��ʹ��������!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("��������񹦻�����������\n"); 
        if((int)me->query("neili") < 500 )
                return notify_fail(WHT"����������㡣\n"NOR);

            if(me->query("max_neili") < 1000 || me->query("neili")<500)
   return notify_fail("�������㣬�����޷�����������յ�������\n");
        if((int)me->query("qi") < 200 )
   return notify_fail("������̫�����ˣ��޷�ʩչ��������ա���\n");
      if((int)me->query_skill("zileidao", 1) <200)

   return notify_fail("������׵������ò������죬�޷�ʹ�����С�������ա���\n");
        me->add("neili", -150);
 msg = HIW
 "$N����һ�����б������¶��Ϸ�������������Ļ��������򽫹�ȥ�� 

                ������ ������ ������ ������ 
                ������ ��ת�� ��Ǭ�� ������             
                ������ ������ ������ ������ 


                      �ơ��顤�顤��\n"NOR;

        ap = me->query_skill("zileidao", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1000 ) {
  msg += HIY "$n��æ������������ӹ�������ǵص�һ����\n\n"NOR;
           message_vision(msg, me, target);
   } else {
        if(!target->is_busy()) target->start_busy(2);
                damage = 500+(int)me->query_skill("zileidao",1) *2 +
        (int)me->query("qi") / 300 + random((int)me->query("qi") / 200 ) +
        (int)me->query("jing") / 300 + random((int)me->query("jing") / 200 );
  msg += HIR "\n$n��ʱ����Χ��һƬ�޼ʵ���Ļ�У�\n\n" NOR;
     damage +=random(10);
     if (damage > 6000) damage=6000;
                        target->receive_damage("qi", damage);
                        target->receive_damage("jing", damage);
       target->receive_wound("qi", damage/2);
                        me->improve_skill("zileidao", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}
 weapon1=me->query_temp("weapon"); 

        extra = me->query_skill("zileidao",1);
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",3000);        
 
  if (extra >= 300)
{
  message_vision(HIR"\n
$NĬ�����ף�������������������֣�����"+weapon1->query("name")+HIR"�������Ƶ�ͨ�죬
ͻȻ������⣬�绮����ʵ������ֱ��$nȫ��Ҫ��!\n"NOR, me, target);

        if(!target->is_busy()) target->start_busy(2);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->add("neili", -50);
}
if (extra>= 380)
{
   message_vision(HIR"\n
$nȫ���ʱ��$N�����������˿ڣ�����$n�����мܵ�ʱ��$N����
һ����������һ�����εı�����$n��ȥ��$N˫�ַ��裬������ʩ��
��ʱ�����������б������"NOR, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->add("neili", -50);
}

        me->add_temp("apply/damage",-3000);
        me->add_temp("apply/attack",-200);

        me->start_busy(3);

        return 1;
}
