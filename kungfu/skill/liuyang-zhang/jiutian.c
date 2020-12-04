// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiutian.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define HUAN "��" HIR "���ʽ" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg,pmsg;
        int ap, dp;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 120)
                return notify_fail("��������Ʒ�������죬����ʹ�á�����ʽ����\n");
                                
        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�����ʽ����\n");
                        
        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʹ�á�����ʽ����\n");
                        
        msg = HIC "$N" HIC "˫��һ�񣬻���������Ӱ����������ס$n" HIC "��\n" NOR;

        ap = me->query_skill("strike"); 
        dp = target->query_skill("parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "���Σ�ֻ��Ӳ��һ�У������$P"
                                           HIR "���������������Ѫ��ֹ��\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
                       HIC "��һ�ƣ�û���ܵ��κ��˺���\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if( (int)me->query_skill("liuyang-zhang", 1) > 200 )
{
  msg = HIR "$N" HIR "˫��һ��ʩ����ɽ�����ơ����ʽ�����ó�"
              "������Ӱ��������ס$n" HIR "��\n" NOR;

        me->add("neili", -50);
        
        ap = me->query_skill("strike"); 
        dp = target->query_skill("force"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "���������ã�ֻ��Ӳ����һ"
                                           "�У���ʱ��$P" HIR "���������������Ѫ"
                                           "��ֹ��\n" NOR;
                me->start_busy(3);
        } else
        {
                msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
                       HIC "��һ�ƣ�û���ܵ��κ��˺���\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}	


if( (int)me->query_skill("liuyang-zhang", 1) > 300 )
{

        msg = HIR "$N" HIR "���˻�����Ψ�Ҷ������������ޣ�ȫ�������ŷ�������һ��"
              "��$n" HIR "ͷ����Ȼ���䡣\n" NOR;

        me->add("neili", -500);
        ap = me->query_skill("strike") + me->query_skill("force"); 
        dp = target->query_skill("parry") + target->query_skill("force"); 
        
        //if (target->is_good()) ap += ap / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "��ʱֻ�����ۡ���һ����$N" HIR "һ�ƽ�$n"
                               HIR "ͷ���ĵ÷��飬�Խ��Ľ�������̱����ȥ��\n"
                               NOR "( $n" RED "���˹��أ��Ѿ�������в���"
                               "��ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else
                {
                        damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "��æ�ֵ�������Ȼ������$N"
                                                   HIR "�ƾ����ˮ��ӿ�����ڣ������������"
                                                   "�߹ǡ�\n" NOR;

                       
                }
                me->start_busy(3);
        } else
        {
                msg += CYN "$p" CYN "��$P" CYN "�ƾ����ȣ����Ƶֵ���"
                       "ס����������������������������\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
}	

if( (int)me->query_skill("liuyang-zhang", 1) > 380 )
{
 msg = WHT" \nֻ��$N" WHT "��Ȼ��Ե�����������֮ɫ��˿˿����������䣬ת˲���ѽ�$P�����ư���������\n" +
             "���ô�ʱ��$n" WHT "�Ѿ������֪�������㣬$N" WHT "���С�" HIY "һ������" WHT "����Ȼ������ǰ��������\n" +
             "������$pֻ�����ܵĿ����·��Ѿ����ᣬ��һ��֮���ѽ���������ǰ�����������ʵ����\n"+
             "�԰��ѡ�˲��Ŀ�������ֱ��һ����մ󶴣�ʹ�����ܵ��˾�����һ�����ͣ�\n\n"NOR;

        ap = me->query_skill("strike") + me->query("con") * 20; 
        dp =  target->query_skill("force") + target->query("con") * 20; 
             
        if (ap / 2 + random(ap) > dp)
        {
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                pmsg = HIR "$n" HIR "�ۼ�$N" HIR "һ���������ƾ���飬�������ȣ�Ȼ��������������֮�У����޿ɱܣ�ֻ��\n" +
                       "��΢Ų���Ų�Ҳ������֮���������$N" HIR "һ��ӡ����ǰ���Ǹ�һ��ʹ����裬ȴ���߹Ǳ�\n" +
                       "��һ��֮����ϣ���Ѫ��ӿ��Ȼʧ�أ�һ����Ѫ�����ӿڱ������˳�����\n\n" NOR;
 damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "�ۼ�$N" HIR "һ���������ƾ���飬�������ȣ�Ȼ��������������֮�У����޿ɱܣ�ֻ��\n" +
                       "��΢Ų���Ų�Ҳ������֮���������$N" HIR "һ��ӡ����ǰ���Ǹ�һ��ʹ����裬ȴ���߹Ǳ�\n" +
                       "��һ��֮����ϣ���Ѫ��ӿ��Ȼʧ�أ�һ����Ѫ�����ӿڱ������˳�����\n\n" NOR;
                //msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65, pmsg);
                
                me->start_busy(3);      
        } else
        {
                msg += HIG "����$n" HIG "�����쳣��һ�۵���$N" HIG "���е�����֮���������е����ģ���伫Ϊ����������\n"+
                       "���ֳ�ָ��������$N" HIG "���������ϣ�������ָ����$P���ĵ�" HIR "�ٸ�"
                       HIG "��" HIR "�͹�" HIG "��Ѩ�����$N" HIG "Ѩ����\n" +
                      "�⣬�������޴���й������ʴ�������$P�����ֽ���ڴ����࣬����������ˣ�\n\n" NOR;

                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}	

        return 1;
}
