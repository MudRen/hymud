// lingxi.c ��Ϭһָ

#include <ansi.h>

inherit F_SSERVER;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
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
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��Ϭһָֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("tanzhi-shentong", 1) < 100 )
		return notify_fail("��ĵ�ָ��ͨ������죬�޷�ʹ����Ϭһָ��\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("��Ϭһָ�����ʹ�á�\n");

	if ( (int)me->query("neili") < 400)
		return notify_fail("��������������޷�ʹ����Ϭһָ��\n");

	msg = CYN "$N˫��һǰһ�󣬻����������ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";

	damage = (int)me->query_skill("tanzhi-shentong", 1) + (int)me->query_skill("bibo-shengong", 1) + 100;
	damage += random(damage);
	damage = damage + 300;
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n�������������ۡ���һ������ָ������ǰ�أ�\n";
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�ؿ�һ���ʹ����е��أ�\n" ;
//                msg += damage_msg(damage, "����");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n���Ա�һ�����ù��˾��磬û�뵽���ָ����Ȼ�л�������$n����ת������������$p�ĺ󱳡�\n";
		target->receive_damage("qi", damage / 2);
		target->receive_wound("qi", damage / 2);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�����ؿ��е�ʹ��\n" ;
//                msg += damage_msg(damage, "����");
//              msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else {
		msg += "$n���Ա�һ�����ù��˾��磬ȴ��Ȼ�������ָ����Ȼ�л�������æ��ֻ��һ��ǰ�˲ſ��������ģ���Ǳ�֮����\n" NOR;
	}
	message_vision(msg, me, target);


me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 1300);
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
me->add_temp("apply/attack", -80);
me->add_temp("apply/damage", -1300);
	me->add("neili", -200);
	me->start_busy(2);

	return 1;
}
