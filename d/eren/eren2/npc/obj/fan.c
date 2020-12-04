 // silencer@fengyun.com
#include <ansi.h>
inherit ITEM; 
void create()
{       set_name("大蒲扇",({ "fan" }) );
        set_weight(10000);
        set("unit", "把");
        set("long", "一把用竹子编成的大蒲扇。\n");
        set("value", 1000);
        
} 
void init(){
        add_action("do_wave", "wave");
} 
int do_wave(string arg){
        
        object me;              
        me = this_player();
        if (!arg && arg!="fan" && arg!="大蒲扇") {
                tell_object(me,"你要扇什么？\n");
                return 1;
                }
        if( me->is_busy() ){
                tell_object(me,"你现在正忙。\n");
                return 1;
        }
        message_vision("你拿起一把大蒲扇，呼呼地扇了几下，凉风习习，心里顿时舒畅了许多。\n",me);
        if (me->query("bellicosity")>50)
                me->add("bellicosity",-50);
                else me->set("bellicosity",0);
        me->start_busy(1);      
        return 1;
}
