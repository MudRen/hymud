
// shisan ����ʮ����
// 2000.5.30  by ybl

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;
string msg;
int damage;
if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("������ʮ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("����ʹ�õ���������\n");

if ( (int)me->query_int() < 30 )
 return notify_fail("������첻�㣬������������ʮ���������\n");


if( (int)me->query_skill("luoyan-jianfa", 1) < 199 )
 return notify_fail("������㽣��������죬����ʹ�á�����ʮ��������\n");

if( (int)me->query("neili")<800)
 return notify_fail("����������̫��������ʹ�á�����ʮ��������\n");

        if( me->query_skill("nei-bagua",1) <=50)
                 return notify_fail("�ڰ��Եȼ�������\n");




/* */ if(random(2)==1) {
/* */ i=13;
  message_vision(YEL+"\n$N"+RED+"������Ц���������㽣���������С�\n"NOR,me);
}
else {
/* */ i=12;
 message_vision(YEL+"\n$N"+RED+"������Ц���������㽣���������С�\n"NOR,me);
}

me->add_temp("apply/attack",50);
/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
        msg = HIY "$N"+HIY"������Ц���̳���"+(i+1)+"����\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}
me->add_temp("apply/attack",-50);
if (me && target)
{
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
{
	msg = HIR  "$N����"+ weapon->name() +"�Ľ�âɢ�����������޵�ǳЦ������" NOR;
	msg +=  HIW "����һ������ʧ��������\n" NOR;
                me->start_busy(3);
                //if (!target->is_busy())
                //target->start_busy(random(2));
                damage = (int)me->query_skill("luoyan-jianfa", 1)+500;
                damage = damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage/6,me);
                target->receive_wound("jing", damage/6,me);
            	  //target->add("neli",-100);
                me->add("neili", -100);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
}
}
me->start_busy(2);
me->add("neili",-250);

return 1;
}
int help(object me)
{
	
	write(@HELP

	ʹ�ù�Ч��
		�Ե�����������ʮ����

	����Ҫ��
		���㽣��199��
		������Ϊ800
		����800
HELP
	);
	return 1;
}