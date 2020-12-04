#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage,nd;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
        if((int)me->query("max_neili") < 800 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("neili") < 200 )
                return notify_fail("����������㣡\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        i=(int)me->query_skill("lunhui-zhang",1)+me->query_skill("staff",1)/2;
        j=(int)me->query_skill("lunhui-zhang",1);

        if(i<60 || j<10)        
                return notify_fail("����ֻ��ȼ��𻹲�����ʹ����һ�л������ѣ�\n");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIY"\n$N���з�ţ���ǧ����Ϊע������"+weapon->name()+NOR+HIY"��ʱ��ϼ�����䣬�յ�$n�������ۣ�\n"NOR,me,target);
        message_vision(HIW"\n                    ��������������� \n"NOR,me,target);
        message_vision(HIC"\n�Ҳ��������˭���������Ω��������ҳ�ס������
��Ω��ס����������ׯ�ϵ������뷢����Ը��������δ�գ��Ĳ��ɷ���
���Ⱦ�����֤���ᡣ\n"NOR,me,target);
                damage=me->query_skill("buddhism") + me->query_skill("staff") + (me->query_skill("lunhui-zhang")*2) ;
        nd=target->query("qi",1)/3;
        if (nd>15000) nd=15000;
        damage=damage+nd;
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) 
        {
if (damage> 60000) damage=60000;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);         
                me->receive_damage("jing", 100+random(50),me);
                me->receive_damage("qi", 100+random(50),me);
                COMBAT_D->report_status(target);
                COMBAT_D->report_status(me);            
                
        }

        me->add("neili",-180);
        me->start_busy(3);
        return 1;
}

