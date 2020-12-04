 // pipe.c
inherit ITEM; 
void create()
{
        set_name("铜哨",({ "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("lore",1);
                set("material", "steel");
                set("long", "一根约两寸多长的铜哨。\n");
        }
        
} 
void init()
{
        add_action("do_blow", "blow");
} 
int do_blow(string arg)
{
          object me;
          me=this_player();
        if( arg != "pipe" ) return 0; 
        message_vision("$N拿起一个" + this_object()->name() + "吹了一声。\n", this_player() );
           if(me->query("class")!="ghost"){
               environment(this_player())->pipe_notify(); 
               														}
        return 1;
}       
