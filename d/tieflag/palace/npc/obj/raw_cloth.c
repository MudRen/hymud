#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("��Ƥ", ({ "hide"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("for_create_cloth",1);
                set("material", "cloth");
                set("long", "һ��Ұ��Ƥ��\n");
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        
}   
