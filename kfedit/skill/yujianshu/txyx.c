// tie@fengyun
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{

        string msg;

        int i, lmt, damage,j ;
        object weapon;
        int ap, dp,qixue,eff_qi,max_qi,qi_pcg;
        
        if( (int)me->query_skill("sword") < 90 ||
            me->query_skill_mapped("sword") != "yujianshu")
                return notify_fail(HIW "������Ž���������\n"NOR);
        if ((int)me->query("neili",1) < 500)
                return notify_fail("��������������޷�ʹ�á�������ѩ����\n");           

 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("��ʹ����ʯ��!\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("�����ʯ�񹦻�����������\n"); 

        if((int)me->query_skill("yujianshu",1) < 150)
                return notify_fail("��������书������������\n"); 

        weapon = me->query_temp("weapon");
        msg = HIY  "$N��Хһ�������ж�Ю����֮ʽ�������͵ı������ߣ����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
        message_vision(msg,me,target);
                damage = 100+me->query_skill("yujianshu",1) + (int)me->query_skill("panshi-shengong", 1);
                damage = damage - random( target->query_skill("dodge")/3 );
        lmt = random(6)+4;
        		       me->add_temp("apply/attack", 80);    
        me->add_temp("apply/damage", 1800);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIW "$N���һ�����ӵ�"+chinese_number(i)+"����\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -80);    
        me->add_temp("apply/damage", -1800);
//      target->receive_wound("jing", random( damage/20 ));
        target->receive_damage("qi", 20 + random(damage));
        target->receive_wound("qi", 20 + damage);
if ((int)me->query_skill("yujianshu",1)> 380)
{
        message_vision(
                HIW"$N��һ�����������Ṧ���ν����衣ֻ��$N�㲻մ�أ����н�Խ��Խ�죬�𽥻���һ�Ű������ù�����\n" NOR, me);
  message_vision(WHT"$N���б������㳯$n"WHT"������ȥ��һ�������������\n\n"HIC"$n"HIC"���Ƶýп�������ȴ�㲻���������εĽ���!\n"NOR,me,target);
       me->add("neili", -90);
        i = 800+(int)me->query_skill("yujianshu",1)*2;
        j = 800+(int)me->query_skill("yujianshu",1)*3;   
        
        //target->start_busy(random(2));
        target->receive_damage("qi",j,me);
        target->receive_wound("qi", i,me);
        target->add("neili",-j);
     message_vision(WHT"$N������������������˭ͬ?˷�����ա�ѩӳ�Ļ��죬��ҹ��Ѭ������\n\n"HIC"$n"HIC"����һͷ��ˮ�����������������Σ��֮�У�\n"NOR,me,target);


}

if ((int)me->query_skill("yujianshu",1)>880)
{
      msg = HIW"\n$N����һҧ��ͻȻ�߸���������ȫ�������˽���һ��"
                 +"����һ���׹⣬���������$n��\n" NOR;
        ap = me->query_skill("yujianshu", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
                msg += HIW "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
                message_vision(msg, me, target);
         } 
         else {
damage=target->query("max_qi")/2;
if (damage> 45000) damage=45000;
                target->receive_damage("qi",damage,me);
                msg += HIW "$n����$N��˾�����Ϊ���������壬��Ȼ���ڵ��أ������мܡ�\n
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target); 
         }
	
}	

        me->add("neili", -280);
        me->start_busy(4);
        return 1;
}

