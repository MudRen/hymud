#include <combat.h> 
#include <weapon.h> 


inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,busy;    
        int damage,wound;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��ϼ����?\n");  
        if( !me->is_fighting() )
                return notify_fail("��ϼ����ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�������������ܻ�����ϼ���գ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("��ʹ�ð����ķ�!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("��İ����ķ�������������\n"); 
        if( (int)me->query_skill("canxin-jian", 1) < 180 ) 
                return notify_fail("��Ĳ��Ľ�����δ���ɣ�����ʹ��[��ϼ����]��\n"); 
        if (me->query("neili") < 300)
                return notify_fail("���������̣�����ʹ����ϼ���ա�\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/60;
        message_vision(HIY"\n$N�Ų��ڳ�ϼ�ƻ�֮�У�����������ɽ���Ų���ӯ������������ʹ��"+HIR"����ϼ���ա�"+HIY"һ����\n"NOR,me,target);        
        msg = HIC"\n�գ����ʽ���С����ɽ�����з紵��ֻΪ���ѣ��ļ���������\n" NOR;
		        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 2500);
                message_vision(msg + "\n", me, target);
                
                msg = HIC "��ͤ�»��ݣ���ǧ���������ã���¶֪���٣����㺬̬���ˣ�ĺ����������......��\n" NOR;
                message_vision(msg, me, target);
                target->start_busy(2);
                msg=HIG"$n����Ӱ����ϡ��������ɽ��פ�㣬̾����ϧ�գ�ϧ��...��"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIG"$n����Ҷ�仨�У�ٰ�㲣��⣺�����գ�����...��"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"$n�䵱�꣬�Ū�����֣����ԣ�����ϼ�����䣬��������ͤ�λ꣬�����ȥ����...��"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -2500);
      
        
 if ((int)me->query_skill("canxin-jian",1)> 360)
{ 
	if (random(2)==0) target->start_busy(2);
   me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3800);
        message_vision(HIW"\n$N���о���ʩչ�Ľ��ġ�Ѹ���彣������$n�������Ĺ�����\n"NOR,me,target);
        msg= RED"$N����$w�ζ������׺���ա�ʹ��������������������$n�Ƶ��ľ���ѣ����֪$N�������˶�����"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=GRN"$N����$w���������ͻȻ���ڿ���һ����һ�С�����ӭ�͡������а�������֮����$w��·������ȣ���̼侹Ȼ���Ƶ���$n����"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg="$N$w������仯������һ�С�������������������֮���£������޶�������׽����$n��һ���ۻ����ң��ٸ����Ӧ���� "NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=BLU"$NͻȻ��������б��ܳ���ʹ�����з����ǡ�����$w�����Ȼ֮���������⻷��ת����ʱ֮���ѽ�$n����һ�Ž���֮��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=MAG"$Nȫ�����Է�������·��ʹ��һ�С������ϸǡ����仯Ī��ع���$n�����ƾ���˿�������Ѱ"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        

        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3800);
}              
        
        me->add("neili", -150);

        me->start_busy(3);
        return 1;  

}