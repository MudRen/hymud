#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string get_name(string str)
{
        str="�ݷ���ʽ";
        return str;
}
string* skill_head1 =({
        HIW"$N�������ˣ�ʹ��һ�� �����Ͼ�¯",
        HIW"$N���쳤Ц����Ҳ������һ�� �¶�������",
        HIW"$Nһ��������ʹ�� ̸Ц�����",
        HIW"$Nһ���޺ȣ���һ�� �������޸�",
        HIW"$Nʹ�� ǧ��������",
        HIW"$N����������ƣ�һ�� Ǭ��һ��",

});

string* skill_tail1 =({
        HIW"������$wӭ��һ��������$n��ͷ�������ҽ�������",
        HIW"������һ����$n��ͷ���¡�",
        HIW"��Խ��$nͷ��������$w�ո���Բ��������һ������$n$l��",
        HIW"������$nһ�֮�䣬$N����$w���Ǻ�Х������ɨ��$n��$l��",
        HIW"���Ų����ԣ���һ������һ����\n���$n��æ���ң��мܲ�����",
        HIW"������$wת����糵һ�㣬\nһ�������Ӱ���л���$n���š�",
});

string get_help(string str)                
{
        str="ָ��: ��������������\n"
        +"�������Ͷ����������120���������������1200��ÿ��һ������100�����200������"
        +"Ѹ����Է��������У����������ù�����һ���⡣";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        	string msg;
        int extra;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��ݷ���ʽ����\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(!me->is_fighting())
                return notify_fail("���ݷ���ʽ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 1200 )
                return notify_fail("�������������\n");
        if((int)me->query("jing") < 600 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("buddha-club", 1) < 120)
                return notify_fail("����Ͷ�������𻹲�����ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_combatd(HIC"\n$N���㾫������һתʹ����̨ɽ��ѧ"HIW"���ݷ���ʽ��"NOR+HIC"������$n���������У�\n"NOR,me,target,"");
        extra=(int)me->query_skill("buddha-club", 1);
if (extra>=300) extra=300;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2200); 

        if(!target->is_busy())
                target->start_busy(1);
        

	msg = skill_head1[0]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[1]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[2]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[3]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[4]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[5]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2200);

        //me->receive_damage("jing", 100);
        me->add("neili", -100);

        me->start_busy(2);
        return 1;
}



