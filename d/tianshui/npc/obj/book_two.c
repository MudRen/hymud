// book_two.c
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("�ٲݾ�(�²�)", ({ "book_two"  }) );
    set("unit", "��");
    set("long","����һ����Ƥ�Ѿ����Ƶ��顣\n");
    set_weight(50);
    setup();
}