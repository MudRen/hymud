#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;


void create()
{
        set_name(YEL "��«" NOR, ({"hu lu","pot","hu"}));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������װˮ�Ĵ��«����Ƥ��ƣ�������װ�ü�����ˮ��\n");
                set("unit", "��");
                set("value",3);
                set("max_liquid", 10);
        }
        set("liquid", ([
                "type": "water",
                "name": "��ˮ",
                "remaining": 10,
                "drunk_apply": 30,
        ]));
}
