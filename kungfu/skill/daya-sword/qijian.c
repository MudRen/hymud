

//����ָ(qijian)--���ŹŽ���
//lestat /6/5/2001�ı����������

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include <combat.h>

inherit F_SSERVER;


string *qijian_msg = ({
//�̸�
HIC"\n$NͻȻԾ�����࣬$n"+NOR+HIC"һ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�Ӻ�Ϯ����\n"NOR,
HIC"$N��б������������Сָ�������������ҵ�б����ȥ�����̸�����ֱ��$n"+NOR+HIC"$l��\n"NOR,
HIC"\n$N�ֱ۶�Ȼһ�ᣬ��������$n"+NOR+HIC"����һ��֮������������Ϊָ��\n"NOR,
//����
HIW"\n$N��Цһ���������$N���������ϣ�˫�����õ��ģ���������֮������$n"+NOR+HIW"����֮�ʣ�һ�С�������������$w"+NOR+HIW"�ɴ���$n��\n"NOR,
HIW"\n$N����ָһ�ӣ�׾�͹��ӵġ�������������ֱ��������˶������ش���$n��\n"NOR,
//����
HIR"\n$N������ϣ�˫�ֻó�����ָӰ��$n"+NOR+HIR"�ļ���һ���ٺ�ɳ�ȥ�������е�$w"+NOR+HIR"��������������ָ��$n"+NOR+HIR"��$l��\n"NOR,
HIR"\n$NĴָһ����ʳָ���������ˡ�����������һ�ƽ�����$n"+NOR+HIR"�̳���\n"NOR,
HIR"\n$Nʳָ����������������һ����һ���Ĵ̳���������Ѹ�٣������ޱȣ�\n"NOR,
HIR"\n$N��ʳָ�������ν�����ȴ��������ָ�����緶Χ��ת������������������$n"+NOR+HIR"һ��һ����\n"NOR,
//����
HIG"\n$N��ָһ����һʽ�����Ͻ�����ǰ�̳���\n"NOR,
HIG"\n$NǱ���������������ˣ�����$n"+NOR+HIG"������ת������$w"+NOR+HIG"���˽���Ҳ��������һ�㣬Խ��Խ�죡\n"NOR,
HIG"\n����ʯ֮�䣬$Nһ���ƣ��������ƣ��������������ֶ�Ȼ̽���������Ͻ���������$n"+NOR+HIG"������\n"NOR,
//���
HIY"\n$N��������ǰ�������Сָ��һ�С���ɽ��������ص���$n"+NOR+HIY"�������Ѩ����ָ������\n"NOR,
HIY"\n$NСָһ����ʹһ�С���ɽ�����������ͬ����һ�㣬Ʈ�����ң�\n"NOR,
HIY"\n$Nһ�С���ɽ�����������ת������������˹���������$n"+NOR+HIY"��$l��\n"NOR,
HIY"\n$N����Сָһ�ӣ�һ�С���ɽ������̴̣�����񻨴̻�һ�㣡\n"NOR,
//ֹ�
HIM"\n$N��Ȼ����Ϊ�����ֳ�����������Ӱ���ٻ���$n"+NOR+HIM"������$w"+NOR+HIM"�û�������ֱ��$n"+NOR+HIM"��$l����ֹ꫽���������ŭ������ӿ������\n"NOR,
HIM"\n$N��Ĵָ���ӣ���ֹ꫽���������һ����īɽˮ���ƣ��ݺ���б���������ʣ�ȴ�ǽ�·�۾���\n"NOR,
HIM"\n$N�ġ�ֹ꫽����󿪴��أ����ɺ�ΰ��ÿһ���̳�������ʯ���쾪���������֮�ƣ�\n"NOR,
});
string *target_msg = ({
//�̸�
"��ֻ����һ�����ν��������$l�����������仯��΢������ޱȣ�\n",
"��һ�����ν��������Ǻ�����ȥ���仯��΢��������޿ɱܣ�\n",
//����
"��о��������ν���׾�͹��ӣ������б�ίʵ���Լܵ���\n",
"��ν�����ɲ���������ֱ����������ν�����Ȼʹ���޴Ӷ�ܣ�\n",
//����
"�����εĽ���������������ĥ���û���ֱ���������\n",
"��������ж�죬Ҳ��������һ�ƽ�����˲���ѱƵ������ǰ��\n",
//����
"��е���һ��Ѹ�������ĵ����Ͻ����󿪴�ϣ�������ΰ���������޿ɵ���\n",
"��Ȼ����е������Ѩ����һ�ɴ󿪴�ϣ�������ΰ�����ν�������Χ��\n",
//���
"���ǽ������ý�ǰ�����Ǿ����������ƿ�֮��������\n",
"ֻ���Ǵ��������ν�����׾�����������������������������񽣣�\n",
//ֹ�
"ֻ���ǽ�·�۾���ʯ���쾪���Ƶ�������������޷��мܣ�\n",
"��������ν�������ʯ���쾪���������֮�ƣ��Ƶ����ݸ߷��ͣ��������ܣ�\n"NOR,
});

