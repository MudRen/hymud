#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("��Ƥ", ({ "gatorskin"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "vine");
                set("long", "һ����Ƥ�������쳣��\n");
                set("value", 1000);
                set("armor_prop/armor", 40);
                set("armor_prop/dodge", -5);
                set("armor_prop/courage",2);
        }
        
}  
