//Cracked by Roath
//bugong.c ����ǹ��֮����
//writted by libai

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int mkee;

        int damage, ap, dp;

        int myskill,times, extra,i;
        string number;

        
        int b_time = (int)me->query_skill("bawang-qiang") / 50 + 2;
        if (b_time < 4) b_time = 4;
        if (b_time > 8) b_time = 10; 
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        extra = (int)me->query_skill("bawang-qiang", 1);  


        if( !target ) target = offensive_target(me);

        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("��û��ǹ����ôʹ��������\n");
        
        if (me->query("neili") < 500) return notify_fail("�������̫�١�\n");
         if (me->query("jing") < 100) return notify_fail("��ľ�̫�١�\n");
       
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "������ԥ�������ŵ������ɡ�\n");
    
        if(environment(me)!=environment(target))
                return notify_fail("��Ҫ�������˲������\n");
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("���̫����������������\n"); 
        
        if( (int)me->query_skill("bawang-qiang", 1) < 80 )
                return notify_fail("��İ���ǹ��������죬���ܲ��ò�����\n");

        msg = CYN "$N����"RED"��ǹ"CYN"�Ͷ�����̤�沽����ʱӿ������ɱ����ң��$n���ƹ��ǹ������ط���!
"HIR"����"CYN"һ����$n��ʱ�е�������������������춱�����������ơ�\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += "$n��æ��ǰ�͹�,����ȴ�޴����֣��������������ѵľ��ء�\n" NOR;
                target->start_busy(5);
        } else {
                me->start_busy(3);
                msg += "����$nҲ�����ż�,����������м���������\n" NOR;
        }

        message_vision(msg, me, target);

      if(myskill <170){
                times = 3;        
                number = "��";}
            else
                if (myskill <190){
                    times = 4;
                    number = "��";}
                else
                    if(myskill <210 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}


        damage = 300+me->query_str() + random(me->query_skill("club"));

message_vision(HIC"\n$Nһ����Х��"+ weapon->query("name")+ HIC"��һת�������������$n������"+number+"ǹ��ǹǹҪ����\n"NOR,me,target);

                if (!target->is_busy()) target->start_busy(1);
        if (extra> 200) extra=200;
        for(i=1;i<=times;i++)
{
        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", 2200);
                        msg = HIY "��"+chinese_number(i)+"ǹ-------> ��\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -2200);
        me->receive_damage("jing", 20);
        me->add("neili", -(times*10));
me->start_busy(3);
}      
        me->add("neili",-100);
        return 1;
}