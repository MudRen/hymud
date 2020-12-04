 // neon@fengyun.com
#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void generate_name(); 
void create()
{       set_name( WHT"��������"NOR, ({ "shen zhen" , "zhen"}) );
        set_weight(10);
        set("unit", "��");
        set("long", "һ����Ө�����룬��˵��ǧ�����Ѫ����ݹ����������������shoot����\n");
        set("value", 3000);
        set("level", 50);
        set("no_drop", 1);
        
} 
void init(){
        add_action("do_shoot", "shoot");
} 
int do_shoot(string arg){
        object me, target;
        int level, exp, t_exp, damage;
        int busy_num;
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("��Ҫ��˭ʹ�ð�����\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n"); 
        target = present(arg,environment(me));
                
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");      
        if (target->is_busy())
                return notify_fail("�Է��Ѿ����ܶ����ˡ�\n");
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
   exp   = (int) me->query("combat_exp");
        msg  = HIW"\n$N����һ�ӣ�"NOR +name()+HIW"������Ϣ�طɳ���\n\n"NOR;
        if( random(exp)*level/50 + 4*exp/5 > t_exp ) {
                damage = me->query_skill("perception",1)* level /10;
                damage = damage/2 + 2 * random(damage);
                msg +=  HIM + "$n����һ�飬�������ã�\n" NOR;
                target->receive_wound("qi", damage/20);
                target->add("jing",-damage/5);
                target->add("eff_jing",-damage/5);
                target->receive_damage("jing", 1);
                if (target->query("no_busy")) {
                        busy_num = target->query("no_busy");
                        target->delete("no_busy");
                        call_out ("busy_recover",12, busy_num, target);
                }
                target->start_busy(4);
        } else
                msg += "���Ǳ�$n�㿪�ˡ�\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
} 
int busy_recover (int busy_num, object obj)
{
        obj->set("no_busy",busy_num);
        return 1;
}        
