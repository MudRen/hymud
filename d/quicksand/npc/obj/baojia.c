 // icy_cloth.c
#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name(BLK"����"NOR, ({ "black cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 8000);
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 15);
        }
        
}    
