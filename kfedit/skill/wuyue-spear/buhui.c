#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
//inherit F_CLEAN_UP;

string get_name(string str)
{
        str="����";
        return str;
}

string get_help(string str)                
{
        str="ָ�����������������\n"
        +"����������ǹ��100����ƽ���100��"
        +"�����ʼ��ߵľ��У�������С��";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int i,j,k,damage,lmt;
        string msg;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");
                
     
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("��ʹ�ú�������!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 200)
                return notify_fail("��ĺ�������������������\n"); 

                
        i=(int)me->query("combat_exp");
        j=(int)target->query("combat_exp");
        k=(int)me->query_skill("club");
        
        if(k<100)        
                return notify_fail("���ǹ�����𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIM"\n$Nһͦ����"+weapon->name()+NOR+HIB"ֱ��$n��\n"NOR,me,target);
//���Ժݺݵļ�ǿ�˲��ڡ�
//Wuyou@Sanjie
        //if (random(i)>random(j)) 
        if (i > random(j)) 
        {
                damage=300+k+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*7/8> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=400+k+random(k)+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        //if (random(i)*5/6> random(j)) 
        if (i > random(j)) 
        {
                message_vision(HIR"\n$Nһǹ�̿գ�����һ�⣬����δ�����Ի���"+HIB"$n"+HIR"��\n"NOR,me,target);
                message_vision(HIM"\n$Nһ���ֿգ����Բ����У�˫��һ�ɣ�һͷײ��"+HIB"$n"+HIM"��\n"NOR,me,target);
                damage=500+k+random(k)*2+(int)me->query("str");
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        else 
                if (random(2)) 
                {
                        message_vision(HIR"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIR"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIR"\n$Nһͷ��Ȼײ�գ���$nҲ����ƴ���ľٶ�����һ����\n"NOR,me,target);
                        target->start_busy(5);
                }
                else 
                {
                        message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
                        message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
                        message_vision(HIW"\n$n������Ц��ֻ��ƥ��ֻ�����к��ã����ɱܿ�\n"NOR,me,target);
                }

      msg = HIY  "$Nǹ�����࣬�·��紪�ޱʱ�ī��ֽ�����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
        message_vision(msg,me,target);
        lmt = random(4)+3;
        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1500);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIC "$N���һ�����ӵ�"+chinese_number(i)+"ǹ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1500);

        //me->receive_damage("jing", 30);
        me->add("neili", -100);
        me->receive_damage("qi", 30); 

        me->start_busy(3);
        return 1;
}


