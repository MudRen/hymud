// dingshen.c ����

#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="����";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������������������\n"
        +"��������������>=100\n"
        +"����յĶ�����ʹ�Է����ܶ�����";
        return str;
}

void free(object target);

int exert(object me)
{
        string msg;
        int success, ap, dp, howlong;
object target;

    string msg1;
    string msg2;
    string msg3;
    string msg4;
    int damage,i;
    i=random(3);

        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("�㻹ûѧ�ᶨ��������\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭��ס��\n");


           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if((int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("���޷����о�����\n");

        me->add("neili", -500);
        me->receive_damage("jing", 10);

        msg = HIC
"$N�������˾����ģ���$nһָ�����һ��������\n" 
NOR;

        success = 1;
        ap = me->query_skill("taoism");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_neili");
        dp = (int)target->query("max_neili");
        if( random(ap + dp) < dp ) success = 0;
//here we compared max_mana.

        ap = (int)me->query("neili");
        dp = (int)target->query("neili");
        if( random(ap + dp) < dp ) success = 0;
//here we compare current mana. this is important. you need recover to try again.

        howlong = 0;        
        if(success == 1 ){
                msg +=  HIR "���$n���㽩Ӳ����Ȼ�������ã�\n" NOR;
                target->start_busy(7);

//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
        }           
        else {
                msg +=  HIR "���$n������һ����\n" NOR; 
        } 

        message_vision(msg, me, target);

        

        if (success == 0) {
                me->start_busy(3);
                return 1+random(2);
}

if ((int)me->query_skill("qingming-xuangong",1)> 200)
{
        msg1=HIY"$N˫�ָ�����������ٲ�£����һ�ƣ���ȵ���"+HIC"�����������ܣ�����׵硭���򣡣��� ɲ�Ǽ䣬������ӿ��Ũ���ܲ���һ������������м���������$n��ȥ������\n";
        msg2=HIR"���䡱��һ�����˸����ţ�"+target->query("name")+"���������Ѭ��ͷһ���ڣ�\n"NOR;
        msg3=RED"��ֻ����ȫ���飬��ǰ������ð��������\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query("max_jing") / 10 + random((int)me->query("eff_jing") / 5);
       damage -= (int)target->query("max_jing") / 20 + random((int)target->query("eff_jing") / 20);
       damage=100+damage;
       if (!userp(me) && damage >3000) damage=3000;
       if (damage <100) damage=100;
       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage,me);
           target->receive_wound("qi", damage/2,me);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N�ġ���ʶ��ͨ������û������κ��˺���\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "����$n����ض㿪�ˡ�\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	 
 
if ((int)me->query_skill("qingming-xuangong",1)> 250)
{
        msg1=HIC"$N����һתɢ���ߴ�ͬʱ�����������������࣬�򽣹��ڣ������������񽣷�ħ������ֻ�����г����������$n��ȥ������\n"NOR;

        msg2=RED"ֻ�������͡����첻�����������"+target->query("name")+RED"���塣"+
        target->query("name")+RED"�����ǧ���ٿ׵Ĵ�ɸ�ӣ�����\n";
        msg3=RED"��ֻ���ı������磬�����ʹ��\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query_skill("qingming-xuangong",1) + random((int)me->query_skill("taoism",1));
          damage=100+damage;
       if (!userp(me) && damage >3000) damage=3000;
       if (damage <100) damage=100;

       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N�ġ���ʶ��ͨ������û������κ��˺���\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "����$n����ض㿪�ˡ�\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	     

if ((int)me->query_skill("qingming-xuangong",1)> 300)
{
        msg1=HIB"$N˫�ֻ�����ǰ�������������������޼���Ǭ���跨������ ͻȻ���һ�������У�����˫�Ʋ�����һ�޴�Ľ�ɫ��������$n��\n";
        msg2="���顱��"+target->query("name")+HIB"�������һ���������˼���������\n";
        msg3="���顱�����ؿ����ⴸ��������һ�ڣ���Щ���˹�ȥ��\n"NOR;
    message_vision(msg1, me, target);
    ap = me->query_skill("taoism");
    dp = target->query("dodge");
    if( random(ap + dp) > dp) 
    {
       damage = (int)me->query_skill("qingming-xuangong",1) + random((int)me->query_skill("taoism",1));
          damage=500+damage;
       if (!userp(me) && damage >3000) damage=3000;
       if (damage <100) damage=100;

       if( damage > 0 ) 
       {
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           tell_room(environment(me),msg2,target);
           tell_object(target,msg3);
           
       }
       else
       {
           msg = "$N�ġ���ʶ��ͨ������û������κ��˺���\n";
           me->receive_damage("jing", 10);
       }
    } 
    else
    msg = "����$n����ض㿪�ˡ�\n";
    message_vision(msg, me, target);

    if( damage > 0 ) COMBAT_D->report_status(target);	
	
}	  


if ((int)me->query_skill("qingming-xuangong",1)> 500)
{
       msg =  HIY "$N�������˾����ģ�����߳�һλ��ò���ŵĵ�ĸ��˫�ָ���һöͭ����ͭ����ת����������һ���������$n��\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
       if (!userp(me) && damage >3000) damage=3000;
       if (damage <100) damage=100;

if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "������͡���һ��������$n����͸�������\n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR;
}
else
{
		msg="����ͣ���һ��$n�ŵ���һ�ɽ�ζ������ֻ�յ��˼���ͷ����\n" NOR; 
}
message_combatd(msg, me,target);	
	
}	  

if ((int)me->query_skill("qingming-xuangong",1)> 700)
{
       msg =  HIW "$N�������˾����ģ�����߳�λ��ͷӥ�ǵ��׹�������ִ����������׶����׶�������$n��ͷ��ը��һƬ���ף�\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("qingming-xuangong");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
       if (!userp(me) && damage >3000) damage=3000;
       if (damage <100) damage=100;

if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIW "���$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR;
}
else
{
		msg="˭֪$n���޷�Ӧ�����������Ƶġ�\n" NOR; 
}
message_combatd(msg, me,target);	
	
}	  
       
         me->start_busy(3);        
        return 3+random(5);
}



