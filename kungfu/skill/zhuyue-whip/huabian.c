//BY Cigar 2002.01 huabian.c <����>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


void huabian_ok(object);

int perform(object me, object target)
{
        int damage;
        object weapon;
 string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("���»���С�������Թ��\n");
        if(!me->is_fighting())
                return notify_fail("�����䡹ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");
          if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 150 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("zhuyue-whip", 1) < 100)
                return notify_fail("������±޷�����������ʹ����һ�л������ѣ�\n");

     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("��ʹ�ñ����ķ�!\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("��ı����ķ�������������\n"); 


        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N���ű�غ������ŵĻ��䣬�鵽һ����Ȼ������˳��������"+HIR""BLINK"�ֻ֡���֡�"NOR""+HIW"���Ĳ���......\n"NOR,me,target);
message_vision(HIG"\n            ���˼仨������ȥ���ģ���ҩ���꣬��Ȼ��̬���㡱��\n"NOR,me,target);
message_vision(HIG"\n            ��������£���ռ�������������㣬�û�ǧ����֦����\n"NOR,me,target);
message_vision(HIG"\n            ���˲��淼�����ﵱ���������ᢣ��������ƻ��á���\n"NOR,me,target);
message_vision(HIG"\n            ���������꣬���潻�࣬�����������վƷ�ͤ�λꡱ��\n"NOR,me,target);
message_vision(HIC"\n������Ⱦ¶�����䵱�꣬���޴���ޣ�ҹ�˯���㣬���鷼�����£��ʣ�"+HIR"��������Ϊ���"+HIC"��\n"NOR,me,target);
              damage=200+(int)me->query_skill("parry")+random((int)me->query_skill("whip"));
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{
              message_vision(HIW"\n$n��ǰ��ػ������涷�ޣ�������˳������������Ե��������飬�ٸ��������ᡣ\n"NOR,me,target);
             target->receive_damage("qi",damage,me);
              target->receive_wound("qi",damage,me);
             target->receive_damage("jing",damage,me);
              target->receive_wound("jing",damage,me);
                target->start_busy(random(2));
             COMBAT_D->report_status(target);
}
else {
  message_vision(HIY"\n$n��ƽ���ͣ���ϥ�����������ͳ��������ƣ����Ŵ���˾���������������\n"NOR,me,target);
                target->start_busy(1);
             }

 if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 || random(3)==0) {
         attack_time = random((int)me->query_skill("zhuyue-whip", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                       me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2000);
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N���һЦ�����˷�����һ�޴�� ���ξ���$nƮ������\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
                                               me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2000);
        me->start_busy(2);
}
if (me && target && msg)  message_combatd(msg, me, target);
me->start_busy(3);
        //me->receive_damage("jing", 50);
        me->add("neili", -100);
        me->set_temp("no_huabian",1);
                call_out("huabian_ok",1+random(2),me);


return 1;
}

void huabian_ok(object me)
{
if (!me) return;
      me->delete_temp("no_huabian");
}
