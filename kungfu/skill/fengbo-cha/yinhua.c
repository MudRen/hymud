//BY Cigar 2002.01 yinhua.c [����һЦ]
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
        int damage;
        string msg;
        object weapon;
        int howlong,enhance;
        int extra, myexp, hisexp;
        mapping action;  
        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail(MAG"��ʲô��Ц��ûװ������ʹ����������Ц����\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����������һЦ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    

    
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

        if ((int)me->query_skill("fengbo-cha",1) < 100 )
                return notify_fail(WHT"��ķ粨�治����죬��ʹ��������������һЦ����\n"NOR);
        if ((int)me->query("max_neili")<1000)
                return notify_fail(RED"���������Ϊ���㣬�޷����㡸��������һЦ����������\n"NOR);
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"������һЦ�����������̫��,�޷�����ʹ�ã�\n"NOR); 
        if(time()-me->query_temp("lxtx_end")<3)
                return notify_fail(WHT"������һЦ��"NOR"��"HIY"����"NOR"�޷�����ʹ�ã�\n"NOR);                 
        if ((int)me->query("neili")<600)        
                return notify_fail(HIC"����������������û�ܽ�����������һЦ��ʹ�꣡\n"NOR);
        
        msg = HIY "$N����ˮ���������⣬����Ĵ���ǧ���ٲݣ�������ϧ"+BLINK""HIR"������һЦ��\n"NOR;
        msg += HIG"�񼡴��䣬���⵭��ױ��һֻ�������ˣ����������С�⡣\n"NOR;
        msg += HIG"���贺�磬�����̸лᣬһ�α������ͣ�����͵������ȥ��\n"NOR;
        msg += HIG"��⻨Ӱ����֦��������Ǳ��²��ƣ��˼���м����硣\n"NOR;
        msg += HIC"��ҹ���裬Ũ˯���оƣ���֬˭���ȵ������������ת�����ʾ����ˣ�֪��֪��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 || random(3)==0)
        {
                //me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("club", 1);
                damage = 200+damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage,me);
                target->receive_wound("jing", damage/3,me);
                msg += HIM"$n�Ŀ���������������������֮׹�䣬����֮������$n�Ĵ���һ�Σ��پ��������顣\n"NOR;
                msg += HIM"$N��"+HIR"������һЦ��"+HIM"���Ѿ�ɢ��$n����������......\n"NOR;
                target->apply_condition("flower",5+random(5) + target->query_condition("flower"));
                me->add("neili", -100);
        } 
        else
        {
                //me->start_busy(2);
                msg += HIW"����$n��ϲ���񣬲�����Ծ��վ��$Nһ�ԣ��ֳ���������С�ã����ʹ���˾���\n"NOR;
                msg += HIW"$N����ֱ�������ޱȣ������Ͳ���˾����˾��Ƿ���֮����Ҳ���������ˡ�\n"NOR;
                me->add("neili", -50);
        }
        message_vision(msg, me, target);
       
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
message_vision(HIR"$NͻȻ�����ڶ���һָ�����������������"NOR+weapon->name()+
        HIR"��ʱ������ӿ�������˵أ��������Ű������$n������\n"NOR,me,target);
        me->add("jing",-100);
        
        howlong=me->query_skill("club")/5;
  if( random(3)>=1 ) 
        {    
        me->add_temp("apply/attack", 200);  
 me->add_temp("apply/damage", 2000); 
	msg =HIR"��һ����� ̰ҵ֮��"NOR;    
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =HIR"�ڶ������ ����֮��"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	msg =HIR"��������� �޳�֮��"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
damage = random(me->query_skill("club")) + me->query_skill("club")+500;
 target->receive_wound("qi", damage);
        COMBAT_D->report_status(target);
message_vision(HIR"\nֻ��$nӲ�����Ľ�ס$N�⼼���У��ٸк�ͷһ��[��]��һ���³�һ����Ѫ��\n\n"NOR,me, target);  
        me->add_temp("apply/attack", -200);
 me->add_temp("apply/damage", -2000); 
 }

        //me->start_busy(2);
	
}	


 if ((int)me->query_skill("fengbo-cha",1) > 900  || !userp(me))
{
if (objectp(weapon = target->query_temp("weapon")))
{
	      myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp*2/3 && weapon)   
        {
        	if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
                message_vision(HIR "\n\n$Nʹ��һʽ�粨�淨�е�"+HIG"����׷�ô�]"+HIR"�����е�"+(me->query_temp("weapon"))->name()+HIR"���һ����ɫ¶˿��$n�ı���Խ��Խ����
$n"+HIR"����ôץ��Ҳ�޼������ˣ���ʱ����"+ weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
                weapon->unequip();
                target->start_busy(3);
        }
                        target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                //if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
                message_vision(HIR "\n\n$Nʹ��һʽ�粨�淨�е�"+HIG"����׷�ô��"+HIR"�����Ҷ��컮��һ����ɫ��Ȧ"+(me->query_temp("weapon"))->name()+  HIR"��"+"$n"+HIR"Խ��Խ�����Ƶ�$n������������ĵز���\n\n" NOR, me,target);
                if(random(hisexp) < myexp*2/3 )
                {
                        target->start_busy(5+random(7));
                }
                else 
                {
                        message_vision(HIY "\n$n��׷���޿��κΣ�����������������һ��"+HIW"�첻����"+HIY"�����в����Լ�������ͳͳ���⣡\n" NOR, me, target);
                }
        }
}
	
}


       
       me->start_busy(3);
        me->set_temp("yinhua_end",time());
        return 1;
}


