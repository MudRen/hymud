// 高丽纸 /d/city/chuzhou/npc/obj/gaoli_zhi.c
// by lala, 1997-12-13

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( RED"高丽"WHT"纸"NOR, ({"gaoli zhi", "zhi", "corean paper", "paper" }));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
据说高丽纸的制造工艺是从中国传过去的，但是高丽人加以改进，造出的高丽纸
质量非常的好，又传回中国来。中国的士大夫们非常喜欢这种纸，所以这种纸的
价格也非常的昂贵。
LONG
    );
                set("unit", "张");
                set("value", 1000);
                set("material", "paper");
        }
        setup();
}
