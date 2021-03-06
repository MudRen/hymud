// lingxi.c 灵犀一指

#include <ansi.h>

inherit F_SSERVER;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
string *xue_name1 = ({ 
        "大锥穴",
        "百会穴",
        "志室穴",
        "肩井穴",
        "劳宫穴",
        "内关穴",
        "外关穴",
        "会宗穴",
});
string *xue_name2 = ({
        "曲池穴",
        "冲阳穴",
        "臂儒穴",
        "白海穴",
        "灵台穴",
        "风府穴",
        "神风穴",
        "玉书穴",
}); 
string *xue_name3 = ({
        "青门穴",
        "商阳穴",
        "丝空竹穴",
        "气海穴",
        "冲门穴",
        "大椎穴",
        "百里穴",
        "槐阳穴",
}); 
string* xuedao = ({
	"巨骨穴",
	"地仓穴",
	"肩井穴",
	"颊车穴",
	"承泣穴",
	"风池穴",
	"章门穴",
	"风府穴",
	"精促穴",
	"陶道穴",
	"强间穴",
	"少海穴",
	"犊鼻穴",
	"神门穴",
	"华盖穴",
	"大椎穴",
	"凤尾穴",
	"至阳穴",
	"劳宫穴",
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"三阴交",
	"天柱穴"
});
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("灵犀一指只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("tanzhi-shentong", 1) < 100 )
		return notify_fail("你的弹指神通不够娴熟，无法使用灵犀一指。\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("灵犀一指须空手使用。\n");

	if ( (int)me->query("neili") < 400)
		return notify_fail("你的内力不够，无法使用灵犀一指。\n");

	msg = CYN "$N双手一前一后，缓缓伸出，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n";

	damage = (int)me->query_skill("tanzhi-shentong", 1) + (int)me->query_skill("bibo-shengong", 1) + 100;
	damage += random(damage);
	damage = damage + 300;
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n躲闪不及，“噗”地一声，被指劲击中前胸！\n";
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n胸口一阵巨痛，大叫倒地！\n" ;
//                msg += damage_msg(damage, "刺伤");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n向旁边一闪，让过了劲风，没想到这股指劲竟然有回力，从$n背后倒转回来，正刺中$p的后背。\n";
		target->receive_damage("qi", damage / 2);
		target->receive_wound("qi", damage / 2);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n觉的胸口有点痛！\n" ;
//                msg += damage_msg(damage, "刺伤");
//              msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else {
		msg += "$n向旁边一闪，让过了劲风，却忽然发觉这股指劲竟然有回力，匆忙中只好一个前扑才堪堪躲过，模样狼狈之极。\n" NOR;
	}
	message_vision(msg, me, target);


me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 1300);
if (random(3)==0) target->start_busy(3);
	msg = CYN "$N双手一前一后，缓缓伸出，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n";
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIY "$N扣住中指，哧哧哧连弹三下，三缕指风锋锐若剑，风驰电挚般射向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIC"$N扣起中指、无名指，一齐弹出，中指指劲激射$n"+xuedao[random(sizeof(xuedao))]+"，无名指上暗劲则已悄无声息的掩至"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg= HIR"$N双足不丁不八，踏着东方乙木之位，食中二指反扣住拇指，一声长啸，反手弹出，但见一股凌厉无极的指劲激射向$n的"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIB"$N冷哼一声，双手笼入袖中，脸上青气一闪即逝，几缕指风已无声无息的袭向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"数处要穴";
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIG"$N身子滴溜溜的打了半个圈子，丹田中提一口真气，青芒犹似长蛇般伸缩不定，蓦地真气突盛，刺向$n的"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);        
me->add_temp("apply/attack", -80);
me->add_temp("apply/damage", -1300);
	me->add("neili", -200);
	me->start_busy(2);

	return 1;
}
