 //libie.c
// - neon 
/*    
��Ȼ�����ߣ�Ψ������ӣ�
...... 
���±ڶ����ʣ����������ɹ⡣
������֮��¶�������֮��˪��
Ѳ��麶����ڣ�����Ļ��������
֪����֮�������֮���
... 
�ʱ���һ�����������塣
... 
���������������������ᣬ�����������Ϳͽ�ȡ�
����������ĳ£��ࡢ�Ը��������ˣ�
����������ĺ�������⽿�ϴ���
������֮��������Ԩ��֮���ۡ�����ֶ����飬�м�į������
... 
�������ǧ�ϧ����֮ͽ����
���Ĺ�֮��ɪ���޸�̨֮���ơ�
�����մ���̦ɫ�����ʺ������¹⣬
���������粻ĺ����������ҹ�γ���
֯���������Ѿ�������ʫ��Ӱ���ˡ� 
... 
���Ա𷽲���������ǧ�����б��Թ����Թ��ӯ��
ʹ������񺧣����۹Ǿ�����Ԩ����֮ī��ϡ���֮�ʾ���
���֮���壬��̨֮ȺӢ����������֮�ƣ����е���֮����
˭��ġ����֮״��д����֮���ź��� 
...
*/ 
// ��Ȼ������Ψ����� 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int libie_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg, weather;
        int extra,skill;
        object weapon; 
        if( !target ) target = offensive_target(me); 
// capped the sword at 575,
        skill = me->query_skill("sword")>575? 575:me->query_skill("sword");
                extra = 3 * skill *2; 
                if (me->query("class")!="swordsuper") extra = extra/4;
                if(me->query_skill("sword",1)> 350) extra = 3 * skill;  
                if(me->query_skill("sword",1)> 449) extra = 4 * skill;  
         extra = me->query_skill("music",1);
        if ( extra < 280) return notify_fail("����ٵ����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ǽ�������ʩչ�����ݡ�\n");
                
    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
//      extra = 788 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(MAG"������"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");  
        weapon = me->query_temp("weapon"); 
if (extra> 200) extra=200;
        me->add_temp("apply/attack", 200); 
        me->add_temp("apply/damage", 2000);
        msg = HIC"$N����"+ weapon->name()+ HIC"�������ǰ�Ĺ�â�������ա�����\n"HIW"��â��̴٣��������Ѿ�û���ǹ��ܱ��������ã��Իͣ�����\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       target->receive_damage("qi",(random(500)+100),me);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
                libie_sword(me,target,extra,weapon);
        me->start_busy(2);  

        return 1;
} 
int libie_sword(object me,object target,int extra,object weapon)
{
        string msg, wname;
        int d;
        int damage;
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0; 
if (!target->is_busy()) target->start_busy(3);
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",2000);
        target->delete_temp("last_damage_from");
        msg = WHT"��â��ȥ֮��$n"NOR+WHT"��ǰ��Ȼ���ֳ�������Ҷ�£���ʼ�Զȥ�Ĺ·���\nһʱ���г������������ļ�į����ʹ��";
        msg += YEL"$N����" + weapon->name() + YEL"����������������������֮����\n��ʯ���ɫ�䣬���Ɐ��������\n"NOR;
        me->set_temp("libie",1);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->receive_damage("qi",(random(600)+100),me);
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-2000);  

        msg = HIB"������һƬ���ţ��紵��ľ��������û�У�Ҳ���Ƿ�����ʹ��������"NOR;
        msg += HIG"$N����" + weapon->name() + HIG"��Ȼ�����������������Ʈ�� . . . \n˭���������е�����֮״������֮���أ�"NOR;         
            me->add_temp("apply/attack",200);
            me->add_temp("apply/damage",2000);
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            target->receive_damage("qi",(random(700)+100),me);
            me->add_temp("apply/attack",-200);
            me->add_temp("apply/damage",-2000);  

                message_vision(HIR"$N��Ȼ�����������Ʈ翣����α���Ľ�Ӱ�м��������� \n"NOR,target);
                message_vision(HIW"��  Ȼ  ��  ��  �� �� Ψ  ��  ��  ��  ... ...  \n"NOR,me);
                if  (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")  || random(3)==0) {

damage=	target->query("qi")/3;
if (damage>8000) damage=8000;
                                         target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage,me);
                                target->apply_condition("libie", 25);


                                msg = MAG"���Ǽ�������ţ�$n"MAG"ͻ��һ�������ʹӿ����ͷ��\n"NOR;
                                message_vision(msg,me,target);
        } 
me->add("neili",-300);
 me->start_busy(2);

        return 1;
}  
