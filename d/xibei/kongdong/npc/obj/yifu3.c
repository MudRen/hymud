#include <armor.h>
#include <ansi.h>
inherit CLOTH;


void create()
{
        set_name(BLU "��������" NOR, ({ "cloth" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ������ͨͨ�Ķ���������������ġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
