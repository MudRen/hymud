#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="���츲��";
        return str;
}

string get_help(string str)                
{
        str="ָ������������������\n"
        +"�������Ͷ������150�����������1000"
        +"�����Դ���������ݷ���ʽ�����������ˣ�";
        return str;
}

int perform(object me, object target)
{
        
        object *inv, obj, obj1;
        int i, mypot, tapot, damage;
        string str;

        object weapon;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����츲�ء���\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(!me->is_fighting())
                return notify_fail("�����츲�ء�ֻ����ս����ʹ�ã�\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("neili") < 600 )
                return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("buddha-club",1);

        if( i < 150)
                return notify_fail("��İ�����������ʹ����һ�л������ѣ�\n");

        if( time()-(int)me->query_temp("fantian_end") < 4 )
                return notify_fail("�����츲�ء����������õĵ���\n");
                
        message_vision(HIY"\n$N��ָ$n�ߺ޵��������Ҳ��ʶ���С�����ԡ���һ����գ�$N���˵���������ģ�ʹ�������츲�ء���\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("buddha-club");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/5 || !living(target) ) 
        {               
                message_vision(HIR"\nֻ��$nӲ�����Ľ�ס$N�⼼���У��ٸк�ͷһ��[��]��һ���³�һ����Ѫ��\n\n"NOR,me, target);  
                COMBAT_D->do_attack_damage(me, target);
                damage = random(me->query_skill("club")) + me->query_skill("club")+200;
                target->receive_wound("qi", damage,me);
                COMBAT_D->report_status(target);
                

                        if ( random(10)>1 )
                        {
                                message_vision(HIR"\n\n$N����$n���˲��ᣬ��ʤ׷�����ֳ�һ�������Ƹ��ꡱ��$n���߻�����������ȥһ�롣\n"NOR,me,target);
                                COMBAT_D->do_attack_damage(me, target);
                                damage = random(me->query_skill("parry")) + me->query_skill("parry")+200;
                                target->receive_wound("qi", damage,me);
                                COMBAT_D->report_status(target);
                                target->start_busy(1+random(2));
                                message_vision(HIR"\n$N˦���Ͷ����������У�����$n�����ء�\n"NOR,me,target);
                                me->set_temp("QJB_perform", 6);
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                me->delete_temp("QJB_perform");
                        }
          
// }
        }        
     
        else  
        {
                message_vision(HIC"$Nʶ�ƴ��У����˵����������Ӳ�Ӵ˾��У�\n"NOR, target);
                //me->start_busy(2);
        }
        me->start_busy(2);       
        me->add("neili", -150);
        me->receive_damage("jing", 50);
        me->set_temp("fantian_end",time());
        return 1;
}


