#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int  myexp, yourexp,i,num,damage;
        object weapon;
        
        int enhance;
        string str;     

        object ob;
        int skill, skill2, ap, dp,kee_wound;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ý�âֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("��ʹ������ķ�!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("�������ķ�������������\n"); 

        if((int)me->query_skill("sanqing-jian",1) < 80)
                return notify_fail("������彣���ȼ���������\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);
        if( (int)me->query("max_neili") < 800)
                return notify_fail("�������̫��,�����³���â��\n");
        if( (int)me->query("neili") < 400)
                return notify_fail("������������ˣ�\n");

        if(me->query_temp("jianmang_busy"))
                return notify_fail("���ˣ���âû�з�����\n");
        myexp = (int)me->query("combat_exp");
        yourexp = (int)target->query("combat_exp");
        msg = HIC
        "\n$Nһ����Ц�����г���бָ���죬�����³�һ�ų������â���������԰�����������\n"
        "$n������䣬���Ž�âȴ�͵ñ��ǣ�����$n������ֱ�������\n\n" NOR;       
        message_combatd(msg, me, target, "");
        damage=me->query_temp("apply/damage")+me->query("force_factor");
        num=0;
        for (i=1;i<=7;i++) 
        {
                if( random(myexp)>random(yourexp))
                num++;
        }   
        if(num>0)         
        {
                damage=damage*num;
                

                
                msg = HIR
                "\nֻ��$nһ���Һ�,��â��$n�Ķ�ͷ�ӹ�,����һ��Ѫ�⣡\n" NOR;

                msg += HIW
                "\n��â���羭�������ʴ�ת��һת,�ַɻ�$N����ߡ�\n" NOR;
                message_combatd(msg, me, target, "");
if (damage > 32000) damage=32000;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);
/*
                //if (random(damage)>target->query_temp("apply/armor"))
                if (damage>target->query_temp("apply/armor"))
                target->receive_wound("kee",damage-target->query_temp("apply/armor"),me,"pfm");
*/
                COMBAT_D->report_status(target,1);
                if(!target->is_busy()) 
                        target->start_busy(1+random(2));
                //target->kill_ob(me);
  	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 2200);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -2200);


        }
        else 
        {
                msg = HIY
                "\n$nȴʶ�����Ž�â������,����ԶԶ����һ�ߡ�\n" NOR;
                message_combatd(msg, me, target, "");
                me->start_busy(2);
        }
        
        me->start_busy(2);
        
        me->add("neili",-150);
        me->set_temp("jianmang_busy",1);

if (me->query_skill("sanqing-jian",1) >= 300 || !userp(me))
{        
         message_combatd(HIC"\n$N�����񹦣�û����ʽ���ϣ���̤���ԣ�����һ��ת��һ�ߣ��������ս����ơ�\n"NOR,me,0,"");
        weapon->unequip();
        me->add_temp("apply/attack", 200);  
        me->add_temp("apply/damage",3800);        
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3800);
        weapon->wield();
        me->reset_action();
     me->add("neili",-20);
me->start_busy(2);
}        

if (me->query_skill("sanqing-jian",1) >= 600 || !userp(me))
{ 
	        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");
                msg = HIY "$N��Ȼ���������������������ὣ����ʱ�������ѣ����磭��
                \n"HIC"����ϼ���졻
                \n"HIY"����������Ƭ����ǵ���$n�����ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
              

 
                ap = ((me->query("combat_exp"))*(me->query_str()));
                dp = ((target->query("combat_exp"))*(target->query_str()))/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp || random(3)==0)
                {
                        msg = HIR "$n��ǰ�·�ӿ��������ɫϼ�⣬���֮�£�������Ƭ��ȻǶ����$n�����ϣ�\n\n$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 380 + skill + random(skill*2);

                        if(kee_wound > target->query("qi")) kee_wound = (target->query("qi") + 1);
                       
                        target->receive_damage("qi",kee_wound); 
                        target->receive_wound("qi", kee_wound);
                       
                        COMBAT_D->report_status(target, 0);

                        me->add("neili",-100);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬���������������Ľ�Ƭ��\n\n"NOR;
                        message_vision(msg, me, target);

                        me->add("neili",-50);
                }

                call_out("perform_qiao", 3, me);

                return 1;
        }
        else if(skill<180  )
        {
                msg = HIW "$N��Ȼ���������������һ���Ҫʩչ���彣�����Ͼ���֮һ�ġ���ϼ���족��
                \nȴ���Ϲ������㣬��Ȼû��������"+weapon->query("name")+HIW"��\n" NOR;
                msg += HIR "$n��Ҫ������ͻȻ���ֻ����ѵã���ʱ������������\n\n";
                message_vision(msg, me, target);
                me->add("neili",-50);

        }
        else
        {
                msg = HIW "$NͻȻ���������������"+weapon->query("name")+HIW"�����罣â���£�����һ��\n��Ȼʹ�������彣���ܴ�����
\n"HIC"��������ϼ��â������
\n\n"HIW"��㽣â�����ӿ���������壬��������������$n��\n\n" NOR;
                message_vision(msg, me, target);

                ap = me->query("combat_exp");
                dp = target->query("combat_exp")/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp || random(3)==0)
                {
                        msg = HIR "$n�Ը�������Ȼ�����޲ߣ������âǡ��������Ƭ������$n�����ϣ�\n\n$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 380 + skill + random(skill*2);

                        if(kee_wound > target->query("kqi")) kee_wound = (target->query("qi") + 1);
                        target->receive_damage("kee",kee_wound); 
                        target->receive_wound("kee", kee_wound);
                        COMBAT_D->report_status(target, 0);

                        me->add("neili",-100);
                }
                else
                {
                        msg = HIG "$n��Ȼ������������һ��ؼ��ɳ��죬���������������Ľ�â��\n\n"NOR;
                        message_vision(msg, me, target);

                        me->add("neili",-150);
                }

 

}        
        call_out("jianmang_ok",3+random(2),me);
        return 1;
}

void jianmang_ok(object me) 
{
        if (!me) return;
        me->delete_temp("jianmang_busy");
}






int perform_qiao(object me)
{
        object weapon, target;
        if (!me) return 1;
        target = me->select_opponent();
        
if (me && target)
{
        me->delete_temp("jianmang_busy");
        if(me->is_fighting() && living(target) && living(me))
        {
                object qiao;
                string msg;
                int count;
                count = me->query_str();
                me->add_temp("apply/attack", 200); 
	me->add_temp("apply/damage", 2200);

                count = me->query_str();
                //me->add_temp("str", count * 2); 
                msg = HIY "\n$NͻȻ�����Ͻ������õ����У���ʽͻȻ���٣�����㹥�����У���ͻȻ�ı仯��$nĿ�ɿڴ���\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->delete_temp("apply/attack", 200);
	me->add_temp("apply/damage", -2200);

                //me->delete_temp("str", count * 2);
        }
}
        return 1;
}
