// stone.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ʯ��", ({ "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͨ��ʯͷ��\n");
                set("value", 1);
                set("material", "stone");
        }
        setup();
}
