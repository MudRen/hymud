// tie@fengyun
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
        int skill;
        int damage, ap, dp, p;
        float at;
        string dodge_skill;        
        
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("longzhua-gong");
       if( (int)me->query_skill("longzhua-gong", 1) < 100 )
		return notify_fail("�����צ���������!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ����ֻ�ܿ���ʹ�á�\n");		
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����צ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//	me->add("force_factor",extra/3);
//	orforce = (int) me->query("force");
//	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ����צ���������µģ���צ�ݣ����μӿ죡\n" NOR;
	message_vision(msg,me,target);
	msg = HIB  "�󹥣���һצ-��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "�ҹ����ڶ�צ---����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "Ծ�𣬵���צ------������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//	me->set("force_factor",0);
//	/me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
	me->start_busy(2);
        me->add("neili", -50);

if (me->query_skill("longzhua-gong",1)>200 && me->query("neili")>500)
{
 msg = HIY "\n$N˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�������Ʈ�ݣ��鶯�쳣����ʱ�����������Ӱ��\n" NOR;
        message_vision(msg, me, target);

        msg = HIR "$nֻ�������ܶ���$N����Ӱ�����ɵû���������\n" NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
	{
		msg +=  HIG "���$p��$P���˸����ֲ���! \n" NOR;
		target->start_busy(5);
			}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	message_combatd(msg, me, target);	
	
}


if (me->query_skill("longzhua-gong",1)>300 && me->query("neili")>500)
{
   msg = MAG "\nֻ��$N����ׯ�ϣ�һʽ��"HIY"�������"MAG"������һ��������Ʈ����ϣ���������ƽ���һ���ھ���������
�ˣ������������Ƶ磬��һ���ĳ�������$n����ʽƽƽ������һ�ɲ��䣬��ȴ���޿ɵ������޿ɱܣ�\n"NOR;
        ap = (int)me->query_skill("longzhua-gong") * (int)me->query("neili") * (int)me->query_str();
        dp = (int)target->query_skill("force", 1) * (int)target->query("neili") * (int)target->query_con();
        ap *= (int)me->query("combat_exp")/200;
        dp *= (int)target->query("combat_exp")/200;    
        ap /= 1000;
        dp /= 1000;

        me->start_busy(3);        
        if(random(ap) > dp/2 || random(3)==0){
                target->start_busy(random(3));
                damage = me->query_skill("yijinjing",1) + me->query_skill("longzhua-gong", 1);
                damage *= 3;
                if(target->query("neili") < 1) at = 5;
                else at = me->query("neili") / target->query("neili");
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                damage -= target->query_temp("apply/armor")*2;
                if (damage < 0) damage = 0;
                if (damage > 5500) damage = 5500;
                damage = damage + random(damage / 2)+100;
                if (target->query_skill_mapped("force") == "yijinjing" &&
                    target->query_skill("yijinjing", 1) > 100){
                      tell_object(me, HIY"\n��֪��һ�ƴ���"+target->name()+"���ϣ�ȴ���罭���뺣������ˮ�齻�ڣ�������ʱ��Ӱ���٣�\n"NOR);
                      msg += "��������Ȼһ�����죬$N�Ѵ�����$n�ؿڣ�ֻ��$p��Ȼȫ��������顣��֪һ�ƹ�ȥ��
$n��¶��ɫ�����ö˶˵�վ�ţ�$Nȴ���������ң�����΢΢������\n";
                      target->start_busy(2);
                      message_vision(msg, me, target);

                      return 1;
                      }
                if ((target->query_skill_mapped("force") == "yijinjing" 
                     || target->query_skill_mapped("force") == "yinyun-ziqi" )
                     && target->query_temp("fanzhen")) 
                        damage /= 2;
                target->add("qi", -damage);
                target->receive_wound("qi", damage/3);
                target->add("neili", -damage/5);
                me->add("combat_exp", (int)me->query_int()*2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                }
        else {
//              msg += CYN"\n$p��æ�������Ծ�����ɣ�����ǿ������������һ����\n"NOR;
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }

        message_vision(msg, me, target);
}	

if (me->query_skill("longzhua-gong",1)>500 && me->query("neili")>500)
{
  damage = (int)me->query_skill("longzhua-gong", 1);
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      
      
        switch(random(4)) {
        case 0:
           { msg = GRN"
$NͻȻ���΢Ц������΢�ţ�����ӿ��һ�ɾ��磬�к���һƬƬ���̵�"CYN"�����ݡ�"GRN"��ֱ��$n����շ�ȥ��\n"NOR;
                damage = damage/3 + random(damage/3);               
                me->set_temp("nl", -120);} break;
          
        case 1:        
          { msg = MAG"
ֻ��$N����ѽ��һ����������ǰ��ȥ��ͻȻһ���������֣��ƿ�֮���м���"WHT"��������"MAG"��$n����ǰ��ȥ��\n"NOR;             
                damage = damage/3 + random(damage/2);                
                me->set_temp("nl", -180);} break;

        case 2:        
          { msg = HIY"
ͻȻ$N˫��Ī��ģ�$n��Ȼ������ǰ��Ӱ��ɽ��������ɽ����������������ɽ��ˮ��
����һ�ж�����$nԶȥ������һ�����˵�"GRN"����ա�"HIY"�����˱Ƕ���������\n"NOR;           
                damage = damage/2 + random(damage/3);                                
                me->set_temp("nl", -220);} break;
        
        case 3:
         { msg = HIW"
ͻȻ$N���һ������ʱ��$nϹ��һ�����飬֮��$N��ü��֮�䲼����һ�㱡˪��
˫Ŀ����ĵ���$n������ɮ��һ��һ���������"MAG"����÷��"HIW"��$n����������\n"NOR;          
                damage = damage/2 + random(damage/2);               
                me->set_temp("nl", -300);} break;
        }
    if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 ||
        random(3)==0)
            {
            	damage=damage+500;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);

                me->delete_temp("nl");
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                } 
            else 
               {       
                me->start_busy(3);

                me->delete_temp("nl");
                message_vision(msg, me, target);               
                msg = CYN" ����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
               }
            message_vision(msg, me, target);	
}		
	return 1;
}
