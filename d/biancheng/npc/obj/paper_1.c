 inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name("碎纸片左上角", ({ "some paper","paper"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
        set("long", "一张撕碎了的纸片，上面写着“易大经”。\n");
        set("value", 2);
        set("lore",1);
        }
         
}  
 