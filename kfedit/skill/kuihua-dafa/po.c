#include <ansi.h>
#include <combat.h>

#define PO "「" HIW "破元剑闪" NOR "」"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 

int perform(object me, object target)
{
        int damage,neili;
        string msg, name;
        object weapon;
        int lvl, ap, dp;

        int i,j;
        int skill;
        int count;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);
        
        if (weapon && weapon->query("skill_type") != "sword"
           && weapon->query("skill_type") != "pin")
                return notify_fail("你使用的武器不对，难以施展" PO "。\n");

        if ((int)me->query_skill("kuihua-dafa", 1) < 180)
                return notify_fail("你的葵花神功不够娴熟，难以施展" PO "。\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("你的葵花心法太低了。\n");
               
        if ((int)me->query("max_neili") < 2600)
                return notify_fail("你的内力修为不足，难以施展" PO "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不足，难以施展" PO "。\n");

        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("你没有准备使用葵花神功，难以施展" PO "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");


        if (me->query_temp("weapon"))
                name = "手中" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIW "$N" HIW "一声冷哼，双眸间透出一丝寒气，" + name +
              HIW "化作千百根相似，幻出死亡的色彩！\n" NOR;

        ap = me->query_skill("sword") +
             me->query_skill("dodge");

        dp = target->query_skill("parry") +
             target->query_skill("dodge");
neili=target->query("neili")/2;
if (neili>28000) neili=28000;
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap)+100;
                target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                target->add("neili",-neili);
                msg +=HIR "$n" HIR "只觉眼前寒芒一闪而过，随即全身一阵"
               "刺痛，几股血柱自身上射出。\n$p陡然间一提真气，"
               "竟发现周身力道竟似涣散一般，全然无法控制。\n" NOR;
                me->start_busy(3);
                me->add("neili", -100);
        } else
        {
                msg += CYN "$n" CYN "大惊之下全然无法招架，急忙"
                       "抽身急退数尺，躲开了这一招。\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        }
        message_vision(msg, me, target);

if (skill>300 && me && target)
{
        msg = HIR "\n$N" HIR "一声尖啸，身体猛然旋转不定，" + name +
              HIR "顿时化成无数气流，犹如千万根银针，齐齐卷向$n" HIR "！\n" NOR;
        i = 4;
        if (lvl / 2 + random(lvl) > (int)target->query_skill("dodge") || random(3)==0)
        {
                msg += HIR "$n" HIR "只觉眼前无数寒光闪过，随即全身一阵"
               "刺痛，几股血柱自身上射出。\n$p陡然间一提真气，"
               "竟发现周身力道竟似涣散一般，全然无法控制。\n" NOR;
                count = me->query_skill("kuihua-dafa", 1);
                i += random(6);
        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "身法好快，哪里"
                       "敢怠慢，连忙打起精神小心应对。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
me->set_temp("action_flag", 1);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 5 && ! target->is_busy())
                        target->start_busy(1);
j=j+1;
	msg = HIY "$N身形奇快无比，接连向$n攻出第"+chinese_number(j+1)+"招！！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
me->delete_temp("action_flag");
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
	
}	
	
	

        return 1;
}

