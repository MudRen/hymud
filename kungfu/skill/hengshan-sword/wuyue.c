// feilong.c ��ɽ�����������������ɽ���

#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIM "������һ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp,count;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
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

       if( !wizardp(me) &&(int)me->query_skill("hengshan-sword", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("huiyan-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "huiyan-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ����������ѧ��ʹ�����������ɵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}



	message_combatd(BLU"$N"BLU"ͻȻ��Хһ�� ��ɽ���������������������ٽ�ͦ�̣��ڰ���л����������⣬����������������������$n"BLU"��Ϯ��ȥ��\n" NOR,me, target);

	me->add_temp("apply/attack", 200);
	me->add_temp("apply/damage", 3000);
	for(count=0;count<3;count++)
	{
		        msg =  HIW "$N���һ�����ӵ�"+chinese_number(count+1)+"������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
target->receive_wound("qi",(me->query_skill("sword")+random(100))*3,me);
	me->add_temp("apply/attack", -200);
	me->add_temp("apply/damage", -3000);


        message_vision(HIG "�������ⶸ������ɽ���� $N���г���ԽʹԽ�죬�����ɽ�ĸߵͲ�ƽ����壬����"+HIR"����ɽ��塹"NOR+HIC"��\n" NOR, me, target);
	me->add_temp("apply/attack", 200);    
        me->add_temp("apply/damage", 3000);
                target->receive_wound("qi",(me->query_skill("sword")+random(100))*3,me);
	for(count=0;count<3;count++)
	{
		        msg =  HIW "$N���һ������â����"+chinese_number(count+1)+"�壡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -200);    
        me->add_temp("apply/damage", -3000);


	msg = CYN "$Nʹ����̩ɽ������̩ɽʮ���̽���֮����ʽ��һ�ѽ�����ʮ�˵���Ӱ��\n";

	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
		target->receive_damage("qi",me->query_skill("sword")*3,me);
		target->receive_wound("qi",me->query_skill("sword")*3,me);
                msg +=HIR "$n" HIR "��ܲ�������$N"
                                           HIR "��һ���̵ÿ�����Ѫ���������ˡ�\n" NOR;

	} else
	{
		msg += HIC"����$n������$N�Ľ��У�һš��Ծ���˽�Ӱ��\n" NOR;
		msg += HIY"$Nȴһ��ʧȥƽ�⣬�������˱�����\n" NOR;

	}
	 message_combatd(msg, me, target);


	msg = HIC"$N"HIC"һ����Х����ɽ���� ����������һʽ���ط����㡹��"+weapon->name()+HIC"�������磬˲����ס$n"HIC"ȫ�������Ѩ��\n��Ӱ�У�ֻ��$N΢һ�������ַ�ת��������"+weapon->name()+"ͻȻ���϶��´̳���ֱָ$n"HIC"����Ҫ�� \n" NOR;
	message_combatd(msg, me, target);



	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
	{
		msg = HIY"$n��ʱ������ǰ���������˫��������������֪����һ���ʹ������һ�㣡\n" NOR;
target->receive_damage("qi",me->query_skill("sword")*3,me);
target->receive_wound("qi",me->query_skill("sword")*3,me);
	}
	else
	{
		msg =HIW"����$n�����������ֽ�$N������Ʋ��һ�ߡ�\n"NOR;
	}

        ap = me->query_skill("force")+150;
        dp = target->query_skill("dodge");
        fp = target->query_skill("force");
        pp = target->query_skill("parry");

        message_vision(HIW "\n$N" HIW "��Хһ������ɽ���� ����" + weapon->name() + HIW "�漴��ͣת������ӿ��"
                        "�������ǻ�ɽ���ھ�����" HIM "�����������ɽ�" HIW "��������" + weapon->name() + HIW 
                        "\n����ͻ�䣬һ����ʱ��Ϊ������Ϯ��$n" HIW "����\n" NOR, me, target);        

        msg = HIM "$N" HIM "������ȫ���˵��˽��ϣ�����һ������ͷֱ����\n" NOR;
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
{
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
                msg +=HIR "$n" HIR "��æ���ˣ���Ȼ��ܲ�������$N"
                                           HIR "��һ����ÿ�����Ѫ���������ˡ�\n" NOR;
 }               
        else
        {
msg += CYN "$n" CYN "б��������\n" NOR;
        }

        msg += HIM "\n$N" HIM "Ȧת" + weapon->name() + HIM "���������������ƻֺ룬�����ݺᣬ���˷�����˼��\n" NOR;
       if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);

                msg +=HIR "�������Ƶ���켰��$n" HIR "�������ü���"
                                           "���мܣ�ֻ��$N" HIR "����������$n"
                                           HIR "������ʱ��Ѫ���죡\n" NOR;
        }
        else
              msg += CYN "$n" CYN "����ӽ���Խ����\n" NOR;
  
        msg += HIM "\n$N" HIM "�������ã�����$p" HIM "���ģ�����֮�죬��λ֮׼����������δ�š�\n" NOR;
        if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
 
  
          {
                damage = ap + random(ap / 2)+100;
                target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);

                msg +=HIR "$n" HIR "���ڿ��У��������ü����У�ֻ��$N"
                                           HIR "�˽��ӹ���$n" HIR "�����Һ�����Ѫ���·ɽ���\n" NOR;
  
        }
else
                msg += CYN "$n" CYN "���ڿ��У��������У�ֻ�ܻӳ�һ�У�������$N"
                       CYN "���ϣ���һ������ƮȻ��ȥ��\n" NOR;
 
        me->start_busy(4);
        message_combatd(msg, me, target);
        return 1;
}
                                                                                                                                                                                                                                                                                                                                                                                                                              