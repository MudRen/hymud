#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int hellfirewhip,tonsillit,gouhunshu,times,extra,damage;
        string desc_msg="";
        int bellicosity_num,lhb_level;
	int success_adj, damage_adj;
        object weapon;
        int p;
        string msg,dodge_skill;
        
        hellfirewhip = (int)me->query_skill("hellfire-whip", 1);
        tonsillit = (int)me->query_skill("zhanzhuang-gong", 1);
        gouhunshu = (int)me->query_skill("buddhism", 1);
        damage=hellfirewhip;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��׷����ǡ���\n");

        if(!me->is_fighting())
                return notify_fail("��׷����ǡ�ֻ����ս����ʹ�ã�\n");
        	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
        bellicosity_num = (int)me->query("bellicosity");
        
        if( hellfirewhip < 80)
                return notify_fail("��������һ�޼��𻹲������޷�������ǵ����⣡\n");


        
        if( tonsillit < 80)
                return notify_fail("���վ׮����Ϊ�������޷���������\n");
        
        if( gouhunshu < 80)
                return notify_fail("��������ķ����𻹲������޷����˻��ǣ�\n");
                
        //if (bellicosity_num<(tonsillit+gouhunshu)) 
        //        return notify_fail("��ɱ���������뵽��ʳ���ǲ��ɵ�ɪɪ����!");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                      if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
        
        if((int)me->query("qi") < 300 || (int)me->query("jing") <300)
                return notify_fail("���չ˺����Լ��Ļ��ǰɣ�\n");

                
        if( time()-(int)me->query_temp("zhdp_end") < 3 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
          
        message_vision(HIC"\n$NͻȻ����������������ζ������г����ĸ���������б��Գ�����ԩ�껷�ƣ�
  ����ϰϰ��ʹ���������һ��ʧ���Ѿõľ�ѧ**׷�����**��\n"NOR,me);
        extra=(int)(bellicosity_num/30);
        me->add_temp("apply/attack", hellfirewhip);
        me->add_temp("apply/damage", 1200);
        if(!target->is_busy())
                target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/attack", -(hellfirewhip));
        me->add_temp("apply/damage", -(1200));
        if( hellfirewhip > 120 && tonsillit > 120 && gouhunshu > 120 )
        {   
                message_vision(HIR"\n$N��������е��һ𣬲��ɵ���Ѫ��ӿ��ƴ�����һ�ޡ�\n"NOR,me);
 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                message_vision(HIR"\n$N�޷��ƺ��Ѿ����ϣ�ͻȻ��ͷ���һ���һ�$n�������Ҳ�㲻��ȥ�ˡ�\n"NOR,me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);

        }
        if( hellfirewhip > 160 && tonsillit > 160 && gouhunshu > 160 )
        {    
                message_vision(HIR"\n$N�·�����������������������Χ��һ˿��Ц�����һ���������һ����
           �ľ���������ʽ�о��֡�\n"NOR,me);
                me->add_temp("apply/attack",hellfirewhip);
                me->add_temp("apply/damage",1200);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                me->add_temp("apply/attack",-(hellfirewhip));
                me->add_temp("apply/damage",-(1200));
                target->receive_damage("qi",damage*3,me); 
                target->receive_damage("jing",damage,me); 
                target->receive_wound("qi",damage*3,me); 
                target->receive_wound("jing",damage,me); 
        }

      if( hellfirewhip > 260 && tonsillit > 260 && gouhunshu > 260 )
        {   
       msg = MAG "$N�Һ�һ����һ����Ѫ�����գ�����������Ѫһ�ƣ����г���Х������������������������Ϯ$n���ؿ��ߴ���Ѩ��\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("hellfire-whip");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("buddhism", 1)*5);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
		msg=MAG "���������$n�ؿ���������������һ����Ѫ��\n" NOR;
}
else
{
		msg=HIG "����$nһ����Ц������ҡ�Σ����˿�ȥ��\n" NOR; 
}
message_combatd(msg, me,target);		           
}
        message_vision(HIR"\n$N˫Ŀ�����˸��������� ������ȥ���������־͸�����\n"NOR,me);
        if (random(me->query("combat_exp",1)) < target->query("combat_exp",1)/3){

                message_vision(HIR"\n�Է���Ԫ��һ��˿����Ϊ��������\n"NOR,me,target);
                me->start_buzy(3);
        }   
        else 
        {   
                message_vision(HIC"\n$N������䣬$n�����ɢ����������!\n"NOR,me,target);

                target->start_busy(3+random(3));

        }
         me->add("neili", -350);                                
me->start_buzy(2);

        me->set_temp("zhdp_end",time());
        return 1;
}

