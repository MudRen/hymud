#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
        set_name(RED"��ͭ���ľ�"NOR , ({ "copper plate", "plate" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͭ���ľ��������Ȼ���Ÿ���һ���֡�\n");
                set("value", 7000);
                set("material", "copper");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
        }
//      ::init_waist();
}      
