//modified by longer

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{
        object weapon;
        int i,j;
                string msg;
                int damage;
                        int wound,k,damage_bonus,mystr;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������������\n");


if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("��ʹ�ð����ķ�!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("��İ����ķ�������������\n"); 
        


        if(!me->is_fighting())
                return notify_fail("������������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("neili") < 600 )
                return notify_fail("�������������\n");

        if((int)me->query("qi") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("rousi-whip", 1) < 150)
                return notify_fail("�����˿�ֱ޼��𻹲������޷�������Ͼ��裡\n");

               weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");
				        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1900);
        msg=HIY"$N˫�ּ��ٻ�����˿�ֱޣ���������������������������������֮��"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIW"���"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIW"���̡�"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIR"��ǡ�"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIB"�����"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg=HIM"�����"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg=HIM"�����Ϻ�һ��"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
				        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1900);
                if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);


if ((int)me->query_skill("rousi-whip",1)> 360)
{
message_vision(HIW"$N���ű�غ������ŵĻ��䣬�鵽һ����Ȼ������˳��������"+HIR""BLINK"�ֻ֡���֡�"NOR""+HIW"���Ĳ���......\n"NOR,me,target);
message_vision(HIG"            ���˼仨������ȥ���ģ���ҩ���꣬��Ȼ��̬���㡱��\n"NOR,me,target);
message_vision(HIG"            ��������£���ռ�������������㣬�û�ǧ����֦����\n"NOR,me,target);
message_vision(HIG"            ���˲��淼�����ﵱ���������ᢣ��������ƻ��á���\n"NOR,me,target);
message_vision(HIG"            ���������꣬���潻�࣬�����������վƷ�ͤ�λꡱ��\n"NOR,me,target);
message_vision(HIC"������Ⱦ¶�����䵱�꣬���޴���ޣ�ҹ�˯���㣬���鷼�����£��ʣ�"+HIR"��������Ϊ���"+HIC"��\n"NOR,me,target);
        
        damage=300+(int)me->query_skill("rousi-whip")+random((int)me->query_skill("whip"));
        if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIW"$n��ǰ��ػ������涷�ޣ�������˳������������Ե��������飬�ٸ��������ᡣ\n"NOR,me,target);
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                target->receive_damage("jing",damage);
                target->receive_wound("jing",damage/2);
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n��ƽ���ͣ���ϥ�����������ͳ��������ƣ����Ŵ���˾���������������\n"NOR,me,target);
        }
        me->receive_damage("jing", 50);
        me->add("neili", -100);
	
	
}	


if ((int)me->query_skill("rousi-whip",1)> 800)
{
	        mystr=me->query_str() * 2;

              k=(int)me->query_skill("whip");
              damage_bonus=k;
              damage_bonus=mystr*(damage_bonus+100+me->query("jiali"))/209;
        message_vision(HIY"$N�����˺ۣ�ʹ���������޵�������û���ģ��Ҹ���ƴ��! ˵������$n�����������Լ�������!\n"NOR,me,target);
                     
                        if (random((int)me->query("per"))<10 || random((int)target->query("combat_exp")) > ((int)me->query("combat_exp"))) 
                                                  {

        message_vision(HIB"����$p������$P�����������ͼ��Ц��:�ұ������������壬������Σ�\n"NOR,me,target);

                                }
                                 else {
			msg="";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
               		damage=calculate_damage(me, target, 20, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("qi", damage);
                                 msg+=WHT"���$n"WHT"����һ���������Ŀ���$N��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���驧\n";
			msg +=HIB "   ������\n";
               		damage=calculate_damage(me, target, 40, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_wound("qi", damage);
                                msg+=WHT"���$n"WHT"��������飬������ͷ��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
               		damage=calculate_damage(me, target, 60, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("qi", damage);
                                msg+=WHT"���$n"WHT"�����Ŀ���$N���޵����ݡ�\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���⩧\n";
			msg +=HIB "   ������\n";
               		damage=calculate_damage(me, target, 80, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_wound("qi", damage);
                                msg+=WHT"���$n"WHT"����������⣬����ͨ�죬������֡�\n" NOR;
                    			}
                    			me->add("neili", -130);
                            message_vision(msg, me, target);
                                                 COMBAT_D->report_status(target);
                            }
	
}	


        me->receive_damage("qi", 50);
        me->add("neili", -130);



        me->start_busy(3);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

        damage=100+base_damage+(damage_bonus+random(damage_bonus));
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
                damage-=damage/3*2;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}