#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,k,u,damage;
        string str; 
                object ob;
        string msg;
        int f_time;
        int myexp,yourexp,lvl;    
        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || target->is_corpse() || target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("����ڹ�̫�\n");
        if((int)me->query("neili") < 900 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

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


        k=50+(int)me->query_skill("canxin-jian",1);
        j=(int)target->query_skill("dodge");
        if(k<150)        
                return notify_fail("��Ľ������𻹲�����ʹ����һ�л������ѣ�\n");
        u=1+k/50;
        if (u>6) u=6;
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIB"\n$N��������һ����"NOR,me,target);
        message_vision(HIW"\n���ҿ˵�������һ����"NOR,me,target);
        message_vision(HIB"\nһɲ�Ǽ�ǧ�򽣹��ƿն�������������$n"NOR,me,target);
        for (i=0;i<u;i++)
        {
                //if (random(k+j)>j/2) 
                if (random(k+j)>j/3) 
                {
                        message_vision(HIY"\n$nһ������������һ��"NOR,me,target);
                        damage=k+random(100)+100;
                        target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage/2,me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi", 10);
                        me->add("neili", -30);
                }
                else 
                {
                        message_vision(HIY"\n$n�����������ò����ױܿ���һ�ֽ���"NOR,me,target);
                        //me->receive_damage("jing", 10);
                        me->add("neili", -30);
                }
        }
if (!random(4))
        {
                target->start_busy(2);
        }          
 
if ((int)me->query_skill("canxin-jian",1)> 360)
{ 
	 myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("canxin-jian",1)/40;
        
        msg = HIC
"\n$N��ɫ����,���н�â�ó���ʹ�â����������$n����Ȧȥ����һ�С��������¡�\n" NOR;
		        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 2500);
                message_combatd(msg + "\n", me, target, "");
                msg = HIM "$nֻ�����ɽ�����ס�Լ�,��ʱȫ��һ��,��������!!\n" NOR;
                
                message_combatd(msg, me, target, "");
                target->start_busy(2);
                msg=HIM"��һ����ʽ���һ�����紺���µĺ�¶Ϊ֮�ڻ�����$n��̾��"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIC"�ڶ�����ʽ���һ�����������������ޣ���$n�п���"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"��������ʽ���һ�����ƿں���¶��ȸ�������衢���ۣ���$n���Σ�"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

		        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -2500);
        me->add("neili", -50);
	
        
   }     

if ((int)me->query_skill("canxin-jian",1)> 880)
{ 
	if (random(2)==0) target->start_busy(2);
   me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3800);
        message_vision(HIW"\n$N���о���ʩչ�Ľ��ġ��Ķ�����������$n�������Ĺ�����\n"NOR,me,target);
        msg=HIR"�Ķ��Ķ������ķ��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"�Ķ��Ķ�������ŭ�ţ�"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"�Ķ��Ķ����Ľ���һ��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3800);

                if( living(target)) 
                        target->receive_damage("qi",2*((int)me->query_skill("canxin-jian",1)));
                        message_vision(HIR"\n$NͻȻʹ���Ľ��������У����ȶ�����\n$n�ܵ������ص��˺���\n"NOR,me,target);

        //me->receive_damage("qi", 100);
        me->add("neili", -50);

   }   
            
        me->start_busy(3);
        return 1;
}

