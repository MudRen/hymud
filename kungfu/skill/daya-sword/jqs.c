//by dewbaby@sk_sjsh
//�Ž������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
	string msg;
	int extra;
	int i;
	object weapon;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

        weapon = me->query_temp("weapon");

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("daya-sword", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("wuzheng-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ÷ׯ��ѧ��ʹ����÷ׯ�ľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
     
        lvl = me->query_skill("wuyun-jian", 1);
     message_vision(WHT"$N��������ؿ���$n��\n\n"NOR,me,target);
     message_vision(WHT"$N��������ͻȻ����"+ weapon->name() +HIY"��Ϊ�ŵ���ɫ������$n��ȥ��\n"NOR,me, target);
 

        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2800);
        //me->add_temp("apply/sword", 800);

        message_vision(HIY"$N������磬���н���Ӱ�䲻�ϣ�\n"NOR,me,target);
msg = WHT"$n"+WHT"����ӭ������Ľ����Ƶ��������ˣ��ƺ���Ϊ������"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY "$Nҧ�����أ�һ�������˹�����" NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"һ��                  "+BLINK+HIC+"����������"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"����             "+BLINK+WHT+"����������"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"����             "+BLINK+HIB+"����������"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"�Ľ�             "+BLINK+HIW+"�޵�������"NOR; 
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"�彣             "+BLINK+BLU+"�ٱ�Ӱ��Ѱ"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"����             "+BLINK+HIR+"��¥����Ъ"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"�߽�             "+BLINK+HIC+"�����״���"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"�˽�             "+BLINK+HIM+"ȥ�������"NOR;
         COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY"�Ž�             "+BLINK+WHT+"���������"NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);


        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2800);



                msg = HIY "ֻ��$N" HIY "һ�����ȣ�����Ѹ����" + weapon->name() +
                      HIY "�ϲ������£���ʱ�������죬ֻ����࣡���\nһ���ƿ�"
                      "֮�죬һ�����ν������������ֱ��$n" HIY "��ȥ��\n" NOR;


        ap = me->query_skill("force");
        dp = target->query_skill("force");


if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

        {
                
                damage = me->query_skill("daya-sword",1);
                target->receive_damage("qi", damage*5,me);
                target->receive_wound("qi", damage*5,me);
                msg += HIR "$n" HIR "ֻ����$N" HIR "������������"
                                           "������һ��������͸��Ĥ�����ۡ������һ��"
                                           "��Ѫ��\n" NOR;


        } else
        {

                msg += CYN "����$n" CYN "��æ���������Ŭ��ʹ�Լ�"
                       "���������ĸ��ţ����ڻ�������һ�С�\n" NOR;


        }
        message_combatd(msg, me, target);





                msg = HIM "ֻ��$N" HIM "һ����ߣ����ھ��߶�" + weapon->name()
                      + HIM "�������������������Ȼ���죬ֻ����࣡���\nһ���ƿ�"
                      "֮�죬һ�����ν������������ֱ��$n" HIM "��ȥ��\n" NOR;


if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

        {
                
                damage = me->query_skill("daya-sword",1);
                target->receive_damage("qi", damage*5,me);
                target->receive_wound("qi", damage*5,me);
                msg += HIR "$n" HIR "ֻ����$N" HIR "������������"
                       "������һ��������͸��Ĥ�����ۡ������һ��"
                       "��Ѫ��\n";
        } else
        {
                msg += CYN "����$n" CYN "��æ���������Ŭ��ʹ�Լ�"
                       "���������ĸ��ţ����ڻ�������һ�С�\n" NOR;
        }
        message_combatd(msg, me, target);



                msg = HIW "ֻ��$N" HIW "˫Ŀ΢�գ�������" + weapon->name() +
                      HIW "�����Ღ������ʱֻ������࣡��ƿ�֮����������"
                      "��������\n�����ν������������ֱ��$n" HIW "��ȥ��\n" NOR;



if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIR "$p" HIR "ֻ�е�$P" HIR "�������ȣ���ӿ��������"
                       "ʱ������飬����������\n" NOR;
                damage = me->query_skill("wuzheng-xinfa",1);
                target->receive_damage("qi", damage*6,me);
                target->receive_wound("qi", damage*6,me);
                
        } else
        {
                msg += HIC "$n" HIC "ֻ�е�$P" HIC "�������ȣ���ӿ��������"
                       "æ���������С��Ӧ����\n" NOR;

               
        }

        message_combatd(msg, me, target);

        //me->add_temp("apply/sword", -lvl/3);
        me->start_busy(4);
        return 1;
}