//By exp
//changed by wuyou@sk_xyj 2002-12-6

#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        object ob;              // ���ֵ�����
        int i,attack_time,skill,damage;        

        extra = me->query_skill("sanqing-jian",1);
        if ( extra < 60) 
                return notify_fail("������彣�����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻý���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("��ʹ������ķ�!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 
                
        if( (int)me->query_skill("sword", 1) < 60 )
            return notify_fail("��Ļ�������̫�ͣ�\n");
        if( (int)me->query_skill("force", 1) < 60 )
            return notify_fail("����ڹ�������죬ʹ�����ۻý��ݣ�\n");
        if( (int)me->query("max_neili") < 800 )
            return notify_fail("������������Ϊ���㣬ʹ�����ۻý��ݣ�\n");    
        if( (int)me->query("neili") < 100 )
            return notify_fail("�������������㣬ʹ�����ۻý��ݣ�\n");         


        weapon = me->query_temp("weapon");
        if (extra > 200) extra=200;
        me->add_temp("apply/damage",1800);
        me->add_temp("apply/attack",extra*2);
        message_vision(HIW"$N���е�"+ weapon->name()+  "һ���ʣ��ͻ���һ���⻪����$n��
һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$n
ֻ��������⻪�ݷ�����Լ�ü�޼䣬ȴ�ֲ���ȷ���������
���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY"������ȷʵ����������޴����ڡ�
���Ǿ���$n��ȷ��������ʱ������Ȼ�ֲ����ˡ�"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ��
���������ǣ�ȴ���������磬ȴ�ֱ����Ǻ�������ӽ��漣��
��Ϊ�߶���仯������������$N�������ġ�"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-1800);
       me->add_temp("apply/attack",-extra*2);
       me->add("neili", -100);
       me->start_busy(2);

if (me->query_skill("sanqing-jian",1) > 300 || !userp(me))
{
       msg = HIM "$N������̾,ʹ���ˡ���һ���ķ��项,�����д������־���,��������,���ֿɰ���һ�ֲ���һ����\n";

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
 skill=me->query_skill("sanqing-jian",1);
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIM "�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n\n" NOR;
                        
                        //me->start_busy(1);
                        
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n" NOR;
                         // msg += "\n"YEL"��һ��,������$n�����"+ob->query("name")+"��\n\n"NOR;

                        ob->unequip();
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //me->start_busy(1);
                        
        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!\n"NOR"\n"HIY"���$n������������ע���ܿռ�,������$N�Ľ��⡣\n" NOR;
                //me->start_busy(3);
                message_vision(msg, me, target);

        } 

 me->add("neili", -300);
me->start_busy(2);
}

       return 1;
}

