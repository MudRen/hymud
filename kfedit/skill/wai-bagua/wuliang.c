// wuliang.c ����ԡ�Ǭ��������
// Create for Haiyan 2002

#include <ansi.h>


#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count, acter;
        int i, bsy, lvl;
int damage,attack_time,level;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��Ǭ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("cuff") != "wai-bagua") 
                return notify_fail("��û�м�������ԣ��޷�ʩչ��Ǭ����������\n"); 

        if ((int)me->query_skill("wai-bagua", 1) < 120)
                return notify_fail("�������Բ�����죬����ʹ�á�Ǭ����������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("��Ǭ��������ֻ�ܿ���ʩչ��\n");  



        if (me->query("neili") < 350)
                return notify_fail("��������������޷�ʹ�á�Ǭ����������\n");




        msg = HIY "$N" HIY "�Ʒ���Ȼ��죬ʹ������Է���Ǭ���������������ذ��Է�λ���ߣ�˫������ʵʵ������$n��\n" NOR;

        dp = (target->query_skill("force", 1) + 
             target->query_skill("parry", 1) +
             target->query_skill("martial-cognize", 1)) / 3 +
             target->query_skill("count", 1); 


             acter = 3;


        ap = (me->query_skill("bluesea-force", 1) +
             me->query_skill("wai-bagua", 1) +
             me->query_skill("bagua-bu", 1) + 
             me->query_skill("nei-bagua", 1)) / acter; 

        if ( ap / 2 + random(ap) > dp )
        {
                msg += HIR "$n" HIR "��$N" HIR
                       "��һ�仯���˸����ֲ������������ء��������ƣ�" HIR
                       "���������Ѫ����ɫ���ɷ�ף�\n" NOR;
                count = ap / 28; 
                bsy = 2;
                lvl = me->query_skill("wai-bagua", 1) / 60;
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "��Ȼ���У����Ҵ��⣬��æ��Ϣ������С��Ӧ�ԣ���$N"
                       HIC "����ʽ������⡣\n" NOR;
                count = 0;
                lvl = 0;
                bsy = 5;
        }
                
        message_combatd(msg, me, target);

        me->add("neili", -150);
if (lvl>9) lvl=9;

                me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1200);
        for (i = 0; i < lvl; i++)
        {

         msg = HIG "��"+chinese_number(i+1)+"�ƣ�$N�����ذ��Է�λ���ߣ�˫������ʵʵ������$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        }

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1200);
        me->start_busy(2 + random(bsy));

        return 1;
}

