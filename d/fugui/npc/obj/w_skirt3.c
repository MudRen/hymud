 // cloth.c
// 
#include <armor.h> 
inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIG"�����������ȹ"NOR, ({ "huaskirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����䳤ȹ���ֳ���Ů��������ˣ�������Ȼ��\n");
                set("material", "cloth");
        set("value", 2000);
         set("armor_prop/armor", 3);
                set("armor_prop/dodge", 1);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        
}   
