//��ԯ��Ĺ ������ͨ ��������
#include <ansi.h>

inherit F_SSERVER;

int random_go(object victim,string* dirs);

int exert(object me)
{
        int success_adj, damage_adj,damage;
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
object target;
success_adj = 130;
damage_adj = 130;



        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
                return notify_fail("��Ҫ��˭ʩչ���������\n");





        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

        if (!target) target=me;


        if( random(me->query("max_neili")) < 850 ) {
                write("���û����ô������\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ������˭��\n");

        if((int)me->query("neili") < 700 )
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 50 )
                return notify_fail("���޷����о�����׼��\n");

        me->add("neili", -250);
                me->receive_damage("jing", 10);

                return 1;
        }

       msg =  HIW "$N���һ�������������ҡ�������ж�ʱ�����ܲ�����������\n
ͻȻһ����һ����ɫ����������ڹ������������ɵ�����$n\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3 && living(target)){
            damage = (int)me->query_skill("hanbing-zhenqi");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = 100+damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "���һ�������$n����͸�������$n��ʱ�����Ľ��ڣ�\n" NOR;
}
else
{
		msg="ֻ��$nʩչ�Ṧ������Ծ��ÿһ�����綼����߲�����\n" NOR; 
}
message_combatd(msg, me,target);		

if ((int)me->query_skill("hanbing-zhenqi",1)> 380)
	{
      msg = HIW
"$Nһ����ȡ�������ڣ��������һ������\n
����������������������������$n����ε��������۾�\n
$N˫��һ�ƣ����罫$n�����İ�������......\n" 
NOR;

        success = 1;
        ap = me->query_skill("taoism");
        ap = ap * ap * ap /12 ;
        ap += (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");

        ap2 = (int)me->query_per();
        dp2 = (int)target->query_per();


        ap3 = (int)me->query("neili");
        dp3 = (int)target->query("neili");
        if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;


        if(success == 1 ){
                msg +=  HIR "$n�����絶�а���ε����ۣ�ȴʼ���޷��ƶ��벽��\n" NOR;
                target->start_busy(7);
                }           
        else {
                msg +=  HIR "$n���·��һ˿��Ц���������С��������ҳݡ�˫��һ�ӷ�ƽ�˾���\n" NOR;   
                me->start_busy(1+random(2));        
              
        } 
me->add("neili", -150);
        message_vision(msg, me, target);
		
}		

if ((int)me->query_skill("hanbing-zhenqi",1)> 600)
	{
            if(random((int)me->query("max_neili")) >(int)target->query("max_neili")/2) {
                        message_vision(HIB"$N����һ�ӣ�ƽ������һ�ź���˲���Χ��$n......\n"NOR, me,target);

 msg =  MAG "$N���������дʣ�ͻȻ��$N����������������Ů\n
$n���ڲ����У�ֻ����Ů������������ʱ����������ɫ�������˹���\n" NOR;
        message_combatd(msg, me,target);		
            damage = (int)me->query_skill("hanbing-zhenqi");  
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taoism", 1)*8);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage);
}
		msg=HIC "��ʧ�룬��ֻ���Ӧ�ԣ�������ҧ�ı������ˣ�\n" NOR;
                } else {
                        msg="$n���Ų�æ������һ�ӣ������Һ�һ������ʱ�ҷ�����\n" NOR; 
                        me->start_busy(2);
                }
                me->add("neili", -150);
message_combatd(msg, me,target);	

}


        me->start_busy(3);
        return 3+random(5);
}


