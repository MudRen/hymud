//Ǭ��һ��
//modify by wuyou@sk_sjsh 
//2003-7-27

#include <ansi.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string get_name(string str)
{
        str="Ǭ��һ��";
        return str;
}

string get_help(string str)                
{
        str="ָ������������������\n"
        +"�������Ͷ������150������������150����С���๦150�����������1200���������20"
        +"�������ӣ����������ƻ��Է��Ŀ��ף������ܹ�ʹ�Է��������ˣ�";
        return str;
}

int perform(object me, object target)
{
        string msg, dodge_skill;                                
        int damage, jiali, attack, defense, p;
        object armor,weapon;
      
        if( !target ) target = offensive_target(me);
     
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�Ǭ��һ������\n");
                
        if(!me->is_fighting())
                return notify_fail("��Ǭ��һ����ֻ����ս����ʹ�ã�\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");
                
        if( (int)me->query_skill("buddha-club",1) < 150 )
                return notify_fail("����Ͷ������������죬������ʹ�á�Ǭ��һ������\n");
      
        if( (int)me->query_skill("club",1) < 150 )
                return notify_fail("��Ļ�������������죬������ʹ�á�Ǭ��һ������\n");

        if( (int)me->query_skill("zhanzhuang-gong",1) < 150 )
                return notify_fail("��ı����ڹ��ȼ�����������ʹ�á�Ǭ��һ������\n");  
      
        if( (int)me->query_str() < 20 )
                return notify_fail("��ı�������ǿ������ʹ�á�Ǭ��һ������\n");
      
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("�������̫��������ʹ�á�Ǭ��һ������\n");
      
        if( (int)me->query("neili") < 800 )

                return notify_fail("�������̫���ˣ��޷�ʹ�ó���Ǭ��һ������\n"); 
        if( time()-(int)me->query_temp("qiankun_end") < 3 )
                return notify_fail("�����Ϣ��û��ƽ����\n");                     
       
        if( (int)target->query_condition("qiankunyibang"))
                return notify_fail("�Է��������С�Ǭ��һ�����������ˣ�\n");                                                                                
      
        jiali = me->query("force_factor")+1;
        attack = me->query("combat_exp")/1000;
        attack += me->query_skill("unarmed");
        attack += me->query("force")/5;
        defense = target->query("combat_exp")/1000;
        defense += target->query_skill("dodge");
        defense += target->query("force")/7;
//      attack = (attack+random(attack+1))/2;
        attack += random(defense+1);
      
        damage = me->query_skill("buddha-club", 1)/20 * jiali;
        if(damage > 23000) damage = 23000;
      
        message_vision(HIR"\n$NͻȻ��ɫ���죬���б���һ�����˫�۹ǽ�һ���죬��Ȼ�ڿն���˫�����������$n������ȥ����һʽ"HIY"��Ǭ��һ����"BLU"��\n"NOR,me,target);
 
//      if( attack > defense ) { 
        if( random( attack ) > defense/2 || !living(target) ) 
        { 
                if( objectp(armor = target->query_temp("armor/cloth"))
                && armor->query("armor_prop/armor") < 600
                && damage > 100)
                {
if (!armor->query("systemmake") && !armor->query("ownmake"))
{
                        message_vision(HIY"ֻ����һ����������$N��$n"HIY"�ϣ�����������÷��飬�ѳ�һ�����ڵ��ϣ�\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "�����" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
}
                }
                tell_object(target, RED"��ֻ���û����ؿ�һ���ʹ������������ɢ�˼�һ����\n"NOR);
                target->apply_condition("qiankunyibang", 6+(me->query_str()));
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                target->add("neili",-damage);
                target->start_busy(2);
                if ((int)target->query("neili")<0)
                {
                        target->set("neili",0);
                     message_vision(HIR"$nһ����Ѫ���������\n"NOR,me,target);

                }
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                message_vision(msg, me, target);
                me->add("neili", -jiali);
        }
        else 
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                //message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
        }
//      me->add("force", -200);
//      me->start_busy(1+random(2));  
        me->set_temp("qiankun_end",time());          
        return 1;
}

 
