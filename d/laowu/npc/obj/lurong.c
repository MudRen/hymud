 // medicine.c
inherit ITEM; 
void create()
{
        set_name("鹿茸",({"lurong"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一包鹿茸，可以用（ｙｏｎｇ）来治伤 。\n");
            set("unit","包");
        set("value", 8000);
        }
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
    int value = 50;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        diff = this_player()->query("max_qi")-this_player()->query("eff_qi");
        if(!(diff))    return notify_fail("你没有受伤！\n");
        if(value > diff) value = diff;
            
        message_vision("$N用鹿茸疗伤 ．\n",this_player());
        this_player()->add("eff_qi",value);
        destruct(this_object());
        return 1;
}       
