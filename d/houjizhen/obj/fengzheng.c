// fengzheng.c
// By dicky

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"大风筝"NOR, ({"da fengzheng"}));
        set_weight(4000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "这是一个非常特殊大风筝，估计是用来飞行的。\n");
               set("unit", "个");
        }
        setup();
}
