// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
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

       if( !wizardp(me) &&(int)me->query_skill("daojian-guizhen", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("lengyue-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
                return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ������ѧ��ʹ���˺��ҵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               

if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}

	me->delete_temp("lianhuan");

	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 2800);
	msg = HIR  "$Nһҧ�������϶����ӿ죬ͬʱʹ���ۺ��ҵ����Уݵĵ������������е�"+ weapon->name() +" һ������һ���������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "��һƬ�����У�һ�����˹���\n" NOR;
        message_vision(msg, me, target);

	for(i=0;i<7;i++)
	{
	msg = HIY "$Nҧ�����أ�һ�������˹�����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}

	me->add_temp("apply/attack", -200);	
	me->add_temp("apply/damage", -2800);



        damage = me->query_skill("daojian-guizhen",1)+me->query_skill("lengyue-shengong",1);

        msg = HIY "$N" HIY "��" + weapon->name() + HIY "��" +
              weapon->name() + HIY "��������ǰ����ת����"
              HIR "����������" HIY "���������ھ��纣Х�㱬����\n" NOR;

if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIR "$n" HIR "��$N" HIR "ɱ�����ǣ�������"
                       "�����⣬�мܶ�ʱɢ�ң�ȫȻ��������\n" NOR;
       target->receive_damege("qi", damage,me);
        target->receive_wound("qi", damage,me);
                //ap += ap / 5;
                //damage += damage / 2;
        } else
        {
                msg += HIG "$n" HIG "��$N" HIG "ɱ�����ǣ�˿����"
                       "�Ҵ��⣬��æ��������Ŭ�����ܸ��š�\n" NOR;
        }

        msg += HIW "ͻȻ��$N" HIW "����һչ������" + weapon->name() +
               HIW "����һ����վ��һ���뻡��ֱ��$n" HIW "��ȥ��\n" NOR;

 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
        	
       target->receive_damege("qi", damage*2,me);
        target->receive_wound("qi", damage*2,me);
		msg +=                     HIR "$n" HIR "�����ֵ���ȴ�����мܵ�ס"
                                           "����$N" HIR "һ�л���Ҫ������Ѫ�Ĵ���"
                                           "����\n" NOR;
        	

        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }

        msg += HIW "����$N" HIW "�ֽ�����" + weapon->name() +
               HIW "��$n" HIW "ƽƽ�ݳ�����ʽ���Ƽ򵥣�ȴ�̲���"
               "�����ɱ�š�\n" NOR;

 	if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                // ת������
       target->receive_damege("qi", damage*2,me);
        target->receive_wound("qi", damage*2,me);

		msg +=                     HIR "$n" HIR "ֻ���ۻ����ң�ȫȻ�޷���"
                                           "���Ȼ���$N" HIR "һ�����У����һ����"
                                           "Ѫ��\n" NOR;
                // ת�ƻس�ʼ״̬

        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }
        message_combatd(msg, me, target);


   msg = HIW "$N" HIW "����" + weapon->name() + HIW "���һ��"
              "������" NOR + WHT "���ҵ���" HIW "������" NOR + WHT
              "��ҽ���" HIW "������ʩ������ʱ��\n���㣬����ҹ��"
              "���գ�����ǵ�����$n" HIW "������һ�С�" HIW "����"
              "��" HIR "Ѫ" HIW "����\n" NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("parry",1);

       if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
        {
                msg += HIW "$n" HIW "ֻ���������⽣Ӱ���Լ���"
                       "�����ٸ��ۻ����ң�һ�����У����һ����Ѫ��\n" NOR;
      damage=me->query_skill("daojian-guizhen",1);
      target->receive_damege("qi", damage*8,me);
        target->receive_wound("qi", damage*8,me);
        } else
        {
                msg += HIG "$n" HIG "ͻȻ�����Լ����ܽԱ�����"
                       "��Ӱ����Χ����֪�����æС���мܡ�\n" NOR;

        }
        message_combatd(msg, me, target);

	me->start_busy(4);
	return 1;
}

