// ��ɰ�պ� /d/city/chuzhou/npc/obj/zishatao_hu.c

#include <ansi.h>

inherit ITEM;

inherit F_LIQUID;

void create()
{
    set_name(MAG"��ɰ�պ�"NOR, ({"zishatao hu", "hu", "pot"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
һ������װ�����ɰ�պ��������˵�������
LONG
        );
        set("unit", "��");
        set("value", 3300);
        set("max_liquid", 10);
    }
}

void init()
{
    add_action("do_drink",  "drink");
    add_action("do_fill",   "fill");
}