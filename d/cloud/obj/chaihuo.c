
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( "һ�����", ({ "chaihuo"}) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");               
                set("value", 0);
                set("material", "iron");
        }
        setup();
}
