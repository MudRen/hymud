#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{

	
	set_name(RED"��������"NOR, ({ "tishen wawa", "tishen wawa" }));
	set_weight(50);

	set("unit", "��");
	set("long",RED"����һ���ɰ����������ޣ��������ڹؼ���ʱ�����һ��\n"NOR);
	set("value", 500000);
	set("no_put",1);
	//set("no_give",1);
	//set("no_get",1);
	set("material", "iron");
	
}


int query_autoload() { return 1; }