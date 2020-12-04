// dian.c һָ�� - ��
// Written by Doing Lu 1999/2/27

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		// ���ֵ�����
	string msg;
int neili_wound, qi_wound ;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������㡹�־�ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(weapon = me->query_temp("weapon")))
			return notify_fail("�㲻��ʹ��������\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�������!\n");

	if( (int)me->query_skill("yizhi-chan", 1) < 150 )
		return notify_fail("���һָ��̫���裬����ʹ�á��㡹�־���\n");

	if ( me->query("neili") < 500)
		return notify_fail("������������������޷�ʹ�á��㡹�־���\n");
	me->add("neili", -100);

	msg = HIY " $N��������һ�����������ָ��ʹ�����ŷ�ħ���Ͼ���ָ������������$p���˹��ˡ�\n";

	ob = target->query_temp("weapon");
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ) 
	{
                qi_wound = target->query("qi")/3 ;
if (qi_wound < 10)qi_wound=10;
if (qi_wound> 39000) qi_wound=39000;
//qi_wound = qi_wound + ((int)me->query_skill("yizhi-chan", 1)*2);
		//me->start_busy(2);
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR " $p�������˼����ϳ���������û�ܶ����"
						"$N����һָ������$p�ĵ����ϣ�\n$pֻ����һ��"
						"�������Ե�����ϣ���������˵���������ܡ�\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $p����Ʈ�������鶯֮����������Ҫ�Ȳʣ�"
              					"�����ۡ���һ��������ܸ$p��ɫɷ�ף�ҡҡ��׹��\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p���һ�����Գ�������ǿ�����ֳ��У���࣡�"
						"��һ����ָ�ཻ��$p����΢�Σ������ֽ��\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��"
						"ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p�������У���Ȼ��֪��ܣ����͡���һ����$N"
						"��һָ������$p��̴�д�Ѩ��\n";
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
//					target->unconcious();
					damage = 0;
					break;
				case 1:
					msg += HIR " $pһת��Ѿ�����˾�ʮ���ֻ���İ취��"
						"��δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N����̴"
						"�д�Ѩ��\n";
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);

//					target->unconcious();
					damage = 0;
					break;
				}
			}
			if (damage > 0)
				target->receive_damage("qi", ((int)me->query_skill("yizhi-chan", 1)*5),me);
			message_vision(msg + NOR, me, target);
			return 1;
		}
		if (random(3) >=1 )
		{
			msg += HIR " $pæ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
		} else
		{
if (!ob->query("systemmake") && !ob->query("ownmake"))
{
			msg += HIW " $p��æ�мܣ�ֻ������ž����һ����$p���е�" + ob->name()
				+ "�����ѣ�ɢ��һ�أ�\n";
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
}
target->receive_damage("qi", (me->query_skill("yizhi-chan",1)*2),me);
target->receive_wound("qi", (me->query_skill("yizhi-chan",1)*2),me);  
		}
		target->start_busy(2);
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $pһ����Ц�������仯�˼����������˶�Ŀ��һʱ��$N�޷�������\n";
				busy = 2;
				break;
			case 1:
				msg += " $pͻȻ���Ʈȥ���������磬��$N��һָ���еĺ�̱仯�޴�ʩչ��\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p��ɫ���أ��������ƣ���׾��׾����Ȼ��$N�޴����֣�ֻ����ָ��\n";
				busy = 3;
				break;
			case 1:
				msg += " $p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += " $p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
				busy = 2;
				break;
			case 1:
				msg += " $pһָ���������ȥ����Ҳ�Ƿ��ž���ָ����$Nһ�������ƶٻ���\n";
				busy = 2;
				break;
			case 2:
				msg += "$p��ס����������ע��������ס��$N�Ľ�����\n";
				busy = 2;
				break;
			}
		}
		target->start_busy(busy);
		//me->start_busy(3);
	}
	message_vision(msg + NOR, me, target);

        me->add_temp("attack",100);
        me->add_temp("damage",1800);
        message_vision(
        HIW "\n$Nʹ��һָ����������ħһָ������ס��$n��ȫ��ҪѨ��\n" NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("attack",-100);
        me->add_temp("damage",-1800);
me->start_busy(3);
	return 1;
}
