// foxing ʾ����
// campsun
//2000.9.17

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
int perform(object me, object target)
{
  object weapon;
string msg;
int damage,p;        
int extra;
        string dodge_skill;
        int hellfirewhip,tonsillit,gouhunshu,times;
        string desc_msg="";
        int bellicosity_num,lhb_level;
	int success_adj, damage_adj;
        


        if( !target ) target = offensive_target(me);

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("hellfire-whip", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("yijinjing", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("zhanzhuang-gong", 1) < 500 )
		return notify_fail("�����ƽ����վ׮��������!���ܹ�ͨʹ�ã�\n");

//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        msg = HBWHT "$N��ͨ��������ѧ��ʹ���������ֵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
        hellfirewhip = (int)me->query_skill("hellfire-whip", 1);
        tonsillit = (int)me->query_skill("zhanzhuang-gong", 1);
        gouhunshu = (int)me->query_skill("buddhism", 1);
        damage=hellfirewhip;

  message_vision(HIC"\n$NͻȻ����������������ζ������г����ĸ���������б��Գ�����ԩ�껷�ƣ�
  ����ϰϰ��ʹ���������һ��ʧ���Ѿõľ�ѧ**׷�����**��\n"NOR,me);
        extra=(int)(bellicosity_num/30);
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2800);
        if(!target->is_busy())
                target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->add_temp("apply/attack", -(200));
        me->add_temp("apply/damage", -(2800));
        if( hellfirewhip > 120 && tonsillit > 120 && gouhunshu > 120 )
        {   
                message_vision(HIR"\n$N��������е��һ𣬲��ɵ���Ѫ��ӿ��ƴ�����һ�ޡ�\n"NOR,me);
 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                message_vision(HIR"\n$N�޷��ƺ��Ѿ����ϣ�ͻȻ��ͷ���һ���һ�$n�������Ҳ�㲻��ȥ�ˡ�\n"NOR,me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);

        }
        if( hellfirewhip > 160 && tonsillit > 160 && gouhunshu > 160 )
        {    
                message_vision(HIR"\n$N�·�����������������������Χ��һ˿��Ц�����һ���������һ����
           �ľ���������ʽ�о��֡�\n"NOR,me);
                me->add_temp("apply/attack",hellfirewhip);
                me->add_temp("apply/damage",3200);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                me->add_temp("apply/attack",-(hellfirewhip));
                me->add_temp("apply/damage",-(3200));
                target->receive_damage("qi",damage*3,me); 
                target->receive_damage("jing",damage,me); 
                target->receive_wound("qi",damage*3,me); 
                target->receive_wound("jing",damage,me); 
        }

      if( hellfirewhip > 260 && tonsillit > 260 && gouhunshu > 260 )
        {   
       msg = MAG "$N�Һ�һ����һ����Ѫ�����գ�����������Ѫһ�ƣ����г���Х������������������������Ϯ$n���ؿ��ߴ���Ѩ��\n" NOR;
        message_combatd(msg, me,target);		
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target) || random(3)==0){
            damage = (int)me->query_skill("hellfire-whip");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            //damage = damage + random(damage);
            //damage +=(int)(me->query_skill("buddhism", 1));
            target->receive_damage("qi", damage*3,me);
            target->receive_wound("qi", damage*3,me);
		msg=MAG "���������$n�ؿ���������������һ����Ѫ��\n" NOR;
}
else
{
		msg=HIG "����$nһ����Ц������ҡ�Σ����˿�ȥ��\n" NOR; 
}
message_combatd(msg, me,target);		           
}
        message_vision(HIR"\n$N˫Ŀ�����˸��������� ������ȥ���������־͸�����\n"NOR,me);
        if (random(me->query("combat_exp",1)) < target->query("combat_exp",1)/3
        || random(3)==0
        ){

                message_vision(HIR"\n�Է���Ԫ��һ��˿����Ϊ��������\n"NOR,me,target);
            target->receive_damage("qi", damage*3,me);
            target->receive_wound("qi", damage*3,me);

                //me->start_buzy(3);
        }   
        else 
        {   
                message_vision(HIC"\n$N������䣬$n�����ɢ����������!\n"NOR,me,target);
                target->start_busy(3);

        }
         //me->add("neili", -350);                                
//me->start_buzy(2);

        
extra = me->query_skill("hellfire-whip",1) / 10;
if ((int)me->query_skill("yijinjing",1) >250
&&(int)me->query_skill("hellfire-whip",1) >250
&& me->query("neili") >500)
{

//if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2800);
	msg = HIR  "�ۿ���ʽҪ�꣬ͻȻ��$N��ʩչ�������ٻ�Ӱ�����ţݣ����μ�����ת��һ����Ӱ��ͻȻ��$n�ɳ�һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -2800);
	extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2800);
        msg = HIR  "��Ӱ���ַɳ�һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2800);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2800);
        msg = HIR  "$N���ν��ȣ���������һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2800);
//me->add("neili",-350);
}
msg =YEL "\n$N��������ʹ�꣬ȫ��һת���������ڵ��ϡ�\n";
message_vision(msg, me, target);                  
me->start_busy(4);
//me->start_busy(3+random(3));
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        msg = RED "\n$N�ӵ����ϵ���������˵�����������������سɷ�һ��ǿ��֮���Ʒ�ֱ��$n��ȥ��\n"NOR;        
//weapon->unequip();
//        weapon->move(environment(me));

//        me->set_temp("sl_wuying", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3 || random(3)==0){                     
//                me->start_busy(1);
                target->start_busy(2); 
                //me->add("neili", -100);
                me->add("jing", -20);
                damage = (int)me->query_skill("hellfire-whip", 1);                
		//damage = (int)me->query_skill("wushen-jian", 1);
		
	target->receive_damage("qi",damage*3,me);
	target->receive_wound("qi",damage*3,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
//                me->start_busy(2);
//                target->start_busy(1);
                //me->add("neili", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = HIC "\n$N���ƾ���δ��������Ҳ�����Ƴ�����������������سɷ��Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hellfire-whip", 1) > 199 || random(3)==0){                
//                me->start_busy(1);
                //target->start_busy(2);
                //me->add("neili", -100);
                //me->add("jing", -30);                
                damage = (int)me->query_skill("hellfire-whip", 1);                

		
	target->receive_damage("qi",damage*3,me);
	target->receive_wound("qi",damage*3,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
//                me->start_busy(2);
                //me->add("neili", -100);
                tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = HIG "\n$N΢΢һЦ��˫���ಢ��ǰ�Ƴ�����������ʲô��������$n��ͬ��ǰ��Բ����ȫ�ڡ����سɷ𡹾�������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hellfire-whip", 1) > 249 || random(3)==0)
        {
//                me->start_busy(2);
//                target->start_busy(random(5)+2);
                //me->add("neili", -200);
                //me->add("jing", -40);                
                damage = (int)me->query_skill("hellfire-whip", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
//                me->start_busy(2);
//                target->start_busy(1);
                //me->add("neili", -200);
                target->add("jing", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

