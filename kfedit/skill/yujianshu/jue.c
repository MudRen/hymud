//by dewbaby@sk_sjsh
//�Ž������


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
                int damage,p;
        string msg,dodge_skill;
        weapon = me->query_temp("weapon");
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


        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ( (int)me->query("neili") < 900)
                return notify_fail("��������������޷�ʩչ�����������\n");
        if ((int)me->query("qi") < 900)
                return notify_fail("�����Ѫ�������޷�ʩչ�����������\n");


     
        lvl = me->query_skill("yujianshu", 1);
        if(lvl < 250)
                return notify_fail("��������书������������\n"); 


     message_vision(WHT"$N��������ؿ���$n��\n\n"NOR,me,target);
     message_vision(WHT"$N��������ͻȻ����"+ weapon->name() +HIY"��Ϊ�ŵ���ɫ������$n��ȥ��\n"NOR,me, target);
 
        me->add("neili", -(200 +random(100)) );
        me->add("qi", -50);
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2000);

        message_vision(HIY"$N������磬���н���Ӱ�䲻�ϣ�\n"NOR,me,target);
msg=WHT"$n"+WHT"����ӭ������Ľ����Ƶ��������ˣ��ƺ���Ϊ������\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"һ��                  "+BLINK+HIC+"����������\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"����             "+BLINK+WHT+"����������\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"����             "+BLINK+HIB+"����������\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"�Ľ�             "+BLINK+HIW+"�޵�������\n"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"�彣             "+BLINK+BLU+"�ٱ�Ӱ��Ѱ\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"����             "+BLINK+HIR+"��¥����Ъ\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"�߽�             "+BLINK+HIC+"�����״���\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"�˽�             "+BLINK+HIM+"ȥ�������\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIY"�Ž�             "+BLINK+WHT+"���������\n"NOR;
                  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
        
if ((int)me->query_skill("yujianshu",1)>=380)
{
        message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ�������������������ѩ����$n��\n"NOR,me,target);
 message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣��ǰ���У��ڰ����ѹ��$n��\n"NOR,me,target);
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("yujianshu",1);  
            //damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*2);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
		


if ((int)me->query_skill("yujianshu",1)>=480)
{
 message_vision(HIC"\n$N����бб����Ʈ����Ҳ����ͷ�����־ʹ̳������С�\n"NOR,me);	
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 200+(int)me->query_skill("yujianshu",1);  
            //damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*2);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
		
}

if ((int)me->query_skill("yujianshu",1)>=680)
{
 message_vision(HIC"\n$Nббһ�ٸ�������������ǧ��֧����������һ�ɺ�������$n��\n"NOR,me,target);
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 300+(int)me->query_skill("yujianshu",1);  
           // damage = damage + random(damage);
            damage +=(int)(me->query_skill("panshi-shengong", 1)*3);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage/2);
}
COMBAT_D->report_status(target);
}
	
}
}	

        me->start_busy(5);
        return 1;
}


