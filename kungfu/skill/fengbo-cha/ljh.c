//modify by Wuyou@Sanjie

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
//object weapon;
        string str;
        int extra;
        object victim;              // ���ֵ�����
        int i,attack_time,skill,damage,lvl;   
        if( !target ) target = offensive_target(me);
        
             if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("fengbo-cha", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jinghai-force", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "fengbo-cha")
          //      return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "jinghai-force")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ�����ѧ��ʹ������ἵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
                                
                        

        msg = HIW "\n$NͻȻ������������һ������������ʡ�$N�����м��ٴ���ʹ��"HIC"���β���"HIW"�ռ�����"HIR"�������֣�" NOR;
        message_vision(msg, me, target);
        damage = 10+(int)me->query_skill("dragonfight",1);
 if (random(2)==0) target->start_busy(2);
me->add_temp("apply/attack", 180);
me->add_temp("apply/damage", 2800);
                                msg = HIY "���P���Ա���" NOR;
                                msg += MAG "�P����ʯ��������������" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIW "��������¡�" NOR;
                                msg += HIB "�������ǧ��֮�⣬��Ȼ������" NOR;
                            	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIG "�����������" NOR;
                                msg += HIC "���ѳԾ�������ʳ�����������" NOR;
                              	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIR "������ŭɱ��" NOR;
                                msg += WHT "����ɱ��������˫��Ѫ�ȣ��޷޶�����" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIC "�����������" NOR;
                                msg += CYN "�����Ӷ���𣬴���˽����Ȼ������" NOR;
                           	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIR "������»��" NOR;
                                msg += HIM "����Ⱥ��̻���Я��������" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = WHT "��ſ��Ϸˮ��" NOR;
                                msg += HIY "ſ�󷭽�����������ˮ�У�Я�������" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = MAG "����ͼ��Ѩ��" NOR;
                                msg += HIW "��ͼ���Ų�������ȥ�Ҵң�" NOR;
                               	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                                msg = HIB "�����γ�����" NOR;
                                msg += HIG "����ͨ���������߱߳���" NOR;
                             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


me->add_temp("apply/attack", -180);
me->add_temp("apply/damage", -2800); 

     msg = HIR
"\n$NĬ�˾����񹦣����κ���б��ɳ���$n��Ҫ׷����ȴ����$N���зų�һ��Ѥ���Ĺ⻷����ʱ����г���һ������ħ��ֻ��ħ���־���ͥ�����\n"
"�����磬���׻�һ��ֱ��$n��ǰ���ֻ̼�$n����������������֪����Ǻ�\n" NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

              msg = HIY "��ħһ����ʱ��$n���ؿ�ֱ�������$n���ؿڶ�ʱѪ����ע�����"+HIW"�����ˣ��������"+HIR"��$n�������Ƿ��в������ڵ�Ϧ��\n" NOR;
target->receive_damage("qi", (me->query_skill("fengbo-cha",1)*8),me);
target->receive_wound("qi", (me->query_skill("jinghai-force",1)*8),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);
        message_vision(HIC"$N��չ��������һ�棬��һ�棬�ó�������С�⻷��$n��ȥ��
�俴��������������ȴ�����ﲨ�����಻����ʵ�ǰ���ɱ����\n\n"NOR,me, target);

message_vision(HIR"$NͻȻ�����ڶ���һָ�����������������"NOR+weapon->name()+
        HIR"��ʱ������ӿ�������˵أ��������Ű������$n������\n"NOR,me,target);
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
        me->add_temp("apply/attack", 200);  
 me->add_temp("apply/damage", 2800); 
	msg =HIR"��һ����� ̰ҵ֮��"NOR;    
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =HIR"�ڶ������ ����֮��"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	msg =HIR"��������� �޳�֮��"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_damage("qi", (me->query_skill("fengbo-cha",1)*8),me);
target->receive_wound("qi", (me->query_skill("jinghai-force",1)*8),me); 
        COMBAT_D->report_status(target);
message_vision(HIR"\nֻ��$nӲ�����Ľ�ס$N�⼼���У��ٸк�ͷһ��[��]��һ���³�һ����Ѫ��\n\n"NOR,me, target);  
        me->add_temp("apply/attack", -200);
 me->add_temp("apply/damage", -2800); 

        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
//        message_vision(msg, me, target);


me->start_busy(4);
        return 1;
}


