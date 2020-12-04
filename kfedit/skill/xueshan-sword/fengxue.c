#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object ob;
        object weapon;
        string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        skill = me->query_skill("xueshan-sword",1);
        ob=me->query_temp("weapon");
        if( !target ) target = offensive_target(me); 

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n"); 

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ����������������"+HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"��\n");

        if((int)me->query_skill("xueshan-sword",1) < 150)
                return notify_fail("���ѩɽ����������죬ʹ����"+HIC"����"HIW"ѩ"HIC"�ؽ���"NOR+"��\n");

        if((int)me->query("neili") < 220)
                return notify_fail("�����������ڲ����� \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        msg = HIC "$N�ؽ����裬���Ʋ��ϼӿ죬������Х��ɢ����ƬƬѩ�����磬ƮȻ������\n�γ�һ��ѩ�������У���$n�������\n";
        if(random(me->query_skill("sword",1)+me->query_skill("xueshan-sword",1)+me->query_skill("dodge",1)) > ((int)target->query_skill("dodge",1))) {
                msg +=HIG "$nֻ��������ѹ��Խ��Խ�󣬵��������������������������á�\n" NOR;
                target->start_busy( (int)me->query_skill("xueshan-sword",1) / 50+2);
                me->add("neili", -100);
        } else {
                msg +=HIR "����$n����������ѩ����ʱȫ���ܽ⣬һƬ��ʣ���ѳ���Χ��\n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
if (skill>=300)
{
  msg = HIW 
    "\n$N��Хһ��,ʹ������÷Ʈ�㡹,���б�������,�������ѩ����ǰ����ǵص���ȥ��\n"
    "�ڰ�ãã��һƬ��,��Ȼ�������÷���ν���,��͸ѩĻ,������˷����������\n" NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp || random(3)==0)
        {
            if(userp(me))
        msg = HIC 
    "����÷���⻪,�ó���������,��$nȫ�������ֵ�����ʵʵ��$n��������,\n"
    "ֻ����������,���Լ�����˿˿����,һʱȫ���ʹ,��Ѫ�ɽ��õ������ǡ���ͬ���֮��,\n"
    "�Ҳ����ԡ�\n" NOR; 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
target->apply_condition("cold_poison",50);
target->apply_condition("ill_shanghan",50);
target->apply_condition("ice_poison",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);
        }
        else
        {
            if(userp(me))
            msg = "����$n��ݵ����Ա�һ�����ܹ�����һ����\n"NOR;
        }
}        
if (skill>=600)
{
	me->add_temp("apply/damage",500);
	if (!target->is_busy()) target->start_busy(2);
weapon=me->query_temp("weapon");
         msg = HIW "��ѩ�ŵ㣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "��֦��б��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "������Ӱ��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "����˫÷��\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "÷ѩ������\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "��Ӱ���㣡\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);	
	me->add_temp("apply/damage",-500);
}	


        return 1;
}

