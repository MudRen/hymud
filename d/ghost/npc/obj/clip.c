#include <armor.h>
inherit HEAD; 
void create()
{
        set_name("��ľ��", ({ "black clip", "clip" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "wood");
                set("armor_prop/armor", 2);
        }
        
}
