 // neon@fengyun.com
#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void generate_name(); 
void create()
{       set_name( HIB"毒蒺藜"NOR, ({ "du jili" , "jili"}) );
        set_weight(10);
        set("unit", "颗");
        set("long", "一颗淬满了剧毒的暗器，可以降低敌人的心神。(shoot)\n");
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
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("你要对谁使用暗器？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n"); 
        target = present(arg,environment(me));
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");      
        
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
        exp   = (int) me->query("combat_exp");
        msg  = HIB"$N中指一弹，扣在手心的毒蒺藜激射而出！！\n\n"NOR;
   if( random(exp)*level/10 + exp/3 > t_exp ) {
                damage = me->query_skill("perception",1)* level /10;
                damage = damage/2 + random(damage);
                msg +=  HIM"$n闪避不及，被毒蒺藜打中肩头，顿时一阵头昏眼花。\n" NOR;
                target->receive_wound("qi", damage/10);
                target->add("jing",-damage);
                target->add("eff_jing",-damage);
                target->receive_wound("jing",10);
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
}     
