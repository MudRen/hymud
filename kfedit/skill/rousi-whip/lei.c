//rousi-whip
//perform lei ����ŭ��
//writted by jie 2001-2-10

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("mace",1);
        myskill1= (int)me->query_skill("rousi-whip",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        
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

        if((int)me->query_skill("rousi-whip", 1) < 350)
                return notify_fail("�����˿�ֱ޼��𻹲�����\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ŭ��ֻ����ս����ʹ�á�\n");
        if ((int)me->query("neili")<800)
                return notify_fail("�������������\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("neili",-300);
        me->receive_damage("jing", 20);
        message_combatd(HIC"$N��ʽһ��������"+weapon->name()+HIC"�·�����ǧ���Ƶģ�ʹ������˿�޷��ľ�ѧ--������ŭ�𡻣�\n\n" NOR,me,target,"");        
        message_combatd(CYN"$N���˵��ƽƽ�ҳ�һ�ޣ�����ȴ˻˻������֮����\n"NOR,me,target,"");
        message_combatd(CYN"��һ�С�����������Ю��������ȴ������է�֣����׺���������\n\n"NOR,me,target,"");
        if (random(myexp)>(int)(texp/8) && random(myforce) > (int)(tforce/4)) 
        {
                msg = HIC"$nֻ����һ�ɾ���������һ�㣬���������\n"
                      "���ۡ���һ����$n���һ�����Ѫ���������������ˣ�\n\n"NOR;
                damage= 100+(int)(((int)me->query("max_neili")/5+myforce -  (int)target->query("max_neili")/5 - tforce)/2);
                if (!userp(me) && damage>25000) damage=25000;
                if (damage >35000) damage=35000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg = HIC"$næ�˹��򿹣�����������$N�Ĺ��ƶ���ɢ�ˡ�\n\n"NOR;
                message_combatd(msg, me, target, "");
        }


        message_combatd(CYN"$N�ɾ�ת����һ���㼱��磬��̤���ţ��������У��ޱ޴�$n���벻���ķ�λ������Ϣ���ҳ���\n" NOR,me,target,"");
        message_combatd(CYN"��һ�С����׵�а�������칫��ŭ��Ҫ��������������������ʹ�ø�ʹ������\n\n" NOR,me,target,"");
        if(random(myexp)>(int)(texp/7)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
        {
                msg = HIC"$n������æ���ң���֪�����ȥ�м��⾲��ˮ�������ı޷���\n"
                      "����Ȼ��$N��"+weapon->name()+HIC"�������У�$n�������±��ҵı������ˣ�\n\n"NOR;
                damage=200+random(50)+me->query("jiali")+((int)me->query_skill("rousi-whip")*2);
                                if (!userp(me) && damage>25000) damage=25000;
                if (damage >45000) damage=45000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$nȴ�ľ���ˮ��˿�����Ի��ң����в��У��߽���$N�������Ĺ��ơ�\n\n"NOR;
                message_combatd(msg, me, target, "");
        }


        message_combatd(CYN"$NͻȻ��ס���Σ��ز������������ڱ�������ʤ���У�����ʤ���Ρ�\n"NOR,me,target,"");
        message_combatd(CYN"��һ�С�����ŭ�𡻰���˿�޷��ľ���Ҫּ���ӵغ���ˬ�죡\n\n"NOR,me,target,"");
        if(random(myexp)>(int)(texp/2))
        {
                msg = HIC"$n��Ȼɱޱ����Ϊ$N¶����������ϲ֮�£���æ��ǰ��������\n"
                      "$N΢΢һЦ����$n����������һ�����価�޳���ֱ̽$n���ؿڡ�\n"
                      "$n����Ӱ��û�������Ͳ���������͸������\n\n"NOR;
                damage=100+(int)(random((int)(myskill1/10))+me->query("jiali")+((int)me->query_skill("rousi-whip")*2));
                if (!userp(me) && damage>25000) damage=25000;
                if (damage >45000) damage=45000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$n���������е���ʵ�����ƾͼƣ���װ����ǰ��ȴ��$N���޵�һ˲���ڿ�Ծ�������־�����һ�У�\n\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(2);
        me->add("neili",-300);
     
        return 1;
}

