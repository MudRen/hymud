// � /d/city/chuzhou/npc/obj/juan_hua.c

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
    set_name( MAG"�"NOR, ({"juan hua", "hua", "flower"}));
    set_weight( 15 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
ɽ������������ʥ��֮�磬Ҳ���������ľ��
LONG
        );
        set("unit", "��");
        set("material", "cloth");
        set("value", 30);
        set("armor_prop/personality", 2);
    }
}
