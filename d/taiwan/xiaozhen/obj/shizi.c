#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ʯʨ��", ({ "shizi" }));
        set_weight(70000);
	set("long", "һֻʯͷ��̶��ɵ�ʨ��,����ȥ�������硣\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "stone");
		   set("value", 6000);
                set("mask","ׯ");
        }
        setup();
}

