 inherit ITEM;
void create()
{
        set_name("垃圾", ({ "trash" , "垃圾"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "堆");
        set("long", "与其说是垃圾，不如说是尸体堆，成堆的尸体散发是腐臭。\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; }      
