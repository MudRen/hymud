// chan.c ������ by stey

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;
int wound;

        int myskill,times;
        string number;
        myskill = (int)me->query_skill("bainiao-jian", 1);  

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ú컨��!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("��ĺ컨�񹦻�����������\n"); 


        if((int)me->query_skill("bainiao-jian", 1) < 150)
                return notify_fail("��İ��񽣷����𻹲�����ʹ����һ�л������ѣ�\n");

        if( me->query("con") < 20 || me->query("str") < 28 )
            return notify_fail("�������������������, ����ʹ�á�����������\n");

        me->clean_up_enemy();
        target = me->select_opponent();
        skill = me->query_skill("bainiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������\n");

        if( skill < 150)
            return notify_fail("��İ��񽣷��ȼ�����, ����ʹ�á�����������\n");




        if( me->query("neili") < 300 )
            return notify_fail("��������������޷����á�����������\n");

        msg = HIC "$N���е�"YEL+weapon->query("name")+HIC"����һ����⣬б��һ����������������
"YEL+weapon->query("name")+HIC"�������ò���$n��"+weapon2->name()+"�ϡ�\n";
    message_combatd(msg, me, target, "");

        damage = 200 + random(skill);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n��ʱ������ǰ���һ��������һ������";
            msg += weapon2->name();
            msg += "���ַɳ���\n" NOR;
            me->start_busy(random(2));
            target->receive_damege("qi", damage);
            target->start_busy(3);
            weapon2->unequip();       
        }
        else
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n����������������" + weapon2->name()+
"бб˳��һ��һ����˻�����\n"NOR;
            me->start_busy(3);
        }
    message_combatd(msg, me, target, "");
 if ((int)me->query_skill("bainiao-jian",1) > 200)
{
         damage = random((int)me->query_skill("sword")/3);
 message_vision(HIC"$Nʹ�����񽣷���Ҫּ�������� �ǳ�����������������������ʽ�ۼ���ѭ��$n��ȥ��\n"NOR,me,target, "");
           if (!target->is_busy()) target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   target->receive_damege("jing", damage/2);
                target->receive_damege("qi", damage+100);
        target->receive_wound("qi", random(damage));
     message_vision(HIC"$N���������ʹ�����У�������չ.\n"NOR,me,target, "");   
        me->add("neili",-50);
}               

 if ((int)me->query_skill("bainiao-jian",1) > 380)
{
   if(myskill <260){
                times = 1;        
                number = "һ";}
            else
                if (myskill <380){
                    times = 2;
                    number = "��";}
                else
                    if(myskill <420 ){
                           times = 3;
                           number = "��";}
                else
                    if(myskill <560 ){
                           times = 4;
                           number = "��";}
                else
                    if(myskill <660 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}
      damage = random((int)me->query_skill("sword")/3);

       message_vision(HIM"\n$NͻȻ����һ�䣬���е�"+ weapon->query("name")+ HIB"��Ӱ���٣������籡�������Ľ������������$n������"+number+"����\n"NOR,me,target, "");

        for(int i=1;i<=times;i++)
        {
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
   		target->receive_damege("jing", damage/3);
                target->receive_damege("qi", damage+1);
        target->receive_wound("qi", random(damage));
message_vision(HIR"\n���$n��$N�ġ����ɵ� �ǳ������������ģ���ǰһ�ڣ��������ɳ�������\n\n $n���Ͻ�����Ѫӿ��......\n" NOR,me,target,"");
                COMBAT_D->report_status(target, 0);
        }
}       
me->add("neili",-50);
me->start_busy(2);

        return 1;
}
