#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("����", ({"dragon scale"}) );
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "���ۡ�\n" NOR);
                set("unit", "��");
                set("base_unit", "��");
                set("base_value", 20000);
                set("base_weight", 600);
        }
        setup();
        set_amount(1);
}
