// baihe.c

inherit ITEM;

void create()
{
	set_name("�ٺϻ�", ({ "lily" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ֦�����İٺϻ���\n");
		set("unit", "֦");
		set("value", 100);
	}
}
