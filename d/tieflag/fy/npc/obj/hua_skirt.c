 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name("С��ȹ", ({ "xiaoskirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��׺����ɫС����ȹ��\n");
                set("material", "cloth");
                set("value", 2000);
                set("armor_prop/armor", 13);
        }
        setup();
} 
