//bi.c.�����
//date:1997.8.28
//by dan   

#include <ansi.h>
#include <armor.h>
inherit WRISTS;   

void create()
{
        set_name(YEL"�����"NOR, ({ "cheng tian bi","bi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���������������. \n");
                set("unit", "��");
                set("value", 500000);
                set("material", "yu_stone");
                set("armor_prop/armor", 30);
                set("armor_prop/personality", 1);
                set("female_only", 1);
        }
        setup();
}

