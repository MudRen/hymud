// qizi.c

#include <weapon.h>

inherit COMBINED_ITEM;



void create()
{
	set_name("����", ({ "qi zi", "zi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"һ��������ϸ�����ӡ�\n");
		set("unit", "��");
	}
	set_amount(100);
	setup();
}
