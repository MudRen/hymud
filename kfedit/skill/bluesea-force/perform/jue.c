// jue.c ���ɾ�
 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;
        int lvl,i,j;
        //mixed dp;        
        
lvl=me->query_skill("bluesea-force", 1);
        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("���ɾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (me->query_skill("bluesea-force", 1) < 200)
		return notify_fail("����Ϻ�������������죬����ʹ�þ��ɾ���\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�õ��ڹ����ԡ�\n");


        if (me->query("neili") < 800)
                return notify_fail("�����������������ʹ�þ��ɾ���\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N" HIC "������Ц�����ɾ� һ�ƻӳ����仯��������Ӱ����ס��$n"
              HIC "���е���·��\n" NOR;
 


        ap = me->query_skill("strike") + me->query("con") * 20;
        dp = target->query_skill("force")+ target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
                        damage = me->query_skill("force")+100;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "$n" HIR "������Ų������ȴ����ž����"
                                           "һ����$P" HIR "���ʵʵ�Ĵ�������ǰ����"
		                           "ʱ��Ѫ��ֹ��\n" NOR;
	}

	message_combatd(msg, me, target);

if (lvl>=300  || !userp(me))
{
msg = HIC "$N" HIC "��Ȼ��Ц��¾�ɾ� �� �ĳ�һ�ƣ��������£��仯Ī�⣬����$n"
              HIC "��\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("con") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
                        damage = me->query_skill("force")+300;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "�������ԣ��˹��ֵ���ֻ����$P��������"
                                           "��֮����ֱ�������澭��������ʱ�������ˣ�\n" NOR;
		                           
	}

	message_combatd(msg, me, target);	
	
}	


if (lvl>=600  || !userp(me))
{
msg = HIC "$N" HIC "�������£�ն�ɾ� ٿ��һ���ĳ�������ʵ"
              "ʵ�Ĺ���$n" HIC "���仯��������׽����\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("str") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
damage = me->query_skill("force")*2+600;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "��һ��ԥ������һ�ƻ���"
                                           "�����У��������˼���������һ�ص�Ѫ��\n" NOR;
	}

	message_combatd(msg, me, target);
	
}	


if (lvl>=900  || !userp(me))
{
msg = HIC "$N" HIC "�����ĳ�һ�ƣ����ɾ� �����������һ�����$n"
              HIC "�ٶȿ�Ĳ���˼�飡\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("int") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "Ȼ��$n" HIG "������$N" HIG
                       "�����ƣ����Ų�æ�Ķ������һ����\n" NOR;
        } else
	{
		me->add("neili",-75);
               damage = me->query_skill("force")*3+1000;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                target->start_busy(3);
                msg += HIR "$n" HIR "����˼����һ�Ƶĺ��ƣ���������"
                                           "��ǰ��ֻ�����ۡ���һ����$n��Ѫ���ߣ�\n" NOR;

	}

	message_combatd(msg, me, target);

msg = HIC "$N" HIC "���Ữ�˸�Ȧ�ӣ����κ�Ȼ��죬������Ϊһ������$n"
              HIC "��\n" NOR;
        i = 6;

                msg += HIY "��������֮�£�$n" HIY "��ʱ���ú���"
                       "����������������ѹ��������ܣ�ֻ��$N"
                       HIY "һ�ƽ�һ�ƵĹ��������纣�ˡ�\n" NOR;
	message_combatd(msg, me, target);
                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1000);
        j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 4 && ! target->is_busy())
                        target->start_busy(1);
	msg = HIR "$N�������� ��"+ chinese_number(j) +" ʽ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        j=j+1;
        }

                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1000);
	
}

if (lvl>=1000 || !userp(me))
{
msg = HIC "$N" HIC "����һ��������Ϊצ���������� Ѹ���ޱȵ�Ϯ��$n��\n";

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        
        if (ap * 2 / 3 + random(ap) > dp)
        {
                ap = me->query_skill("bluesea-force");
                dp =  target->query_skill("parry",1);
	        me->add("neili", -60);
	        me->start_busy(1 + random(2));

	        
                // if (dp >= 10000)
                if (me->query("max_neili") < target->query("max_neili") * 2) 
                {
                        damage = me->query_skill("strike")+100;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "ֻ�����У������ޱȣ�����Ī�⣬"
                                        "����һ����ȴ��Ȼ�����һ������͸�Ƕ�����\n" NOR;


                        me->add("neili", -140);

                        message_combatd(msg, me, target);
                        // target->start_busy(1 + random(2));
                        return 1;
                } else
                {
                damage = (int)target->query("qi")/3;
                if (damage>80000) damage=80000;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                	
                        msg += HIR "��һ����ȫ������$n" HIR "�����󣬱�$N"
                                HIR "���ʵʵ��ץ��������Ѩ������������ʱ��ɢ��\n" NOR;
                        message_combatd(msg, me, target);


                        return 1;
                }
        } else
        {
                msg += HIM "$n" HIM "���һ������æ���ҵֵ�����"
                                "Ȼû��һ���˺������ҵ��ѣ�\n" NOR;
                
                me->start_busy(3);
        }
me->start_busy(2);
        message_combatd(msg, me, target);

}
me->start_busy(2);
	return 1;
}
