#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;



int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,busy;  
        int damage;  
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�����䡹?\n");
         
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("��ʹ����ڤ����!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("�����ڤ����������������\n"); 
                
        if( !me->is_fighting() )
            return notify_fail("�����䡹ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("�������������ܻ��������䡹��\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("frht-hammer", 1) < 120)
                return notify_fail("��ķ��ջ��촸�ȼ�����������ô��ʹ�������䡹��\n");

        if (me->query("neili") < 600)
                return notify_fail("���������̣�����ʹ�������䡹��\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/100+1;
message_vision(HIY"\n$N�Ų��ڳ�ϼ�ƻ�֮�У�����������ɽ���Ų���ӯ������������ʹ��"+HIR"�����䡹"+HIY"һ����\n"NOR,me,target);        
           msg = HIC"\n�գ����ʽ���С����ɽ�����з紵��ֻΪ���ѣ��ļ���������\n" NOR;

                message_vision(msg + "\n", me, target);
                
        msg = HIC "��ͤ�»��ݣ���ǧ���������ã���¶֪���٣����㺬̬���ˣ�ĺ����������......��\n" NOR;
                message_vision(msg, me, target);
 me->add_temp("apply/attack", 50); 
  me->add_temp("apply/damage", 2000); 
if (random(3)==0) target->start_busy(3);
 message_vision(HIG"$n����Ӱ����ϡ��������ɽ��פ�㣬̾����ϧ�գ�ϧ��...��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIG"$n����Ҷ�仨�У�ٰ�㲣��⣺�����գ�����...��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"$n�䵱�꣬�Ū�����֣����ԣ�����ϼ�����䣬��������ͤ�λ꣬�����ȥ����...��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);



 me->add_temp("apply/attack", -50); 
  me->add_temp("apply/damage", -2000); 
        me->add("neili", -150);
 
 if ((int)me->query_skill("frht-hammer",1)> 600 || !userp(me))
{
       msg =  HIR "$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ���\n" NOR;
        message_combatd(msg, me,target);                
if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong",1)+ (int)me->query_skill("frht-hammer",1);  
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*6);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage,me);
            target->receive_wound("qi", damage,me);
}
                msg=RED "���һ�������$n��ͷ����,����һ����Ѫ��\n" NOR;
}
else
{
                msg="$n��æ�������Ծ�����ɣ�����ǿ������������һ����\n" NOR; 
}
message_combatd(msg, me,target);        
        
}         
 
 
        me->start_busy(2);
        return 1;  

}