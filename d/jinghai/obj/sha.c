#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIY"������ɱ��"NOR, ({ "sha ling", "sha" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����糤������,�������[ɱ]�����֡�\n");
                set("value", 500);
        }
}

