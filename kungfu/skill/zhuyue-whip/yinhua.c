//BY Cigar 2002.01 yinhua.c [����һЦ]
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
//        string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;
        
        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
             return notify_fail(MAG"��ʲô��Ц��ûװ������ʹ������һЦ����\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
             return notify_fail("������һЦ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("zhuyue-whip",1) < 100 )
             return notify_fail(WHT"������±޷�������죬��ʹ����������һЦ����\n"NOR);
        if ((int)me->query("max_neili")<1000)
             return notify_fail(RED"���������Ϊ���㣬�޷����㡸����һЦ����������\n"NOR);
        if ((int)me->query("neili")<500)
        {
               return notify_fail(HIC"����������������û�ܽ�������һЦ��ʹ�꣡\n"NOR);
        }
        

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
        
        msg = HIY "$N�ĳ������������������⣬��ɽ��Ұ������Ĵ���ǧ���ٲݣ�������ϧ"+BLINK""HIR"������һЦ��\n"NOR;
        msg += HIG"�񼡴��䣬���⵭��ױ��һֻ�������ˣ����������С�⡣\n"NOR;
        msg += HIG"���贺�磬�����̸лᣬһ�α������ͣ�����͵������ȥ��\n"NOR;
        msg += HIG"��⻨Ӱ����֦��������Ǳ��²��ƣ��˼���м����硣\n"NOR;
        msg += HIC"��ҹ���裬Ũ˯���оƣ���֬˭���ȵ������������ת�����ʾ����ˣ�֪��֪��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 || random(3)==0)
        {
                me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("whip", 1);
                damage = 300+damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage,me);
                target->receive_wound("jing", damage/3,me);
        msg += HIM"$n�Ŀ���������������������֮׹�䣬����֮������$n�Ĵ���һ�Σ��پ��������顣\n"NOR;
        msg += HIM"$N��"+HIR"������һЦ��"+HIM"���Ѿ�ɢ��$n����������......\n"NOR;
        target->apply_condition("flower_poison",15+random(25) + target->query_condition("flower_poison"));
                me->add("neili", -100);
        } else
        {
               
        msg += HIW"����$n��ϲ���񣬲�����Ծ��վ��$Nһ�ԣ��ֳ���������С�ã����ʹ���˾���\n"NOR;
        msg += HIW"$N����ֱ�������ޱȣ������Ͳ���˾����˾��Ƿ���֮����Ҳ���������ˡ�\n"NOR;
                me->add("neili", -50);
        }
        message_vision(msg, me, target);

  if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4  || random(3)==0) {
         attack_time = random((int)me->query_skill("zhuyue-whip", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2000);
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N�����飬��֫��š����Ȼ�ó��߲���Ӱ��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
                  me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2000);
        
}
me->start_busy(2);
        message_combatd(msg, me, target);
        
        //if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
