#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"ҹ����"NOR, ({ "yemingzhu","zhuzi","mingzhu" }));
        set_weight(10000);
	set("long", "��ʹ�ںڰ���Ҳ�ڲ�ס���ã�����顣\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
		   set("value", 10000);
                set("mask","ׯ");
        }
        setup();
}

