// tuwu.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	int damage;
	string msg;
	object weapon;
        object weapon2;
        int ap, dp, wound;
         int i, lvl;
	 if( !target ) target = offensive_target(me);

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("lonely-sword", 1) < 200 )
		return notify_fail("��Ķ��¾Ž�������죬����ʹ���������С�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	skill = me->query_skill("lonely-sword", 1);

	me->add("neili", -100);
	target->receive_damage("qi", (int)skill/ 3,me);
	message_combatd(HIC "$N���ּ�����$n����,һ��ֻ�¾�ȫ�Ǵ���$n�书������
$n����һ��.....���ɵķ����Ĺֽ�����\n"NOR,me,target);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
	message_combatd(
        HIR "$N���еĽ������������Ľ���,һ��һ���Ľ�����$n��ȥ��\n" NOR, me, target);
	target->start_busy(1);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
	target->set_temp("block_msg/all",1);
	message_combatd(
        HIR "$n����һ�ڣ�$nɶҲ�������ˣ�\n" NOR, me, target);
    }
	damage = (int)me->query_skill("lonely-sword", 1);
	damage = 500+damage + random(damage);
	target->receive_damage("qi", damage/2,me);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(7);
        me->start_busy(1);
        //	return 1;
    } else
    {
	message_combatd(
        HIR "$N���еĽ������������Ľ���,һ��һ���Ľ�����$n��ȥ��\n" NOR, me, target);
        me->start_busy(2);
        msg = HIY"$p�鼱���������һ��...�ӳ��˽����ķ�Χ��\n"NOR;
        message_combatd(msg, me, target);
    }

if (skill>=200)
{
	
	msg = HIC "$N" HIC "���һ�������е�" + weapon->name() +
              HIC "�����缲��һ��������$n" HIC "��\n"
              HIR "��ʱ��ֻ�������������粨�˰���ӿ����$n"
              HIR "ֻ���ú�����ʱ������\n" NOR;
	message_combatd(msg, me, target);
lvl = me->query_skill("lonely-sword", 1) / 80;
                if (lvl>9) lvl=9;
                me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1200);
        for (i = 0; i < lvl; i++)
        {
msg=HIM"$N�����ݺ�! ��"+chinese_number(i+1)+"������������$n��$l�������Ѫ��!\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1200);
}

if (skill>=300)
{
  msg = HIC "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0)
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi")/5;
if (damage >=25000) damage=25000;
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);        
msg += HIC"$n��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����\n"NOR;
    } else
    {
        me->start_busy(2);

msg += HIY"����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�\n"NOR;
    }
    message_combatd(msg, me, target);	
	
}	

//if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void tuwu_end(object me, object target)
{
if (target)
{
	target->enable_player();
	message_combatd("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
	target->set_temp("block_msg/all", 0);
}
	//write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	return;
}