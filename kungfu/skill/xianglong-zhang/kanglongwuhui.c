#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define HUI "��" HIR "�����л�" NOR "��"
#define HUIP "��" HIR "�����л�" HIW "��"
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
	 int skill;
	 int damage;
	 
       int  ap, dp;
	 
        extra = me->query_skill("xianglong-zhang",1);
        skill = me->query_skill("xianglong-zhang",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("��������ʹ�á�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
     
        if( (int)me->query_skill("xianglong-zhang", 1) < 200 )
                return notify_fail("��Ľ���ʮ���Ʋ�����죬�޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
if ( me->query_skill_mapped("force") != "huntian-qigong" )
return notify_fail("��û�ñ����ڹ���\n");
if ( me->query_skill_mapped("unarmed") != "xianglong-zhang" )
return notify_fail("��û��ʹ�������Ʒ���\n");

        if (me->query_skill("huntian-qigong", 1)<120)
                return notify_fail("��ı����ڹ����δ������\n");
       
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
        if ( (int)me->query("neili") < 1500)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
                 
                 me->add_temp("apply/attack", 100);
	         me->add_temp("apply/damage", 2200);
	me->add("neili", -200);
		 msg = YEL "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ������ʮ���Ƶ����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"��һ�а�ʽ����$n��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "��һʽ��$N����һʽ��������Ұ���������ޱȵ�����$n��" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ�ʽ��$N˫��ʩ��һʽ��������½��������ԼԼ�����Ʒ�����$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "����ʽ��$N�������أ�����һʽ��Ǳ����������������$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����ʽ��$Nʹ������Ծ���졹����$n���������ƣ�" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "����ʽ��$N˫��һʽ��˫��Ϸˮ��һǰһ����$n����ǰ��" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "����ʽ��$N����ת����ʹ����������������$n�������£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "����ʽ��$N����һת��ͻȻ�۵�$n��ǰ��һʽ����ս��Ұ��ֱ����$n����" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "�ڰ�ʽ��$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2200);
if ((!userp(me) || skill>200) && me && target)
{
 msg = HIB "
$NĬ�˻���������ʩչ��������һ������ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0) { 
      me->start_busy(3);
   damage = (int)me->query_skill("xianglong-zhang", 1)*3+(int)me->query_skill("huntian-qigong",1);
   damage = damage + random(damage)+200;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage,me);
   target->receive_wound("qi", damage,me);

   msg += "
$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫�ƣ�������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������\n"NOR;
message_combatd(msg, me, target);
COMBAT_D->report_status(target);

    } else
    {
      me->start_busy(3);

       msg += "����$n������$N����ͼ����Ȼ��$N������\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(me);
    }	
}	

if ((!userp(me) || skill>300) && me && target)
{
if (objectp(weapon = target->query_temp("weapon")))
{
    msg = HIW "$N" HIW "����һ����ȫ���ھ��ŷ��������ұ۷����⳶����ͼ��$n"
              HIW "��" + weapon->name() + HIW "�������С�\n" NOR;

        ap = me->query_skill("xianglong-zhang") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("dex") * 10;

        if (ap / 3 + random(ap) > dp || random(3)==0)
        {
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
                msg += HIR "$n" HIR "ֻ����Χ����ӿ��������" + weapon->name()
                       + HIR "��Ȼ����ס����$N" HIR "�������ַ�ȥ��\n" NOR;

                weapon->move(environment(me), 1);
}
                target->receive_damage("qi", ap*2,me);
                target->receive_wound("qi", ap*2,me);
        } else
        {
                msg += CYN "$n" CYN "ֻ����Χ����ӿ������æ����������"
                       + weapon->name() + CYN "������ܲ�͸�磬ʹ��$N"
                       CYN "�޴����֡�\n" NOR;

        }
        message_combatd(msg, me, target);
}	
	
}	
if ((!userp(me) || skill>400) && me && target)
{
  msg = WHT "$N" WHT "ʩ������ʮ����֮��" HIW "�𾪰���" NOR +
              WHT "����ȫ�������Ķ���˫������ɽ������ѹ��$n" WHT "��\n"NOR;  

        ap = me->query_skill("xianglong-zhang",1) + me->query("str") * 10;
        dp = target->query_skill("dodge",1) + target->query("dex") * 10;

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        { 
                damage = ap + random(ap / 2)+400;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage*2,me);
   target->receive_wound("qi", damage*2,me);
                msg +=HIR "$n" HIR "ֻ��һ���ӿ����������"
                                           "����ܣ�$N" HIR "˫������ǰ�أ���Ѫ��"
                                           "���������\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += CYN "$n" CYN "�ۼ�$N" CYN "������ӿ��˿����"
                       "��С���æ������һ�ԡ�\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if ((!userp(me) || skill>500) && me && target)
{
        ap = me->query_skill("xianglong-zhang",1) + me->query("str") * 10;
        dp = target->query_skill("dodge",1) + target->query("dex") * 5;

        message_vision(HIW "\n��Ȼ$N" HIW "���μ���������һ�������ֺ���һ��"
                     "����$n" HIW "�����ǽ���ʮ����" HUIP "��\n��������֮��"
                     "˵���㵽������ɽ����֮����$n" HIW "��ӿ��ȥ������ʯ"
                     "���쾪�������ޱȡ�\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = ap + random(ap)+800;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage*2,me);
   target->receive_wound("qi", damage*2,me);
                msg =HIR "$P����һ�������ѻ���$p��ǰ��$p��"
                                          "���������ٱ��������С�\n" NOR;
        } else
        {
                msg = HIC "ȴ��$p����˫�ۣ�����Ӧ�ԣ�$P��"
                      "������ţ�뺣������жȥ��\n" NOR;
        }
        message_vision(msg, me, target);

}	

        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		&& me->query("xlz/hang"))
	 {

 msg = HIR"��ҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��!!"NOR+" ";
                msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
         damage=(int)me->query_skill("xianglong-zhang",1)+200;
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*3,me);
                target->receive_wound("qi",damage*3,me);
		target->receive_wound("jing", 10 + random(200),me);
                if (!target->is_busy()) target->start_busy(2);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}



        me->start_busy(5);
        return 1;
}
