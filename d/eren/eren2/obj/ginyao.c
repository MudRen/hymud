 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(RED"九花玉露丸"NOR,({"yulu wan","wan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "传说此药乃是采集每日晨曦时九种鲜花花瓣上的露水调制而成，外呈朱红\n色，清香袭人，养精蓄锐，功效不凡。。\n");
            set("unit","颗");
        set("value", 5000);
        }
        
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
        int value = 20;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        diff = this_player()->query("max_jing")-this_player()->query("eff_jing");
        if(!(diff))    return notify_fail("你没有受伤！\n");
    if(value < diff) value = diff;
            
    message_vision("$N小心翼翼咽下一颗九花玉露丸，但觉清爽无比，精神陡然一振。\n",this_player());
        this_player()->add("eff_jing",value);
        destruct(this_object());
        return 1;
}    
