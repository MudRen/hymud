#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name(HIM "��ȡѫ��" NOR, ({ "study emblem", "emblem" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "��������ѧϰ��������\n" NOR);
                set("unit", "��");
                set("no_put",1);
	              set("no_beg",1);
	              set("no_steal",1);
                set("no_clone",1);
                set("value", 10000);
        }
        setup();
}


int query_autoload() { return 1; }

