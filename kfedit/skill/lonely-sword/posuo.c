// posuo.c ������ʽ��

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, wound, damage;
int i, lvl;
//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "whip")
            return notify_fail("�Է�û��ʹ�������ò��ˡ�����ʽ����\n");

        if( skill < 60)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");

        if( me->query("neili") < 50 )
            return notify_fail("��������������޷����á�����ʽ����\n");

        msg = HIC "$Nʹ�����¾Ž�֮������ʽ�����������ǣ�Ѹ���ޱȵص���$n������\n";
        message_combatd(msg, me, target);

        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword") ;
        dp = target->query_skill("whip") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 //me->add("neili",-50);
            msg = "���$n��$p���˸����ֲ���������һ�飬����";
            msg += weapon2->name();
            msg += "���ֶ�����\n" NOR;

            me->start_busy(1);
            target->receive_damage("qi", damage,me);
            target->start_busy(2);
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
            weapon2->move(environment(me));
}
            if (weapon2->query("ownmake")==1)
            {
                weapon2->move(target);
                msg += "�ǿ���$n�������һ$n��һ�콫���������\n" NOR;
            }
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
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
        else
        {
            if(userp(me))
                 //me->add("neili",-30);
            msg = "����$n������$N����ͼ��Ѹ���˿���ʹ$N�ġ�����ʽ��û�������á�\n"NOR;
                 //me->start_busy(2);
		message_combatd(msg, me, target);
        }

me->start_busy(2);
        return 1;
}