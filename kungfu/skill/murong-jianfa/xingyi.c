//������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
                int damage, p;
        object weapon;
        extra = (int)me->query_skill("murong-jianfa",1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("douzhuan-xingyi", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("murong-jianfa", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("shenyuan-gong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	//if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
	//	return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨĽ��������ѧ��ʹ����Ľ�����ҵľ�ѧ֮���裡\n" NOR;
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        message_vision(msg, me, target);    

	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 2800);
        msg = WHT "$n��������ʽ,ͻȻ���д����Լ���\n" NOR;
        message_vision(msg, me, target);    
if (random(3)==0) target->start_busy(3);
	msg =  HIR"��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"ת" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        msg =  HIR"��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
        message_vision(HIM"������$Nʹ��Ľ�ݽ����еľ��Уۿ콣���������$n������һ����\n\n" NOR,me,target);        
	 msg =  RED"Ľ�ݽ���" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIY"�䵱̫����" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIB"������Ӱ��" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shenyuan-gong",1)),me);
	 msg =  HIW"��ɽ���¾Ž�" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);





	me->add_temp("apply/attack", -200);	
	me->add_temp("apply/damage", -2800);
        
        
        message_vision(WHT"$N�������������$n�����˸���æ���ң�\n" NOR,me,target);
        

        msg = HIY "\n��Ȼ���ذ���$Nʹ��$n�ľ��У������������ڼ�������$n��ȥ��\n"NOR;
        if(me->query("neili") < random(target->query("neili"))){
          // me->add("neili", -100);
           target->add("jing", -50);
           target->add("neili", -200);
           msg += HIY"���$p��$P��������һƴ��˫����ûռ��˿���ô���\n"NOR;
           message_vision(msg, me, target);
           return 1;
           }
        if( weapon = target->query_temp("weapon") ){
 if (random(me->query("combat_exp")) >target->query("combat_exp")/3 || random(3)==0)
        {                
     damage = (int)me->query_skill("shenyuan-gong", 1);
         //damage = random(damage)+1000;                
                target->receive_damage("qi", damage*7,me);
                target->receive_wound("qi", damage*7,me);   

            msg += HIR"\n$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ�����\n"NOR;
            message_vision(msg, me, target);
                //(target->query_temp("weapon"))->move(environment(target));
            } 
          else {
            //me->add("neili", -60);
            msg += "$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n";
            message_vision(msg, me, target);
            }        
         }
        else
        {
 if (random(me->query("combat_exp")) >target->query("combat_exp")/3 || random(3)==0)
        {                
                     damage = (int)me->query_skill("shenyuan-gong", 1);
         //damage = random(damage)+1000;                
                target->receive_damage("qi", damage*8,me);
                target->receive_wound("qi", damage*8,me);   

                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                       
        } else 
           {
             //me->add("neili", -180);
             msg += CYN"\n$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n" NOR;
          }
        message_vision(msg, me, target);

        }

 msg = HIW "ֻ��$N" HIW "����һչ������Ȼ��ù����ޱȣ�������ָ��Ȼ��"
              "�������ɽ���ֱϮ$n" HIW "ҪѨ��ȥ��\n" NOR;  

        message_combatd(msg, me, target);
        me->add("apply/attack", 80);
        me->add("apply/damage", 1800);
        msg = MAG "$Nһָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = YEL "$N��ָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = WHT "$N��ָ����$n�Ĵ��Ѩ"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =RED "$N��ָ����$n���Ϲ�Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "$N��ָ����$n����ԨѨ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC "$N��ָ����$n���쾮Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIB "$N��ָ����$n�ļ�ȪѨ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = GRN "$N��ָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        
        me->add("apply/damage", -1800);
        me->add("apply/attack", -80);
me->start_busy(4);
        return 1;
}
