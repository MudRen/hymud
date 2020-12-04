#include <ansi.h>
#define DUO "��" HIC "�������Ծ�" NOR "��"
inherit F_SSERVER;

int check_fight(object me, object target, object weapon, int skill);
void remove_effect(object me, object target, object weapon, int skill);

int perform(object me, object target)
{
        string msg;

        int ap, dp;
        int damage;
        
	int skill = me->query_skill("yinlong-bian", 1);
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ƾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query_skill("yinlong-bian",1) < 100)
                return notify_fail("��ľ��������޻�������죬����ʹ�ò��ƾ���\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return notify_fail("�������޷�ʹ�ò��ƾ���\n");

        if( me->query("neili") < 1500 )
                return notify_fail("�������������\n");

      msg = HIW "$N" HIW "�����һЦ������" + weapon->name() +
              HIW "����һ��������Ȼ����$n" HIW "�����Ǿ����澭�е�"
             "���С�" HIC "�������Ծ�" HIW "����\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (ap * 11 / 20 + random(ap) > dp || random(3)==0)
        {
                damage = ap + random(ap)+100;
                me->add("neili", -100);
                me->start_busy(2);
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "���$n" HIR "һ���ҽУ�δ�ܿ���$N"
                                           HIR "����ͼ������һ��Ӳ�����ؿڣ���Ѫ��"
                                           "����Ƥ��������\n" NOR;

                message_combatd(msg, me, target);
                
        } else
        {
                me->start_busy(2);
                msg += CYN "����$p" CYN "����һԾ���𣬶�ܿ���"
                       CYN "$P" CYN "�Ĺ�����\n" NOR;
                message_combatd(msg, me, target);
        }

if (!target->is_busy())
{
	msg = HIG "$Nʹ�����ƾ�������һ����$n��˫�Ⱦ�ȥ��\n";

        me->start_busy(2);
        if((random(me->query("combat_exp")) > target->query("combat_exp")/3) 
          )
        {
		msg += HIY "���$p��$Pһ�������ȱ����ʵʵ�����������ڵ����޷�����\n" NOR;
                target->start_busy(2);
		target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry", -skill/3);
		target->add_temp("apply/armor", -skill/3);
		me->set_temp("jiuyin/chan", 1);
	        //me->start_perform(1, "���ƾ�");
		remove_call_out("check_fight");
	        call_out("check_fight", 1, me, target, weapon, skill);
		remove_call_out("remove_effect");
	        call_out("remove_effect", skill/20, me, target, weapon, skill);
        } 
        else {
                msg += HIW "����$p������$P�Ĳ��ƾ�������һԾ��㿪�ˡ�\n" NOR;
	        //me->start_perform(8, "���ƾ�");
                me->start_busy(2);
        }
}        
        message_vision(msg, me, target);
        me->add("neili", -100);
        return 1;
}

int check_fight(object me, object target, object weapon, int skill)
{
        string msg;
        object wep;
	int neili, jiali;

        if (!me) return 1;
        if (!me->query_temp("jiuyin/chan")) return 1;

        if(!living(me) || !target){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "whip"){
           remove_effect(me, target, weapon, skill);
           return 1;
           } 
        if(environment(me) != environment(target)){
           remove_effect(me, target, weapon, skill);
           return 1;
        }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           
        if(wep != weapon){
           remove_effect(me, target, weapon, skill);
           return 1;
	   }
       if (userp(me) && me->query_skill_mapped("whip") != "yinlong-bian"){
           remove_effect(me, target, weapon, skill);
           return 1;
           }   
       if( me->query("neili") <= me->query_skill("yinlong-bian", 1)/2 ){
           remove_effect(me, target, weapon, skill);
           return 1;
           }           

       target->start_busy(2);
       //me->start_perform(3, "���ƾ�");
       if (!random(3) && me->query_skill("jiuyin-zhengong", 1) > 150) {
	   message_vision(HIB"$N����$n��æ����֮�ʣ���Ȼ����һ�С�\n"NOR, me, target);
	   me->add_temp("apply/attack", 200);
	   me->add_temp("apply/damage", 3000);
	   neili = me->query("neili");
	   jiali = me->query("jiali");
	   me->set("jiali", me->query_skill("jiuyin-zhengong", 1));
	   weapon->unequip(); 
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	   weapon->wield();
	   me->set("jiali", jiali);
	   //me->set("neili", neili-100);
	   me->add_temp("apply/attack", -200);
	   me->add_temp("apply/damage", -3000);
       }
       call_out("check_fight", 1, me, target, weapon, skill);
       return 1;
}       

void remove_effect(object me, object target, object weapon, int skill)
{
	if (!me->query_temp("jiuyin/chan")) return;
        me->delete_temp("jiuyin/chan");
	if (!target) return;
	message_vision(HIW"$n˫����һ�þ���������"+weapon->name()+"���������ӵ�������������\n"NOR, me, target);
	target->add_temp("apply/dodge", skill/3);
	target->add_temp("apply/parry", skill/3);
	target->add_temp("apply/armor", skill/3);
}