string *winner_msg = ({
        CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
        CYN "\n$n���һ�ݣ�˵�����������չ�Ȼ�������ⳡ�����������ˣ�\n\n" NOR,
        CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
        CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
        CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
        CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

string *winner_animal_msg = ({
        CYN "\n$N����һ�ԣ��������$n���ӣ�\n\n" NOR,
        CYN "\n$N���ؿ���������Ȼ�������ɵض���$n��\n\n" NOR,
        CYN "\n$N���˼���������ʱ�����ٳ������\n\n" NOR
});



int check_fight(object me, int amount, object weapon);
int check_qijian(object me, object target);
private int remove_effect(object me, int amount);
int perform(object me, object target)
{       
        string msg;
        int damage, p, skill;
        int damagea,extra,exp;
      
                object weapon = me->query_temp("weapon");  
        if(!me->query_skill("daya-sword", 1)) return 0;  
        
        if(((int)me->query_skill("daya-sword", 1) < 300 ||
            (int)me->query_skill("sword", 1) < 300))
                return notify_fail("��Ľ����������򻹲�����죬�������á�����ָ����\n");


        if(((int)me->query_skill("daya-sword", 1) < 800 && userp(me)))
                return notify_fail("������Ž��������ң��������á�����ָ����\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("���������Ϊ̫��������ʹ����������ָ������\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
      if( me->query_temp("zxzx") ) 
        return notify_fail("�������˹�,���ܷ������ã�\n");
        if(me->query_temp("start_qijian")) return notify_fail("���Ѿ�����������ָ�����ν����ˣ�\n");

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("������ָ��ֻ����ս����ʹ�á�\n");

//        tell_object(me, HIW"\n�����д�����г������ַ���,Ȼ�������ָ���ھ�������������ʼ��������ָ��\n"NOR);
        msg = HIW"\n$N���д������$w"+NOR+HIW"���ַ����������������裬Ȼ�������ָ���ھ�������������ʼ��������ָ��\n" NOR;
                msg=replace_string(msg,"$w",weapon->query("name"));
                message_vision(msg, me, target);
                me->set_temp("start_qijian", 1);
                skill = me->query_skill("daya-sword");
if (skill > 500) skill=500;
        me->add_temp("apply/dodge",  skill*2);    
    me->add_temp("apply/parry",  skill*2);
    me->add_temp("apply/attack",  skill/2);
                check_fight(me, skill, weapon);
//        remove_call_out("check_qijian");        
//        remove_call_out("checking");
//        call_out("check_qijian", 2, me, target);
//        call_out("checking", me->query_skill("daya-sword", 1), me);
                check_qijian(me,target);
        return 1;
}
/*
int checking(object me)
{
        if(me->query_temp("start_qijian")){
              me->delete_temp("start_qijian");
              tell_object(me, HIW"\n���ھ�����һ���죬������ָ����������һ�飡\n"NOR);
              }
        return 1;
}
*/
int check_qijian(object me, object target)
{
        string msg, *limbs, dodge_skill, str, limb;
        int lv, i, force, ap, dp, damage, p, j;
        mapping act, *action;
        object wep;
                object weapon = me->query_temp("weapon"); 
        lv = (int)me->query_skill("daya-sword", 1);

       
 action = ({
([      "action" : qijian_msg[random(3)],
        "t_msg" : target_msg[random(2)],
        "damage" : 5,
        "lvl" : 0,
        "skill_name" : "�̸���",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[3+random(2)],
        "t_msg" : target_msg[2+random(2)],
        "damage" : 6,
        "lvl" : 30,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[5+random(4)],
        "t_msg" : target_msg[4+random(2)],
        "damage" : 6,
        "lvl" : 60,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[9+random(3)],
        "t_msg" : target_msg[6+random(2)],
        "damage" : 5,
        "lvl" : 90,
        "skill_name" : "���Ͻ�",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[12+random(4)],
        "t_msg" : target_msg[8+random(2)],
        "damage" : 5,
        "lvl" : 120,
        "skill_name" : "��ɽ�",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[16+random(3)],
        "t_msg" : target_msg[10+random(2)],
        "damage" : 7,
        "lvl" : 150,
        "skill_name" : "ֹ꫽�",
        "damage_type" : "����"
]),
([      "action" : qijian_msg[random(sizeof(qijian_msg))],
        "t_msg" : target_msg[random(sizeof(target_msg))],
        "damage" : 2+random(8),
        "lvl" : 200,
        "skill_name" : "���Ž�",
        "damage_type" : "����"
]),
});

        if (lv >= 200) j = 6;
        else if (lv >= 150) j = 5;
        else if (lv >= 120) j = 4;
        else if (lv >= 90) j = 3;
        else if (lv >= 60) j = 2;
        else if (lv >= 30) j = 1;
        else j = 0;
        act = action[random(j)];
        damage = act["damage"];
        msg = act["action"];
        force = (int)me->query("neili");        

        if(!living(target) || !target || !me->is_fighting() || environment(me) != environment(target)){
                me->delete_temp("start_qijian");
                return 1;
                }
       if(!me->query_skill("daya-sword", 1) || !me->query_temp("start_qijian")){
                me->delete_temp("start_qijian");
                return 1;
                } 

        if(force < 2500){
                tell_object(me,"�㷢���Լ����ڵ�����̫�����Ѿ�����ʹ��������ָ���ˡ�\n");           
                me->delete_temp("start_qijian");
                return 1;
                }      
        if(me->is_busy()){
                call_out("check_qijian", 2+random(8-j), me, target);
                return 1;
                }

        ap = me->query_skill("force") + me->query_skill("daya-sword", 1) + me->query_int();
        dp = target->query_skill("force", 1) + target->query_skill("dodge") + target->query_int();
        ap *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg, "$l", limb);
       if (me->query_temp("weapon"))
                msg=replace_string(msg,"$w",weapon->query("name"));
        message_vision(msg, me, target);
        tell_object(target, HIR+act["t_msg"]+NOR); 
        wep = target->query_temp("weapon");

        if( random(ap+dp) > dp/2 || random(3)==0){
             me->add("neili", -damage*3);
             damage *= lv/2;
             damage -= target->query_temp("apply/armor")/2;
             damage += me->query("force_factor")*4;
             if(force > target->query("neili")*2) damage = damage*2;          
             if(damage > 3500) damage = 3500;

//the target has a weapon in hand
             if(objectp(wep) && random(2) == 1){   
//                       if(objectp(wep)){
                   if(me->query("neili") < target->query("neili")/2){
                        me->start_busy(1);
                        msg = HIY"���ֻ���ѵ�һ����$n"HIY"������$W"HIY"��Ȼ��������$w��\n" NOR;                        
                        }
                   else if(me->query("neili") >= target->query("neili")*2){
                         if(wep->query("rigidity") >= 3){
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                               me->start_busy(1);
                               //wep->move(environment(target));
                               wep->unequip();
                               target->receive_damage("qi", 150,me);  
                               target->receive_wound("qi", 125,me);   
                               msg = HIW"���ֻ��ž��һ����$n"HIW"����ס$W"HIW"��������ɣ�����Ҳ������ײ�������ѣ�\n" NOR;
                               target->reset_action();
}
                               }
                         else{
                                me->start_busy(1);
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                                msg = HIW"���ֻ���ĵ�һ���죬$n����$W"HIW"Ϊ$N��$w"HIW"���ϣ���Ϊ����Ķ���ʮ�أ����ϰ�գ��������׹⣡\n" NOR;
                                msg = replace_string(msg, "$W", wep->name());
                                wep->unequip();
//                                wep->move(environment(target));
                                wep->set("name", wep->query("name")+"��Ƭ");
                                wep->set("value", 0);
                                wep->set("unit", "Щ");
                                wep->delete("long");
                                wep->set("weapon_prop", 0);
                                target->reset_action();
 }
                                }
                        }       
                   else {       
                         if(wep->query("rigidity") >= 8){
                                me->start_busy(1);
                                msg = HIY"���ֻ��һ�����죬$W"HIY"��$w"HIW"�ĳ���²�ס�������ɻ��Ľ���\n" NOR;
                                }
                         else{
if (!wep->query("systemmake") && !wep->query("ownmake"))
{
                                me->start_busy(1);
                                wep->move(environment(target));  
                                msg = HIW"$n��æ��$W"HIW"һ��������һ������"+wep->query("unit")+"$W"HIW"�ֱ���ɣ�\n" NOR;
                                target->reset_action();
}
                                }
                         }
                   msg = replace_string(msg, "$W", wep->name());
                   msg = replace_string(msg, "$w", "���ν���");          
                   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);
                   }
             else{
                   target->receive_damage("qi", damage,me);
                   target->receive_wound("qi", damage/(2+random(4)),me);          
                   p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                   msg = damage_msg(damage, act["damage_type"]);
                   msg += "( $n"+eff_status_msg(p)+" )\n";
                   msg = replace_string(msg, "$l", limb);
                   msg = replace_string(msg, "$w", "���ν���");          
                   message_vision(msg, me, target);
                   if(wizardp(me)) tell_object(me, "qijian_damage: "+damage+" \n");
                                   msg=HIB"\n��������������˸��$w"HIB"�ڿ�������,ʱ���ɻ�$N���С�\n"NOR;
if (me->query_temp("weapon"))
                                   msg=replace_string(msg,"$w",weapon->query("name"));
                                   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);                   
                   }
            }
        else{
             me->start_busy(1);
//             HIY"$Nȫ�����һ��һ����������ֵرܿ����Ǽ��ٶ��������ν�����\n"NOR, target);
             dodge_skill = target->query_skill_mapped("dodge");
             if( !dodge_skill ) dodge_skill = "dodge";
             message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
             call_out("check_qijian", random(8-j), me, target);    
             } 
