// xuanling.c ����������
#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIG"����������"NOR, ({ "xuan ling", "ling" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǹ����糤������,���������������[����]��\n");
        }
}

