 // icy_cloth.c
#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name(HIY"֯����������"NOR, ({ "dragon cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "cloth");
        set("armor_prop/armor", 350);
                //set("armor_prop/dodge", 5);
        }

} 
