#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i;
        string str;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("���蹥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("sumi-jian", 1) < 120 )
                return notify_fail("������޽�������̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");
        if( (int)me->query_skill("taixuan-gong", 1) < 120 )
                return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("�������̫ǳ���������ˡ�\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("��������������������ˡ�\n");
         if( (int)me->query("jing") < 100 )
                return notify_fail("��ľ��������������ˡ�\n");

       if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("����ʲôΪ������ʹ���޽�������ô?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "sumi-jian")
                return notify_fail("��ʹ�������޽�������ô?\n");

        if( me->query_temp("ss_feiwu") )
                return notify_fail("���ʹ�꡸���衹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        
        me->add("neili", -100);
        //me->add("jing", -40);
        message_vision(BLU "\n$NͻȻ��Хһ�����ٽ�ͦ�̣��ڰ���л����������⣬����������������������$n��Ϯ��ȥ��\n" NOR,me, target);

        me->set_temp("ss_feiwu", 2); 
	me->add_temp("apply/attack", 90);
me->add_temp("apply/damage", 1000);
if (random(3)==0) target->start_busy(2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        if(me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        
        if(me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);          
        if(me->is_fighting(target)){
             if( random(me->query("combat_exp")) > target->query("combat_exp")/2){
        	       weapon->unequip(); 
                       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                       weapon->wield();
                       me->start_busy(2+random(2));
                       }
                
              else{
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
              me->start_busy(1+random(3));
              }
        }
	me->add_temp("apply/attack", -90);
me->add_temp("apply/damage", -1000);
        me->set_temp("ss_feiwu", 1);      
        i = (int)me->query_skill("sword")/30;
        if( 15 - i <= 4) i = 4;
        call_out("remove_effect", i, me);
        me->start_busy(1);
        
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("ss_feiwu");
        tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����衹�ˡ�\n"NOR); 
}
