#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("����ľ��", ({ "table" }));
        set_weight(40000);
	set("long", "���������õ�����,����մ���ҳ���\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
		   set("value", 1000);
                set("mask","ׯ");
        }
        setup();
}

