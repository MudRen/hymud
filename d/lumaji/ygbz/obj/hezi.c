#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("Сͭ��", ({ "tong he"}) );
        set_weight(300);
        set_max_encumbrance(50000);
        set("unit", "��");
        set("no_drop", "�������������뿪�㡣\n");
        set("no_get", 1);
        set("no_sell", 1);
        set("no_put", 1);
        set("no_give", 1);
        set("material", "steel"); 
        setup();
} 

