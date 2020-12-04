// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIW "������" NOR "��"



inherit F_SSERVER;


string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string final(object me, object target, int damage);

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        skill = me->query_skill("shenghuo-ling", 1);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õı������ԣ�����ʹ��ʥ���֮" LIAN "��\n");

        if (skill < 150)
                return notify_fail("���ʥ����ȼ�����, ����ʹ��ʥ���֮" LIAN "��\n");

        if (me->query("max_neili") < 500 )
                return notify_fail("���������Ϊ���㣬����ʹ��ʥ���֮" LIAN "��\n");

        if (me->query("neili") < 300 )
                return notify_fail("�����������������ʹ��ʥ���֮" LIAN "��\n");

        if (me->query_skill_mapped("sword") != "shenghuo-ling") 
                return notify_fail("��û�м���ʥ���������ʹ��ʥ���֮" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����ͷ���$n" HIW "��ǰ����Ȼʹ��ʥ��"
              "�֮���������" + weapon->name() + NOR + HIW "����"
              "��������ʽ�����ޱȡ�\n" NOR;

        damage = me->query_skill("sword");
        
        ap =me->query_skill("sword");
        dp = target->query_skill("dodge");


        if (ap * 11 / 20 + random(ap) > dp || random(3)==0)
        {
                me->add("neili", -50);



       target->receive_wound("qi", (damage*2),me);
       target->receive_damage("jing", damage / 2,me);
       target->receive_wound("jing", damage / 4,me);
       target->start_busy(1);
                msg += HIR "$n" HIR "ֻ����ǰ���������ͻ"
              "Ȼ$N" HIR "˫�ֳ������Լ���ǰ������̫��Ѩ��"
              "ʱһ���ʹ��\n" NOR;

                       
        }
        else
        {
                me->add("neili", -100);
                msg += CYN "$n" CYN "����ǰ�����������æ����������ǿ"
                      "�ֵ���������������ò�����������$N" CYN "��"
                      "����Χ֮�⡣\n" NOR;
        }
        
        message_combatd(msg, me, target);
if (me && target)
{
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 500);
message_vision(HIG"\n$N��Ȼ����һ�䣬ֻ��һ���͸���룬�ֱ�Ϯ��$n���ߴ�ҪѨ��\n"NOR,me,target);
msg = HIW"��һö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIM"�ڶ�ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = MAG"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = YEL"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIB"����ö͸���룺"WHT"��"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"��\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -500);
}
                        me->start_busy(2);
        return 1;
}

