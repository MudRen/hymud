//�������ǹ BY Cigar 2002.04.05

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon; 
        int damage, ap, dp;

        int myskill,times, extra;
        string number;
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        extra = (int)me->query_skill("bawang-qiang", 1);  

        
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ���������ǹ����\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"���������ǹ��ֻ����ս����ʹ�ã�\n"NOR); 
        
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������ǹ��ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("���̫����������������\n"); 
        if(me->query("max_neili") < 1500 || me->query("neili")<500)
                return notify_fail("���������Ϊ��ǳ����������[�������ǹ]��\n"NOR);

        if((int)me->query("qi") < 200 )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ���������ǹ����\n"NOR);
        if((int)me->query("jing") < 100 )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ���������ǹ����\n"NOR);

        if( time()-(int)me->query_temp("jinghun_end") < 3 ) 
                return notify_fail(CYN"�����ھ����޷����У����ô˾���������Ԫ����\n"NOR); 
        
        if((int)me->query_skill("bawang-qiang", 1) <120)
                return notify_fail(CYN"��İ���ǹ���������죬�޷�ʹ�����С��������ǹ����\n"NOR);

 
        me->add("neili", -165);
        //me->receive_damage("qi", 100);

       msg = HIW "\n$N�־�"+ weapon->query("name")+ HIW"ֱָ����,ֻ��ǹͷ������,ǹӧ��ʱ�Ե÷�����次�";
        msg += "\n\n˵ʱ�٣���ʱ�죬$N˫�������������գ�����ͣ�٣���תǹͷ��������������һ���֡�\n\n" NOR;
        
        msg +=HIY "              ������                        ������  \n";       
        msg +=HIY "              ��"+HIW"�@"+HIY"��  ��������������������  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ��"+HIW"��"+HIY"��  ��"+HIR" �@ �� �� �� �� "+HIY"��  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ��"+HIW"��"+HIY"��  ��������������������  ��"+HIW"��"+HIY"��  \n";
        msg +=HIY "              ������                        ������  \n";

      
        ap = me->query_skill("bawang-qiang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/200) <  dp/1000 ) 

        {
                msg += "\n$n"+HIC"���弱�ٺ��ˣ��������ĵĶ������������һ�У���ʱ���������亹���졣\n"NOR;
                message_vision(msg, me, target);
              me->start_busy(2); 
        } else {
                damage = 800+(int)me->query_skill("club",1)  +
 		(int)me->query("jing") / 400 + random((int)me->query("jing") / 200 ) +
        (int)me->query("qi") / 400 + random((int)me->query("qi") / 200 );
                msg += HIW "\nֻ������һ����$N���弸����վ����Զ��ɽ�о��£�����$n��ǰ�Ѿ����̳�һ��Ѫ������\n\n" NOR;
                damage +=random(50);
                if(!target->is_busy()) target->start_busy(2);
                //target->receive_damage("jing", damage,me);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->improve_skill("bawang-qiang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        

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
            else
                    if(myskill <310 ){
                           times = 6;
                           number = "��";}
                     else{ 
                           times = 7;
                           number = "��";}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        damage = 300+me->query_str() + me->query_skill("club");

message_vision(HIC"\n$Nһ����Х��"+ weapon->query("name")+ HIC"��һת�������������$n������"+number+"ǹ��ǹǹҪ����\n"NOR,me,target);

                if (!target->is_busy()) target->start_busy(1);
        if (extra> 200) extra=200;
        for(int i=1;i<=times;i++)
{
        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", 2200);
                        msg = HIY "��"+chinese_number(i)+"ǹ-------> ��\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -2200);
        me->receive_damage("jing", 20);
        me->add("neili", -(times*10));
}
        if( times>5 && myskill> 360)
        {

                target->receive_damage("jing",damage,me);
                target->receive_wound("jing", damage,me);
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi", damage*2,me);
                                        
                message_vision(HIR"\n$nֻ������ǰһ�����ؿ��ѱ�$N��"+ weapon->query("name")+ HIR"����һ����õ�����÷��������\n\n����������Ѫ��ӿ��������$n�Ѿ���Ϣ���٣���\n" NOR,me,target);
                COMBAT_D->report_status(target, 0);
        }
    	me->start_busy(3);
//        me->set_temp("jinghun_end",time()); 
        return 1;
}
