// zhen.c ̫��ȭ��ճ���־�
// snowman
#include <ansi.h>

inherit F_SSERVER;
string *taiji_msg = ({"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��",
"����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ",});
#include "/kungfu/skill/eff_msg.h";
string *taiji_msg2 = ({"ʮ����","����Ʊ�","������","Ұ�����","б����","����","����","��ͨ��"});

int perform(object me, object target)
{
        int damage;
        string msg;
        int p, force;
        float at;
       
        string *limbs;
        
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("��ճ���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭ��Ҫ���ڽ�չδչ����û�����á�̫�������������ʹ�á�ճ���־���\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������������ǿ��ʹ�á�ճ���Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        if( target->is_busy())
                return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʹ�á�ճ���־���\n");   
                
        msg = CYN "\n$Nһ��һʽ�ڽڹᴮ���糤����ӣ�"RED"��ճ��"CYN"��$n���ϣ�һ��ԲȦ����һ��ԲȦ��
��Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ���������಻�ϣ����ϲ�����\n"NOR;
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2){
                damage = (int)me->query_skill("taiji-quan", 1)/20; 
                damage = 2+random(damage)+8+1;
                if(damage > 1800) damage = 1800; 
                target->start_busy(6);
                me->add("neili", -(damage*30));
                me->add("jing", -20);
                msg += HIR"����Ȧ��Ȧ��ʱ���׵�$p����ײײ�������������㲻�ȣ������оƻ��ԣ�\n"NOR;       
                } 
        else{
                target->start_busy(2);
                me->start_busy(3);
                me->add("jing", -15);
                me->add("neili", -100);
                msg += HIY"$pֻ����$P̫��ȭ����֮�£��޿ɵ�����ֻ��ֻ���˾����㣬ƮȻ������\n"NOR;
             }
        message_vision(msg, me, target);

    if( (int)me->query_skill("taiji-quan", 1) > 200 )
    {
     limbs = target->query("limbs");
        msg = CYN "\n$Nʹһ��̫��ȭ��"+taiji_msg[random(sizeof(taiji_msg))]+"�����ҽ�ʵ������飬����"RED"������"CYN"�־���ճ��ճ�棬�����Ѵ�ס$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
        
        force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("unarmed")) > target->query_skill("unarmed")/2 || random(3)==0){
                me->start_busy(3);
                if(!target->is_busy()) target->start_busy(3);
                
                damage = 200+(int)me->query_skill("force");                
                if(me->query("neili") > target->query("neili")*2) damage *= 2;
                else if(me->query("neili") > target->query("neili")*3/2) damage += random(damage);
                else if(me->query("neili")*2 < target->query("neili")) damage /= 2;
                else if(me->query("neili") < target->query("neili")) damage -= random(damage);
                else damage = damage/2 + random(damage);
                if(damage> 35000) damage = 35000; 
                target->receive_damage("jing", damage/5);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                msg += HIR"����$P�ᾢ������$p����ôһ�������ӱ��Լ��ľ������ò���������ǰһ�壬���������\n"NOR;       
                } 
        else{
                me->start_busy(2);
                msg += HIY"$p�����龰��һ�����棬��æ�ջ��Լ��ľ�����������ã�\n"NOR;
             }
        message_vision(msg, me, target);
}

    if( (int)me->query_skill("taiji-quan", 1) > 300 )
    {
msg = CYN "\n$NĬ���񹦣�ʹ��̫��ȭ�����־�����ͼ����������$n��\n"NOR;

    if (random(me->query_skill("force")) > target->query_skill("force")/3 || random(3)==0)
    {
      me->start_busy(2);
      damage = (int)me->query_skill("taiji-shengong", 1)+200;
      damage = damage/2 + random(damage)+500;

      target->receive_damage("qi", damage);
      target->receive_wound("qi", damage/2);
      me->add("neili", -damage/10);

      if( damage < 20 ) msg += HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
      else if( damage < 40 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
      else if( damage < 80 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
      else msg += HIR"���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n"NOR;

    } else
    {
      me->start_busy(1);
      msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
    }
    message_combatd(msg, me, target);

}
    if( (int)me->query_skill("taiji-quan", 1) > 600 )
    {
        msg = CYN "\nͻȻ��$Nһ�С�"+taiji_msg[random(sizeof(taiji_msg))]+"����˫������������һ��ԲȦ�ѽ�$n��ס��̫��ȭ��"RED"����"CYN"�־��漴ʹ����\n"NOR;
        
        force = 500+me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("force")) > target->query_skill("force")/2 || random(3)==0){
                if(me->query("neili") < target->query("neili")/2){
                       me->start_busy(2);
                       if(!target->is_busy()) target->start_busy(3); 
                       target->add("neili", -force/2);
                       msg += HIY"ֻ����ž����һ����$p��$P����������ƴ�������������˼�����\n"NOR;
                       message_vision(msg, me, target);
                       return 1;
                       }
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(2+random(3));
                
                damage = (int)me->query_skill("force")*2+600;                
                at = me->query("neili") / (target->query("neili")+1);
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                if(damage> 38000) damage = 38000; 
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                if(target->query("neili") >= damage/4) target->add("neili", -(damage/4));
                else target->set("neili", 0);

                if(damage > 2000)
                   msg += RED"̫��֮�����಻�ϣ�������ȥ�пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ����������һ�죬$pһ����ͷ���ʶϣ�\n"NOR;
                if(damage > 3000)
                   msg += HIR"$N���������������־�ʹ��ʱ���಻�ϣ����ſ�����������$pȫ�������ͷҲ��һһ�ʶϣ�\n"NOR;
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
                } 
        else{
                me->start_busy(2);

                msg += HIY"$pһ�����ԣ�����һ�󼱹���$P��ʱ��æ���ң���Ҳ���������У�\n"NOR;
             }
        message_vision(msg, me, target);	
   } 	
        return 1;
}