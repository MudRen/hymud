// dieying.c �ɼ��Ӱ
// Last Modified by sir on 4/25/2001



#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIM "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp,count;
	int skill, neili_wound, qi_wound;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            ((string)weapon->query("skill_type") != "hammer"
            &&  (string)weapon->query("skill_type") != "sword")
            )
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("frht-hammer", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("qingming-xuangong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ�������ѧ��ʹ��������ɵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}





	msg = HIG "$N"HIG"����Ϣ����һʽ���ɼ��Ӱ������"+weapon->name()+HIG "���������$n"HIG"��\n";
	message_combatd(msg, me, target);

	skill = me->query_skill("qingming-xuangong",1);
  dp = target->query_skill("force",1);
	if( dp < 1 ) dp = 1;
//	if( random(skill) > dp/2 ) //��ͬ100������ random(100) > 150/2  �õ�...
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
	
		msg ="$n��ʱ������ǰ��ӰƮ�ɣ�˫������������ȫ������һ���ʹ������һ�㣡\n" NOR;
		qi_wound = 3 * skill;
		//qi_wound = qi_wound/2 + random(qi_wound)+300;

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
	}
	else
	{
		msg = "����$n���ľ�����������Σ�Ծ����Ӱ��\n"NOR;
	}
	message_combatd(msg, me, target);
    msg = HIB"$N��ȻһЦ�����Ϳ�ݾ��׵Ķ�����Ȼ��ø���������������һ˲֮�䣬"+
    "$N���������У������ŷ磬���ﺬ��Ӱ��$nֻ����������ֹͣ�ˣ�\n"NOR;
   me->add_temp("apply/attack",200);
	me->add_temp("apply/damage",2600);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"�ʵ�������"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"��˶��ѣ�"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"�ֻ�������"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"�ߵ�������"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"�����蹵��"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIC"ƽɳ���㣡"NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add_temp("apply/attack",-200);
	me->add_temp("apply/damage",-2600);


	     message_vision(HIY"$N��ָ$n�ߺ޵��������Ҳ��ʶ���С�����ԡ���һ��˵�գ�$N���˵���������ģ�ʹ�������츲�ء���\n"NOR,me,target);
                


       
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
{     
        
         message_vision(HIR"ֻ��$nӲ�����Ľ�ס$N�⼼���У��ٸк�ͷһ��[��]��һ���³�һ����Ѫ��\n"NOR,me, target);  
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*3,me);
		target->receive_wound("qi",damage*3,me);
}
         else  {message_vision(HIC"$Nʶ�ƴ��У����˵����������Ӳ�Ӵ˾��У�\n"NOR, target);
                
               }

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
        {
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*3,me);
		target->receive_wound("qi",damage*3,me);
             }
         else  {message_vision(HIC"$Nʶ�ƴ��У����˵����������Ӳ�Ӵ˾��У�\n"NOR, target);
                
               }
          
msg = HIG "$N"HIG"�͵�һ������һ����ת��$n"HIG"���������$n"HIG"����ӡ����ȥ��\n"NOR;

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*4,me);
		target->receive_wound("qi",damage*4,me);
msg +=HIR"ֻ��$nӲ�����Ľ�ס$N�⼼���У�[��]��һ���³�һ����Ѫ��\n";  
	} else
	{

		msg += HIY"����$pҲ����ת���ܿ��˺���Ҫ����\n"NOR;

	}
	message_combatd(msg, me, target);


          
 msg = RED"$N�����㷴�߶���ֱ��$n������������$n�˿�վ�ȣ������������ߣ���$n�ߵ�һʱ�޷����֣�\n"NOR;
         msg += RED"��������!!����$N��Ӱ���ε��߳����ţ�$n�³�һ����Ѫ!!��\n"NOR;

        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
                damage = me->query_skill("frht-hammer",1);
                target->receive_damage("qi",damage*4,me);
		target->receive_wound("qi",damage*4,me);
msg +=HIR"ֻ��$nӲ�����Ľ�ס$N�⼼���У�[��]��һ���³�һ����Ѫ��\n";  
	} else
	{

		msg += HIY"����$pҲ����ת���ܿ�������Ҫ����\n"NOR;

	}
	message_combatd(msg, me, target);
     

me->start_busy(3);
	return 1;
}