//              call_out("check_qijian", 1, me, target);  
/*       if(target->query("kee")*2 <= target->query("max_kee")
           && !target->is_killing(me->query("id"))
           && !me->is_killing(target->query("id"))){
             me->remove_enemy(target);
             target->remove_enemy(me);
             if (me->query("race") == "����") {
                                if (!me->query("mute") && target->query("mute"))
                                        message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, target);
                                        if (me->query("mute") && !target->query("mute"))
                                                message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, target);
                                        if (!me->query("mute") && !target->query("mute"))
                                                message_vision( winner_msg[random(sizeof(winner_msg))], me, target);
                        } else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, target);
             }
*/
       return 1;
}       

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
        call_out("check_fight", 1, me, amount, weapon);
//        me->start_perform(1, "����ָ");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
        string msg;
        object weapon = me->query_temp("weapon"); 
        object target;
        me->add_temp("apply/dodge", -amount*2);
    me->add_temp("apply/parry", -amount*2);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("start_qijian");
    if(living(me) && !me->is_ghost())
if (me->query("weapon"))
{
                msg=replace_string(msg,"$w",weapon->query("name"));         msg = HIB"\nһ������������$w"HIB"�ɻ�$N���У�\n" NOR;
                message_vision(msg, me, target);
//              msg=replace_string(msg,"$w",weapon->query("name"));
//      message_vision(HIB"һ������������$w�ɻ�$N���С�\n"NOR, me);
}
    return 0;
}




