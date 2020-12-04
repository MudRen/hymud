inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_use", "use");
}
void create()
{
        set_name("金创药", ({"jinchuang yao", "jin", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包武林人士必备的金创药。\n");
                set("value", 6000);
        }
        setup();
}
int do_use(string arg)
{
        if (!id(arg)) 
                return notify_fail("你要用什么药？\n");
        if ( this_player()->query_condition("jin-chuangyao"))
                return notify_fail(
"你已经敷上金创药了。\n");
        if ((int)this_player()->query("eff_kee") ==
            (int)this_player()->query("max_qi"))
                return notify_fail("你现在不需要用金创药。\n");
        else {
                message_vision("$N把金创药敷在伤口上。。。。。。\n", this_player());
                if( this_object()->query("usetime") >10)
                           destruct(this_object());
                else
                           this_object()->add("usetime",1);
                this_player()->apply_condition("jin-chuangyao",8);
                return 1;
        }
}

