// Last Modified by winder on Sep. 12 2001
// zhuihun.c һ��׷��

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "����׷��"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

        int ap, dp, fp, pp,count;
      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail(PNAME "ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("baniao-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("honghua-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ�컨����ѧ��ʹ���˺컨��ľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
	

	//damage = (int)me->query_skill("force", 1);
	damage = (int)me->query_skill("bainiao-jian", 1);

			
	msg = CYN "$N΢΢һЦ������һ����������Ծ��"+weapon->name()+CYN"���޳�������������$n��\n"NOR;
         damage += 200;
	if (random(me->query_skill("force")) > target->query_skill("force")/3 || random(3)==0)
	{
		target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
		target->start_busy(3);
		//me->add("neili", -200);
		msg += HIR "$nֻ��������ҹĻ������ǵذ�ѹ����һʱ����ǰһ���������������޴��мܣ���\n"NOR;
		//me->start_busy(1);
	} else 
	{
		msg += CYN"����$p�������죬����Ծ����$P�Ľ�����\n"NOR;
		//me->add("neili", -200);
		//me->start_busy(1+random(1));
	}
	message_combatd(msg, me, target);


 
 

         damage = random((int)me->query_skill("bainiao-jian"));
 message_vision(HIC"$Nʹ�����񽣷���Ҫּ�������� �ǳ�����������������������ʽ�ۼ���ѭ��$n��ȥ��\n"NOR,me,target, "");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                target->receive_damege("qi", damage,me);
        target->receive_wound("qi", damage,me);
     message_vision(HIC"$N���������ʹ�����У�������չ.\n"NOR,me,target, "");   





                msg = HIW "$N��Ȼ���б��������е�"+ weapon->query("name")+ HIW"������һ��̫�������зֳ�����������           
         $NĬĬ�������̫�������ǣ�\n"NOR;

                message_vision(msg, me, target);
        
 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "$nֻ������������֮��ֱ�ƹ�������֪����ζ�������ʱ��$N��"+ weapon->query("name")+ HIR"���˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "ֻ��$n�������أ����ɽ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);

                }




                msg = HIW "���������������е�"+ weapon->query("name")+ HIW"�������󣬴��ĸ���������           
         $NĬĬ�����������������\n"NOR;

                message_vision(msg, me, target);

	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "$nһ�����񣬱�$N����޻���֮����\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n����������$N�Ĺ���һһ���⣡\n\n"NOR;
                        message_vision(msg, me, target);

                }





                msg = HIW "�����漴�����仯��Ϊ���ԣ�           
         $NĬĬ����������󻯰��ԣ�\n"NOR;
       
                message_vision(msg, me, target);
        
	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                        msg = HIR "ֻ����Ӱ��Ǭ�������𡢿����ޡ��롢�㡢�Ұ˷�������$n������æ���ң��˸���λ���ܼ�ˣ�\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
                        COMBAT_D->report_status(target, 0);
 
                }
                else
                {
                        msg = HIG "$n���������������׽��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);

                }




                msg = HIW "�����ֽ����϶�Ϊһ���γ�һ��̫����           
         $NĬĬ����������Ժ�̫����\n"NOR;
       
                message_vision(msg, me, target);
        
                	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
                {
                                               msg = HIR "һ���޴��̫����$n���˹�����$n�մ������������̱����˸����ţ�\n\n"NOR;
                        message_vision(msg, me, target);
      damage = me->query_skill("honghua-shengong",1);
       target->receive_damege("qi", damage*3,me);
        target->receive_wound("qi", damage*3,me);
 
                }
                else
                {
                        msg = HIG "$nһ������̫�����Ľ��仯�⣡\n\n"NOR;
                        message_vision(msg, me, target);

                }

      me->add_temp("apply/attack", 180);    
        me->add_temp("apply/damage", 2800);

 if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "$N�ڿ�Ծ�𣬱任���Σ�˲�Ʊ�������λ�����е�"+ weapon->name() +RED"����ɭȻ��������������$n ��\n" NOR, me, target);
        
        msg =  HIC  "���������졹��$N����"+ weapon->name() +HIC"����һ����ֱ��$n��" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIR  "\n�������ɢ����$N����"+ weapon->name() +HIR"��������Ľ���б��$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIY  "\n���������졹��$N����"+ weapon->name() +HIY"��Ҷ���ɨ$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIW  "\n��ʮ����ħ����$N����"+ weapon->name() +HIW"���������$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=MAG  "\n��Ⱥħ���衹��$N����"+ weapon->name() +MAG"Я��������ֱ��$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIY  "\n��������������$N����"+ weapon->name() +HIY"Ѹ�װ����$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIG  "\n�������˼䡹��$N����"+ weapon->name() +HIG"��Ȼ��Ϊһ����������$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIC  "\n��ħӰ��������$N����"+ weapon->name() +HIC"������������$n��"  NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg=HIM  "\n��ħ����Ӱ����$N����"+ weapon->name() +HIM"��Ϊ��ǧ��Ӱ����$n��" NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);


       me->add_temp("apply/attack", -180);    
        me->add_temp("apply/damage", -2800);


me->start_busy(4);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

