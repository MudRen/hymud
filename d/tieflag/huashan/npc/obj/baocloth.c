 // cloth.c
#include <ansi.h>
#include <armor.h> 
inherit CLOTH; 
void create()
{
    set_name(CYN"�����"NOR, ({"qing shan", "cloth"}) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
                set("unit", "��");
                set("long", "һ������ɫ��˿������");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/per", 1);
                set("value",1000);
    }
    setup();
}   
