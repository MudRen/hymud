#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define ZHUAN "��" HIR "תǬ��" NOR "��"

inherit F_SSERVER;
string *xue_name1 = ({ 
        "��׶Ѩ",
        "�ٻ�Ѩ",
        "־��Ѩ",
        "�羮Ѩ",
        "�͹�Ѩ",
        "�ڹ�Ѩ",
        "���Ѩ",
        "����Ѩ",
});
string *xue_name2 = ({
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�׺�Ѩ",
        "��̨Ѩ",
        "�縮Ѩ",
        "���Ѩ",
        "����Ѩ",
}); 
string *xue_name3 = ({
        "����Ѩ",
        "����Ѩ",
        "˿����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "����Ѩ",
        "����Ѩ",
}); 
string* xuedao = ({
	"�޹�Ѩ",
	"�ز�Ѩ",
	"�羮Ѩ",
	"�ճ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"����Ѩ",
	"�縮Ѩ",
	"����Ѩ",
	"�յ�Ѩ",
	"ǿ��Ѩ",
	"�ٺ�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
});
int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage,skill;
        string msg;
        string pmsg;

	object weapon2;
	int wound,p;
	
skill=(int)me->query_skill("tanzhi-shentong", 1);
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHUAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 220)
                return notify_fail("��ĵ�ָ��ͨ������죬����ʩչ" ZHUAN "��\n");

        if ((int)me->query_skill("qimen-wuxing", 1) < 200)
                return notify_fail("�������������Ϊ����������ʩչ" ZHUAN "��\n");
 
        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("��û�м�����ָ��ͨ������ʩչ" ZHUAN "��\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("��û��׼����ָ��ͨ������ʩչ" ZHUAN "��\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("��İ�Ӱ������̫ǳ��\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("���������Ѩ�ֻ��̫ǳ��\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("�����Ӣ�񽣻��̫ǳ��\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("�����Ӣ���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("��ĵ�ָ��ͨ���̫ǳ��\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("�������ɨҶ�Ȼ��̫ǳ��\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("������｣�����̫ǳ��\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("����������Ի��̫ǳ��\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("����������л��̫ǳ��\n");
        if (me->query("max_neili") < 3500)
                return notify_fail("���������Ϊ���㣬����ʩչ" ZHUAN "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�����ڵ���������������ʩչ" ZHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "��ȫ��������һָ��ָ�����ն�ʮ���޷�λ�ƹ��������"
              "���һ�����" HIR "תǬ��" HIC "��������\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("qimen-wuxing", 1);
        dp = target->query_skill("dodge") + target->query_skill("qimen-wuxing", 1);

        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(2);
                        msg += HIR "���Ǽ�$n" HIR "ֻ����âһ����$N" HIR "ʳָ"
                               "������$p" HIR "ӡ�ð�ߣ�ָ����ʱ���Զ��롣\n"
                               HIW "���������ۡ���һ�������Ͼ�Ȼ���������Խ���"
                               "\n" NOR "( $n" RED "���˹��أ��Ѿ�������в���"
                               "����ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else
                {
                        me->start_busy(3);
                        damage = me->query_skill("finger");
                        me->add("neili", -500);
target->add("qi",-damage*3);
target->add("eff_qi",-damage*2);

                        msg +=HIR "���Ǽ�$n" HIR "ֻ����âһ����$N"
                                                   HIR "ʳָ������$p" HIR "���ð�ߣ�ָ��"
                                                   "��ʱ������롣\n���������͡���һ����"
                                                   "���Ͼ�Ȼ����������Ѫ��\n" NOR;

                }
        } else
        {
                me->start_busy(3);
                me->add("neili", -300);
                msg += CYN "$p" CYN "��$P" CYN "��ʽ���أ����д�"
                       "�⣬��ʱ���Ծ���ɣ�����������\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
        {
                target->receive_wound("qi", 9000);
                target->receive_wound("jing", 2000);
                //target->die(me);
        }

        msg = HIG "\n������ ͻȻ��$N" HIG "ָ��һת������ָ�⡰�͡��ĵ���һ����â��ֱϮ$n"
              HIG "������Ѩ��\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        damage = me->query_skill("finger");

        if (ap * 3 / 2 + random(ap) > dp)
        {
                target->receive_damage("jing", damage+100);
                target->receive_wound("jing", damage+100);
                target->add("neili", -damage * 3);

                if (target->query("neili") < 0)
                        target->set("neili", 0);

                msg += HIR "$n" HIR "ֻ��$N" HIR "ָ��Ϯ�壬�漴����һ"
                       "��������ٸ�������ɢ�������ʡ�\n" NOR;
                me->start_busy(3);
        } else
        {
                msg += CYN "����$p" CYN "�������ܣ������Ż�����ʱ��$P"
                       CYN "�Ĺ��ƻ�Ϊ���С�\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
    msg = HIC "\n���$N" HIC "��ָ�ᵯ��ֻ���ƿ���������һöʯ�Ӽ��ٷɳ�" +
             "������$n" HIC "��\n" NOR;

        me->start_busy(2);
        ap = me->query_skill("finger") + me->query_skill("throwing");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "ʯ�����úÿ죬$n"
                       HIR + "һ�����ܲ����������˸����У�����һ"
                       "���ʹ�������˼�����Ҫɢ���ˡ�\n" NOR;
                target->receive_damage("qi", damage+skill  + random(skill)+100);
                target->receive_wound("qi", damage+skill  + random(skill)+100);
                COMBAT_D->clear_ahinfo();

                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "����$p" CYN "����һ���������$P" HIG "������ʯ�ӡ�\n" NOR;
                message_combatd(msg, me, target);
        }
me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1500);
if (random(3)==0) target->start_busy(3);
	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIY "$N��ס��ָ���������������£�����ָ�������������۵�ֿ������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIC"$N������ָ������ָ��һ�뵯������ָָ������$n"+xuedao[random(sizeof(xuedao))]+"������ָ�ϰ�������������Ϣ������"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg= HIR"$N˫�㲻�����ˣ�̤�Ŷ�����ľ֮λ��ʳ�ж�ָ����סĴָ��һ����Х�����ֵ���������һ�������޼���ָ��������$n��"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIB"$N���һ����˫���������У���������һ�����ţ�����ָ����������Ϣ��Ϯ��$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"����ҪѨ";
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIG"$N���ӵ�����Ĵ��˰��Ȧ�ӣ���������һ����������â���Ƴ��߰������������������ͻʢ������$n��"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);        
me->add_temp("apply/attack", -100);
me->add_temp("apply/damage", -1500);

if (skill>300 && me && target)
{
	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";

	damage = (int)me->query_skill("tanzhi-shentong", 1) + (int)me->query_skill("bibo-shengong", 1) + 100;
	damage += random(damage);
	damage = damage + 300;
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 || random(3)==0) {
		msg += "$n�������������ۡ���һ������ָ������ǰ�أ�\n";
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�ؿ�һ���ʹ����е��أ�\n" ;

	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n���Ա�һ�����ù��˾��磬û�뵽���ָ����Ȼ�л�������$n����ת������������$p�ĺ󱳡�\n";
		target->receive_damage("qi", damage / 2);
		target->receive_wound("qi", damage / 2);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�����ؿ��е�ʹ��\n" ;

	}
	else {
		msg += "$n���Ա�һ�����ù��˾��磬ȴ��Ȼ�������ָ����Ȼ�л�������æ��ֻ��һ��ǰ�˲ſ��������ģ���Ǳ�֮����\n" NOR;
	}
	message_vision(msg, me, target);	
	
}	

if (skill>600 && me && target)
{
	msg = HIC "$Nʹ����ָ��֮ͨ����ָ���ס�, ��ʱ���ھ��Ⱪ�䣬\n";
	message_combatd(msg, me, target);
 
	dp = target->query("combat_exp");
	if( dp < 1 )
		dp = 1;
	if( random(me->query("combat_exp")) > random(dp) || random(3)==0) 
	{
		if(userp(me))
			me->add("neili",-150);
		msg = "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n" ;
		if ( objectp(weapon2 = target->query_temp("weapon")))
		{
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
			msg += "ͬʱ����һ�飬����";
			msg += weapon2->name();
			msg += "���ֶ�����\n" NOR;
			weapon2->move(environment(me));
}
		}
		wound = 300 + random(200);
		if((int)target->query("neili") < wound)
			wound = target->query("neili");
		if (wound>100000) wound=100000;
		target->add("neili", -wound);
		target->receive_wound("jing", wound/5);
		target->receive_wound("qi", wound/5);
		target->start_busy(8);
		me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�\n"NOR;
		me->start_busy(1);
		message_combatd(msg, me, target);
	}
}

        return 1;
}

