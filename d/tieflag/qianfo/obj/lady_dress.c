 // lady_dress.c
#include <armor.h> 
inherit CLOTH; 
void create()
{
        set_name("���޳���", ({ "lady dress", "dress" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ֹ��൱ϸ�£�������͸���ĳ���\n");
                set("unit", "��");
                set("value", 700);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("armor_prop/intelligence",3);
                set("female_only", 1);
        }
        
}   
