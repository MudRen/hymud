#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int damage, ap, dp;
        object weapon;
        extra = me->query_skill("bainiao-jian",1);

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "honghua-shengong")
                return notify_fail("��ʹ�ú컨��!\n");

        if((int)me->query_skill("honghua-shengong",1) < 200)
                return notify_fail("��ĺ컨�񹦻�����������\n"); 

        if ( extra < 200) return notify_fail("��İ��񽣷����������죡\n");     
       
        if( (int)me->query("neili") < 800 )      
                return notify_fail("�������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾Ž������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",1800);
        me->add("neili", -50);
        weapon = me->query_temp("weapon");
        if(!target->is_busy()) target->start_busy(2);
        message_vision(RED  "\n\n$N�ڿ�Ծ�𣬱任���Σ�˲�Ʊ�������λ�����е�"+ weapon->name() +RED"����ɭȻ��������������$n ��\n\n" NOR, me, target);
        message_vision(HIC  "���������졹��$N����"+ weapon->name() +HIC"����һ����ֱ��$n��" NOR, me, target);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n�������ɢ����$N����"+ weapon->name() +HIR"��������Ľ���б��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n���������졹��$N����"+ weapon->name() +HIY"��Ҷ���ɨ$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n��ʮ����ħ����$N����"+ weapon->name() +HIW"���������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n��Ⱥħ���衹��$N����"+ weapon->name() +MAG"Я��������ֱ��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n��������������$N����"+ weapon->name() +HIY"Ѹ�װ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG  "\n�������˼䡹��$N����"+ weapon->name() +HIG"��Ȼ��Ϊһ����������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC  "\n��ħӰ��������$N����"+ weapon->name() +HIC"������������$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n��ħ����Ӱ����$N����"+ weapon->name() +HIM"��Ϊ��ǧ��Ӱ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n$N�ս����ˣ�����"+ weapon->name() +RED"����������������,��һ��"+HIW"���Ž����ꡱ��" NOR, me, target);
       me->add("neili",-50);
        
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-1800);

        if ((int)me->query_skill("bainiao-jian",1) > 550)
        {
        me->add("neili", -50);
        msg = HIW
 "\n$N���ν���������ͻȻһ��ŭ�ȣ����еĽ��û���һƬ����
˲������ʮ����һ���޴��
"RED"
           ]@         
           ]b      ____        ]@
           ][      @~~~~J[~    ]@
        ___ P____  ]    i[     ]@
       ~~~~]@~~~   J_____U  d  ]@
           ][   /'__ J___   ]i ]@
           ]@'J~ ~~~~]~~d[' jl ]@
           d[       d[  ]@  J[ ]@
         ]%][       d'  ][  i' ]@
      _d~  ]@      a'   d[     ]@
           ][    _r~    ad     ]a
           J[   ~     _a'      J[
          _r                  J~ 
"NOR"\n"HIW"�ָ�����$n��ǰ��\n"NOR;

        ap = me->query_skill("bainiao-jian", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1200 ) {
  msg += HIY "$n��æ������������Ǳ��Ķ㿪�������İ˽���\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = 50+(int)me->query_skill("bainiao-jian",1)*2 +
        (int)me->query("jing") / 200 + random((int)me->query("jing") / 150 ) +
        (int)me->query("qi") / 250 + random((int)me->query("qi") / 150 );
  msg += HIR "\n$n��ʱ�����������İ˽����У�\n\n" NOR;
     damage +=random(10);
                        target->receive_damage("jing", damage/3);
                        target->receive_damage("qi", damage);
       target->receive_wound("qi", damage/2);
                        
           message_vision(msg, me, target);
      }
    }	
       me->start_busy(3);
        return 1;
}

