 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(GRN"翠袖护心丹"NOR,({"cuixiu dan","dan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "据说乃是“黄山翠袖”的独门灵药，以七十二种名药炼制七十二天而成，\n色泽碧绿，护心养神，妙用无方。 。\n");
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
            
    message_vision("$N咽下一粒翠袖护心丹，一股暖流护住丹田，气息陡然畅通起来。。。\n",this_player());
        this_player()->add("eff_jing",value);
        destruct(this_object());
        return 1;
}     
