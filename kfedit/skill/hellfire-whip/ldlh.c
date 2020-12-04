//write by yesi

#include <ansi.h>

inherit F_SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
        int i,j;
                        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        {
return notify_fail("��Ҫ��˭ʩչ�������ֻء���\n");}
        
        if(time()-(int)me->query_temp("ldlh_end") < 10) 
                return notify_fail("����Ƶ�����롸�����ֻء���\n");

        
        if(me->query_temp("ldlh")) 
                return notify_fail("������ʹ�á������ֻء���\n"); 
        
            
        if(!me->is_fighting())
                return notify_fail("�������ֻء�ֻ����ս����ʹ�ã�\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
        
        
        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        
        
        if((int)me->query_skill("hellfire-whip", 1) < 250)
                return notify_fail("��������һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");

        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");

        
        
        
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIW"\n$N���������дʣ����������ܣ����������ܣ������������ҹ����������ٶ��ֻء�\n"NOR,me);
        me->set_temp("lunhui",0);
        me->set_temp("ldlh",1);
        me->set_temp("ldlh_time",6+random((me->query_skill("whip"))/6));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
        object weapon;
        if(!me) return;        
        if( !objectp(weapon=me->query_temp("weapon")) ||
                (weapon->query("apply/skill_type") != "whip" &&
                weapon->query("skill_type") != "whip" ) || 
                me->query_skill_mapped("whip") != "hellfire-whip") 
                remove_effect(me);
        else if(me->query_temp("ldlh_time")<1 || !me->is_fighting())
                remove_effect(me);              
        else {  
                me->add_temp("ldlh_time",-1);
                call_out("check_fight", 1, me);
             }
}



void remove_effect(object me)
{       if(!me) return;
        remove_call_out("check_fight");
        me->delete_temp("ldlh");
        me->delete_temp("lunhui");
        message_vision(HIW"$N�ӡ������ֻء����˳�����\n"NOR, me);
        me->set_temp("ldlh_end", time() );
}


