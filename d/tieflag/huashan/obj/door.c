 inherit ITEM;
void create()
{
        set_name("门板", ({ "门板", "door" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","under");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "个");
            set("long", "一个破碎的门板。\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }        
