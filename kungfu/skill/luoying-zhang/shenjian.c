// shenjian.c �һ�Ӱ�����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

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
        int damage, rand, p;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�һ�Ӱ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if (!(me->query("thd/perform") & 2))
//                return notify_fail("����Ȼ��˵�����һ�Ӱ����񽣡���һ�У�����ȴδ���ڡ�\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("��������ʹ���һ�Ӱ����񽣣�\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʹ���һ�Ӱ����񽣡�\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 80)
                return notify_fail("��ı̲��񹦻�򲻹����޷�ʩչ�һ�Ӱ����񽣡�\n");
        if ( (int)me->query("neili") < 120)
                return notify_fail("��������������޷�ʹ���һ�Ӱ����񽣡�\n");
        if ( me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("�������޷�ʹ���һ�Ӱ����񽣽��й�����\n");

        msg = CYN "\n$N˫������Ĭ�˱̲��񹦣���Ե���ƽ���һ������˿˿��"GRN"����"CYN"���ֱ����������ն��$n��\n"NOR;
        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/3 ) {
                me->add("neili", -100);
                me->start_busy(2);
                damage = (int)me->query_skill("luoying-zhang", 1)*2+random(damage/2);
                damage += random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n" + eff_status_msg(p) + " )\n";
                } 
        else {
                me->add("neili", -50);
                me->start_busy(1);
                msg += HIY"$n���һ�����˲�������־����п�����������У������ų���һ���亹��\n" NOR;
        }
        message_vision(msg, me, target);


me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 300);
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
me->add_temp("apply/damage", -300);

        return 1;
}
