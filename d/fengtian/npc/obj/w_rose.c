// w_rose.c

inherit ITEM;

void create()
{
	set_name("��õ��", ({ "white rose" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ֦���ŵİ�õ�廨��\n");
		set("unit", "֦");
		set("value", 100);
	}
}
