//��������ǧ��ѩ BY Cigar 2002.01

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
void qianxue_ok(object);

int perform(object me, object target)
{
        int damage,damagea;
        object weapon;
        string msg;
        int extra,add_dodge;
        string *mapped;
        mapping map;
                extra = me->query_skill("snowsword",1);         
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���������ǧ��ѩ����\n");


     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("��ʹ�ñ����ķ�!\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("��ı����ķ�������������\n"); 
                

        if(!me->is_fighting())
                return notify_fail("����������ǧ��ѩ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 300 )
                return notify_fail("�������������\n");
        if((int)me->query("neili") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
         if((int)me->query_skill("snowsword", 1) < 120)
                return notify_fail("��ķ��ѩ�轣������������ʹ����һ�л������ѣ�\n");

  
        if(me->query_temp("no_qianxue"))
                return notify_fail("�����ڡ���������ǧ��ѩ�����ñϣ��Ȼ�����ðɣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        //damagea=random((int)me->query_skill("dodge")/2);
        damagea=random((int)me->query_skill("dodge"));
        if(random((int)target->query("combat_exp"))/2 < (int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$N�������⺮��С�£�ů��δ�ߣ�����ʫ�⣬����"+HIR"����������ǧ��ѩ��"+HIW"��\n"NOR,me,target);
                target->receive_damage("qi",damagea,me);
                target->receive_wound("qi",damagea/2,me);
                target->receive_damage("jing",damagea/3,me);
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIG"\n$N�������������������࣬$n�������$Nȴ����ζ...\n"NOR,me,target);
        }
        message_vision(HIG"\n$N���þ�˿����ѩ���������⺮÷����ӳ���У�������������\n"NOR,me,target);
        message_vision(HIG"\n��Ϊ����ѩΪ�񣬱��˲���ѩ�֣�������˿���£����ġ�\n"NOR,me,target);
        
        	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 2200);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n����ͤ���£�������Ӱ�����񣬳ص�Ӱ�����£�������ˮ�����⡣\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n��ǰ�������ˣ����廨Ѭ���Ʋ�������������\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        //damage=random((int)me->query_skill("sword")/2);
        damage=(int)me->query_skill("sword")+random((int)me->query_skill("parry"));
         	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -2200);
        if(random((int)target->query("combat_exp"))/2<(int)me->query("combat_exp"))
        {
                message_vision(HIC"\nС�¡����㡢����Χ����$N����Χ������˾���������$n���ߵ�....\n"NOR,me,target);
                target->receive_damage("qi",damage/2,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n����һЦ����Ц��������⡣$n�ӻ����ͳ�һ�����ƣ�����С�á�\n"NOR,me,target);
        }

       message_vision(
                HIW"$N��һ�����������Ṧ���ν����衣ֻ��$N�㲻մ�أ����н�Խ��Խ�죬�𽥻���һ�Ű������ù�����\n" NOR, me);
 
 if ((int)me->query_skill("snowsword",1) > 300)
 {
 	       if(  me->query_skill("snowsword",1)<100)
        {
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);                
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))  
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������.\n"NOR,target);
                        target->start_busy(3);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������.\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        if( (me->query_skill("snowsword",1)<300)&&(me->query_skill("snowsword",1)>100))
        {
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2)))  
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������..\n"NOR,target);
                        target->start_busy(2+random(3));

                       
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������..\n"+NOR,me);
                        me->start_busy(3);
                }
        }
        if( me->query_skill("snowsword",1)>300 )   
        {
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")*7/10)))                
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������...\n"NOR,target);
                        target->receive_damage("jing", extra);
                        if(!userp(target)) 
                        {
                                target->add("eff_jing", -extra*2);
                                target->receive_damage("jing", extra);
                        }
                                target->start_busy(4);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������...\n"+NOR,me);
                        me->start_busy(2);
                }
        }
 	
}
 
me->start_busy(3);
        //me->receive_damage("jing", 30);
        me->add("neili", -100);
        me->set_temp("no_qianxue",1);
        call_out("qianxue_ok",2+random(2),me);

        return 1;
}

void qianxue_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_qianxue");
}

