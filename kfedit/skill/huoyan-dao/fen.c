// fen.c �����Ի�
// by secret
 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;

	me->clean_up_enemy();
       if( !target ) target = offensive_target(me);

       if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        skill = me->query_skill("huoyan-dao",1);

 
//	if (objectp(weapon = me->query_temp("weapon")))
//              return notify_fail("���������˹���\n");

	if( skill < 120)
                return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�\n");

	if( me->query_skill("xiaowuxiang",1) < 60)
                return notify_fail("��ġ�С���ࡹ�ȼ�����, ����ʹ���������Ի𡹣�\n");

	if( me->query("neili") < 600 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;

	ap = me->query("combat_exp") + skill * 800;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
	{
		if(userp(me))
			me->add("neili",-200);


		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili")/3;
		
                qi_wound = target->query("qi",1)/3;

if (qi_wound <500) qi_wound=500;
if (qi_wound >80000) qi_wound=80000;
if (neili_wound <500) neili_wound=500;
if (neili_wound >80000) neili_wound=80000;

target->receive_damage("qi", (me->query_skill("huoyan-dao",1)*8),me);
target->receive_wound("qi", (me->query_skill("huoyan-dao",1)*8),me);  
		if (target->query("neili",1) >neili_wound) target->add("neili", -neili_wound/2);
		if(userp(me)) me->add("neili",-200);
		//me->start_busy(2);

		inv = all_inventory(target);
msg += HIR "$nֻ������ǰһ�ڣ�һ������������������ۡ���һ�����һ����Ѫ��\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
if (!inv[equip]->query("systemmake") && !inv[equip]->query("ownmake"))
{
msg += HIR "$n�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR;
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "����Ƭ");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
}
target->receive_damage("qi", (me->query_skill("huoyan-dao",1)*2),me);
target->receive_wound("qi", (me->query_skill("huoyan-dao",1)*2),me);  
			}
		}
	}
	else
	{
msg += HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-200);
		//me->start_busy(2);
	}
	message_combatd(msg, me, target);



        message_vision(HIR"\nͻȻ$N˫�ƴ��˼��ֻ꣬�����������죬�����浶����$P��ǿ�ھ��Ķ�Ȼ���֮�����ƴ�ʢ��������������ε��������һƬ�������������޽���������$nֱ�����£�\n"NOR,me,target);      
        me->add_temp("apply/attack", 180);
        me->add_temp("apply/damage", 2800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/attack", -180);
        me->add_temp("apply/damage", -2800);
	//if(!target->is_fighting(me)) me->fight_ob(target);
me->start_busy(2);
	return 1;
}
