// yitian.c ���콣��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#define ZHAO "��" HIY "�������" NOR "��"

#define YUN "��" HIW "�ƺ�����" NOR "��"
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        int extra,i,time,ap,dp,damage;
        string msg;
                int lvl,skill;
        lvl=me->query_skill("yitian-jian");
        i = me->query_skill("yitian-jian", 1) + me->query_skill("sword", 1) + me->query_skill("linji-zhuang", 1);
        time = 5;
         if( !target ) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����콣����ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�����콣���������ý�����ʹ�ã�\n");
        if (me->query_skill_mapped("sword") != "yitian-jian")
                return notify_fail("��û�м������콣������ôʹ�á����콣��������\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("����ڹ���Ϊ������\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("yitian-jian",1) < 120 )
                return notify_fail("������콣���������ң��޷�ʹ�á����콣������\n");

        msg =HIY "$N" HIY "��Хһ����\n" HIR "�������𡢱����������������£�Ī�Ҳ��ӡ����첻����˭������? \n"
             HIR "��ʱ���Ʊ�ɫ��" HIR "$N" HIR "����������콣��........ \n" NOR;

        message_vision(msg, me);
        if (random(3)==0) target->start_busy(3);
if (i>200) i=200;
        me->add_temp("apply/attack", i);
//        me->add_temp("apply/damage", i/2);
        me->add_temp("apply/damage", 1200);
//        for(i=1;i<=(int)time;i++)
        //{
        msg =  HIC "-----���Ƽ���!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  BLU "-----�Ǻ�����!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIM "-----�����Ƶ�!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg =  HIM "-----������!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);      

        msg =  HIY "-----���첻��!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIR "-----˭������!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIM "-----��������!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

  
        

        //}
        me->add_temp("apply/attack", -i);
//        me->add_temp("apply/damage", -i/2);
        me->add_temp("apply/damage", -1200);
        me->add("neili",-200);
        msg =HIY "$N�������콣��������Ȼ�ӿ죡\n" NOR;
        message_vision(msg, me);
if (lvl>300)
{
	
	msg = 
YEL "\n$Nʹ�����ָѨ�����������ָѨ�����ع������������������۾�һ�㣬��
��ʳ�ж�ָ��$n������ȥ��һ����ָ��ȫ�Ƕ���$n��ͷ����ǰ����Ѩ��\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
		msg +=  NOR "���$p��$Pָ�����м���Ѩ��! \n" ;
		target->start_busy( 7);

	}
	else
	{
		msg += NOR "$p�鼱����������һԾ���˳���Զ��\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);	
}	

if (lvl>600)
{
msg = HIY "\n$N" HIY "����ȫ��������ʱ�����ŷ���ȫ�������ž��"
              "�죬��Ȼһ����$n" HIY "\nȫ���ĳ�������һ���еУ�����һ"
              "�С�������ա���\n" NOR;
         
        ap = me->query_skill("hand") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("hand")+lvl;

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {

                me->start_busy(5);
                msg += HIW "ֻ����Ȼһ�����죬$n" HIW "�ѱ�һ�����У���$N"
                       HIW "ֻ��ȫ���������罭����\n��������ˮ�齻�ڣ���"
                       "ʱ��ʧ����Ӱ���١�\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {

                me->start_busy(2);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ����Ȼһ�����죬$n" HIR "��$N"
                                           HIR "һ�����У����ӱ��絾�ݰ�ƽƽ�ɳ�"
                                           "����\n��ˤ�ڵ��£�Ż��һ�����Ѫ����"
                                           "Ҳ������\n" NOR;

        } else 
        { 

                me->start_busy(3);
                msg += CYN "����$p" CYN "������񣬼�ʱ������" 
                       CYN "$P" CYN "������ǣ�����㿪����һ����\n" NOR; 
        }
        message_combatd(msg, me, target);	
	
}	

        me->start_busy(2);
        return 1;
}

