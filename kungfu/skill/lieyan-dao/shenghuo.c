// guangming.c  ʥ�����

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include <combat.h>


inherit F_SSERVER;


string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
}); 

string *limb=({
"����","����","����","ͷ��","С��","�ؿ�","����","�ɲ�","�Ҽ�","�ұ�","�ҽ�",
});

int perform(object me, object target)
{
        object weapon;
        int damage,p;
        string msg,name,dodge_skill,limbs;
        int extra;
        int i,skill;

	int ap, dp, neili_wound, qi_wound;
      
        
        skill=(int)me->query_skill("lieyan-dao",1);
        if(!target) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ʥ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if((int)me->query_skill("lieyan-dao", 1) < 100 )
                return notify_fail("������浶��������죬����ʹ�á�ʥ���������\n");
                                        
        if ((int)me->query_skill("jiuyang-shengong", 1) < 120)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
                        
//        if((int)me->query_skill("piaoyi-shenfa", 1) < 100 )
//                return notify_fail("���Ʈ���������ߣ�����ʹ�á�ʥ���������\n");

        if((int)me->query("max_neili", 1) < 800 )
                return notify_fail("���������Ϊ����������ʹ�á�ʥ���������\n");

        if( me->query_skill_mapped("blade") != "lieyan-dao")
                return notify_fail("�����ڵ�״̬�޷�ʹ�á�ʥ���������\n");

        if ((int)me->query("neili",1) < 500)
                return notify_fail("��������������޷�ʹ�á�ʥ���������\n");

        msg = HIC"\n$N���һ����"HIR"Ϊ�Ƴ���Ω�����ʣ�ϲ�ֱ���Թ鳾��"HIC"��"+weapon->query("name")+HIC"���˺϶�Ϊһ����������ɱ������$n��\n"NOR;

        if(((random(me->query("combat_exp",1)) > target->query("combat_exp",1)/4)
         &&(random(me->query_skill("blade")) > target->query_skill("parry")/4 ))
         ||!living(target)){
              limbs= limb[random(sizeof(limb))];
              msg +=CYN"$nֻ����������·��������˵�ɱ�����֣����޿ɱܣ����ɴ�ʧɫ����ʱ��ǰһ����"+weapon->query("name")+CYN"�Ѵ���"+limbs+"����������\n"NOR;
              damage = (int)me->query_skill("blade");
              damage += (int)me->query_skill("dodge");
              damage *= 2;
              if(damage > 3500) damage = 3500;
              target->receive_damage("qi", damage);
              target->receive_wound("qi", damage/3);
              me->add("neili", -150);
              //me->add("jing", -20);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if( random(5)>2          && me->query_skill("sougu",1 ) > 100
          && me->query_skill_mapped("claw") == "sougu"
          && me->query_skill_prepared("claw") == "sougu"){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N��������ǰһ�����˶Է�����֮�ʣ����ֱ���Ϊӥצ֮�ƣ���������ץ��$n��"+name+"��\n"NOR;
           if( random(me->query_skill("claw")) > target->query_skill("dodge")/3
            ||!living(target) ){
               me->add("neili", -150);
               target->start_busy(7);
               msg +=CYN"���$n��"+name+"��ץ�����ţ�ȫ����������һ������ʱ���ɶ�����\n"NOR;
           }
           else{
               dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
               msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
               me->add("neili", -50);
           }
           message_vision(msg, me, target);
//           me->start_perform(5,"��ʥ�������");
           me->start_busy(2);
           return 1;         
         }
         }
        else{
              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
              me->add("neili", -100);
              me->start_busy(2);
        }
        message_vision(msg, me, target);
//        me->start_perform(4,"��ʥ�������");

if (skill>300 && me && target)
{
  msg = HIY "$Nʹ���ѹ�ӥצ����������Ұӥ���˫צ���ץ��$n��ȫ��ҪѨ��\n";
        message_vision(msg, me, target);

if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);
        msg =  HIW "��һצ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "�ڶ�צ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "����צ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);

}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
                msg = "���$p��$P����ҪѨ����ʱ�������ã�\n" NOR;
                target->start_busy( 7);

        } else {
                msg = HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if (skill>400 && me && target)
{
msg = HIC "$NͻȻ��ͬ����Ѫ���𡹣��۽�$n����ǰ���������$n���ʺ�ҧȥ��\n"NOR;
	message_combatd(msg, me, target );
 if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);

        msg =  HIR "��һҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "�ڶ�ҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "����ҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);

}
	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp || random(3)==0)
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��\n"NOR;
		neili_wound = 800 + (skill*2);
		if(neili_wound > target->query("qi"))
			neili_wound = target->query("qi");
if (neili_wound> 60000) neili_wound=60000;

		qi_wound = neili_wound / 3;
		if (target->query("qi") > neili_wound)
		target->add("qi",-neili_wound);
		if (target->query("eff_qi") > neili_wound)
		target->add("eff_qi",-neili_wound);
		me->start_busy(2);
	       me->add("qi",qi_wound);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�����ݣ�\n"NOR;
		if(userp(me))

		me->start_busy(2);
		message_combatd(msg, me, target);
	}
}
        return 1;
}
