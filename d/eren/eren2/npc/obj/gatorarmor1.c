#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("鳄皮", ({ "gatorskin"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "vine");
                set("long", "一张鳄皮，坚韧异常。\n");
                set("value", 1000);
                set("armor_prop/armor", 40);
                set("armor_prop/dodge", -5);
                set("armor_prop/courage",2);
        }
        
}  
