#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name("��첼��", ({ "cloth" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        
}    
