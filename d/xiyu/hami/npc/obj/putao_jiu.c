// putao_jiu.c  ���Ѿ�
// Ffox 98-4-30 20:29

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name(MAG"���Ѿ�"NOR, ({ "putao jiu", "jiu" }));
    set_weight(300);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ��СС��װ�����ѾƵ�С�ƺ���\n");
        set("unit", "ƿ");
        set("value", 250 );
        set("max_liquid", 40);
    }
    set("liquid", ([
        "type": "alcohol",
        "name": MAG"���Ѿ�"NOR,
        "drunk_apply": 5,
    ]));
}

void init()
{
    this_object()->delete("value");
    add_action("do_drink","drink");
}
