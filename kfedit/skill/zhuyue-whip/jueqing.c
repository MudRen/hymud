// writted by fbbz
// 10/2001

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,k,damage_bonus,mystr;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("һ���˾����˭������\n");

        if(!me->is_fighting())
                return notify_fail("�����项ֻ����ս�����ñ��˵��������ˣ�\n");
        

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

                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("��ľ���״̬̫���ˣ�û�˻ῴ�㣡\n");
        if((int)me->query_skill("zhuyue-whip", 1) < 200)
                  return notify_fail("������ű޷���Ϊ������������ֻ��͵͵������ɣ�\n");
               mystr=me->query_str();

              k=(int)me->query_skill("whip");
              damage_bonus=k;
              damage_bonus=200+mystr*(damage_bonus+100+me->query("force_factor"))/200;
        message_vision(HIY"$N�����˺ۣ�ʹ���������޵�������û���ģ��Ҹ���ƴ��! ˵������$n�����������Լ�������!\n"NOR,me,target);
                     
                        if (random((int)me->query("per"))<5 || random((int)target->query("combat_exp")) > ((int)me->query("combat_exp"))) 
                                                    {
//                         msg = "����$p������$P�����������ͼ��Ц��:�ұ������������壬������Σ�\n" NOR;
//		              message_vision(msg, me, target��;
        message_vision(HIB"����$p������$P�����������ͼ��Ц��:�ұ������������壬������Σ�\n"NOR,me,target);

                                }
                                 else {
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 60, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"���$n����һ���������Ŀ���$N��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���驧\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 80, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"���$n��������飬������ͷ��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 120, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"���$n�����Ŀ���$N���޵����ݡ�\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���⩧\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 180, damage_bonus);
			wound=damage-(int)target->query_temp("apply/armor");
			if(damage>0) {
				target->receive_damage("qi", damage,me);
				if(wound>0) target->receive_wound("qi", wound,me);
				msg+=HIB"���$n����������⣬����ͨ�죬������֡�\n" NOR;
                    			}
                            message_vision(msg, me, target);
                                                 COMBAT_D->report_status(target);
                            }
        me->start_busy(2);
        //me->add("qi", -100);
        me->add("neili", -200);
        //me->add("jing",-100);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=(int)me->query_skill("zhuyue-whip", 1)+base_damage+(damage_bonus+random(damage_bonus))/4;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}

