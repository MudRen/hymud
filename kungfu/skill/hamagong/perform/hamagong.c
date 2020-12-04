// hama.c ��󡹦

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
 int extra;
        string msg, dodge_skill;

        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("��󡹦����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("hamagong", 1) < 150 )
                return notify_fail("��ĸ���񹦻���������������ʹ�ø����жԵУ�\n");

        if( me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�á���󡹦����\n");

        if ( me->query_skill_mapped("strike") != "hamagong")
                return notify_fail("������Ƚ���󡹦�������Ʒ�֮�в��С�\n");

	if ((int)me->query_skill("hamagong", 1) < 100)
		return notify_fail("��ĸ�󡹦�ڹ���򲻹���\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query_skill("strike", 1) < 100 )
                return notify_fail("����Ʒ�������죬ʹ������󡹦�ľ��У�\n");

        if( me->query_temp("hmg_hama") )
                return notify_fail("���ʹ�꡸��󡹦�����У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
	extra = me->query_skill("hamagong",1) / 10;
	extra += me->query_skill("hamagong",1) /10;        
    if( (int)me->query_skill("hamagong", 1) > 200 )
    {
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2200);
        msg = HIC "��һ���ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "��һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "��һ����" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN "��һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add("neili",-30);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2200);

}
if ((int)me->query_skill("hamagong", 1) > 250 
&&  random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{
	        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2200);
	 msg = RED "�߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("snake_poison",10);
	 msg = RED "��ܶ�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("chanchu_poison",10);
	 msg = RED "�����߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("qx_snake_poison",20);
me->add("neili",-30);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2200);
}
        msg = BLU "\n$N���Ӷ��£�����ƽ�ƶ�����ʹ������$N��ƽ�����ġ���󡹦�����У��Ʒ�ֱ��$n��ȥ��\n"NOR;        
        
        
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3)){                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -100);
                me->add("jing", -10);
                damage = (int)me->query_skill("hamagong", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                if (!userp(me) && damage>3000) damage=3000;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if (!me)
{
        me->delete_temp("hmg_hama");
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("hmg_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target)) 
{
        me->delete_temp("hmg_hama");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 500 )
{
        me->delete_temp("hmg_hama");
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     
}
        msg = BLU "\n$N���ƾ���δ��������Ҳ�����Ƴ����������������󡹦���Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("hamagong", 1) > 199 ){                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -100);
                me->add("jing", -10);                
                damage = (int)me->query_skill("hamagong", 1);                
                damage = damage*2 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                if (!userp(me) && damage>3000) damage=3000;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(2);
                me->add("neili", -100);
                tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if (!me)
{
        me->delete_temp("hmg_hama");
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("hmg_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target))
{
        me->delete_temp("hmg_hama");
              return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 700 )
{
        me->delete_temp("hmg_hama");
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     
}
        msg = BLU "\n$N˫��һ�ǣ�˫���ಢ��ǰ�����Ƴ���$n��ͬ��ǰ��Բ����ȫ�ڡ���󡹦����������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("hamagong", 1) > 249 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -200);
                me->add("jing", -10);                
                damage = (int)me->query_skill("hamagong", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                if (!userp(me) && damage>3000) damage=3000;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", 5, me);
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("hmg_hama");
        tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á���󡹦�������ˡ�\n"NOR); 
}
