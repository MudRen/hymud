#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;


string* skill_head1 =({
        HIW"$N�������ˣ�ʹ��һ�� ��������",
        HIW"$N���쳤Ц����Ҳ������һ�� �����ĺ�",
        HIW"$Nһ��������ʹ�� ��Ծ����",
        HIW"$Nһ���޺ȣ���һ�� ˫��Ϸ��",
        HIW"$Nʹ�� ������Ұ",
        HIW"$N�����������һ�� ������Х",

});

string* skill_tail1 =({
        HIW"������$wӭ��һ��������$n��ͷ�������ҽ�������",
        HIW"������һ����$n��ͷ���¡�",
        HIW"��Խ��$nͷ��������$w�ո���Բ��������һ������$n$l��",
        HIW"������$nһ�֮�䣬$N����$w���Ǻ�Х������ɨ��$n��$l��",
        HIW"���Ų����ԣ���һ������һ����\n���$n��æ���ң��мܲ�����",
        HIW"������$wת����糵һ�㣬\nһ�������Ӱ���л���$n���š�",
});

int perform(object me, object target)
{
        int mypot,tapot,time, ap, dp,damage;
object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���޾��粨��ֻ����ս���в���ʹ�á�\n");

        if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
                return notify_fail("�����Ϊ�������ʹ������һ�У�\n");
    
  if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);
  
     
        
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("���뾸���񹦲��С�\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("��ľ����񹦻���Щ���\n");            
        if ((int)me->query("max_neili")<800)
                return notify_fail(RED"���������Ϊ���㡣\n"NOR);
  
        if ((int)me->query("neili")<400)        
                return notify_fail(HIC"����������������\n"NOR);   
        if( target->is_busy() )
                return notify_fail(target->name()+"�Ѿ���æ�ˣ���ʹ����Ư��Ҳ����ע�⵽��\n");

        message_vision(HIC"$N��չ��������һ�棬��һ�棬�ó�������С�⻷��$n��ȥ��
�俴��������������ȴ�����ﲨ�����಻����ʵ�ǰ���ɱ����\n\n"NOR,me, target);

        me->add("jing", -60);

        mypot=(int)me->query_skill("club");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        time=(int)me->query_skill("fengbo-cha", 1)/10 - (int)target->query_skill("parry")/20;
    
        if ( time > 10 ) time = 10;
        if ( time < 6  ) time = 6;

//        if ( (mypot+tapot)/4+random( mypot + tapot ) > tapot ) {
//        if ( (mypot+tapot)/2+random( mypot + tapot ) > tapot ) {
        if ( (mypot+tapot)/2+random( (mypot+tapot)*3/4 ) > tapot ) 
        {
                message_vision(HIR"$N��Ȼ����⻷��ס����ʱĿ�ɿڴ�����֪���룡\n"NOR,target);
                target->start_busy(time);
                me->set_temp("no_pfm",time() + 2);
        }
        else 
        {
                message_vision(HIR"����ȴ��$N���ƣ����䲻����$n�������˸����ֲ�����\n"NOR,target,me);
//                me->start_busy(3);
                me->start_busy(1+random(2));
        }

        
 if ((int)me->query_skill("fengbo-cha",1) > 300 )
{
         me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2000); 

        if(!target->is_busy())
                target->start_busy(1);
        

	msg = skill_head1[0]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[1]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[2]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[3]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[4]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[5]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-100);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
}
 if ((int)me->query_skill("fengbo-cha",1) > 600  || !userp(me))
{
     msg = HIR
"\n$NĬ�˾����񹦣����κ���б��ɳ���$n��Ҫ׷����ȴ����$N���зų�һ��Ѥ���Ĺ⻷����ʱ����г���һ������ħ��ֻ��ħ���־���ͥ�����\n"
"�����磬���׻�һ��ֱ��$n��ǰ���ֻ̼�$n����������������֪����Ǻ�\n" NOR;

        ap = me->query_skill("fengbo-cha", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/400) <  dp/1000 ) 
        {
                msg += "$n"+HIG"��������ֱ������������һ��"+HIW"�����춷�������κ�����"+HIG"�����ƣ������������һ����\n\n"NOR;
                message_vision(msg, me, target);
        } 
        else 
        {
                damage = 300+((int)me->query_skill("club",1)*2)  +
        (int)me->query("jing") / 300 + random((int)me->query("jing") / 200 ) +
        (int)me->query("qi") / 300 + random((int)me->query("qi") / 200 );
                msg += HIY "��ħһ����ʱ��$n���ؿ�ֱ�������$n���ؿڶ�ʱѪ����ע�����"+HIW"�����ˣ��������"+HIR"��$n�������Ƿ��в������ڵ�Ϧ��\n" NOR;
                damage +=random(50);
                if (damage > 8000) damage=8000;
                target->receive_damage("jing", damage/2,me);
                target->receive_wound("qi", damage,me);
                
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }	
	
}	
               
        me->start_busy(1+random(2));

        return 1;
}
    


