#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ȱ������", ({ "chair" }));
        set_weight(20000);
	set("long", "����̫ʦ���Ѿ�ֻʣ��������,���Ҵ�౻�������ˡ�\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
		   set("value", 2000);
                set("mask","ׯ");
        }
        setup();
}

