
#include <ansi.h>

inherit COMBINED_ITEM;


void create()
{
        set_name("����", ({ "bear hand" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ɢ���������������⡣\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 80);
        }
        setup();
        set_amount(1);
}
