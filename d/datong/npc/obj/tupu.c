// tupu.c

inherit ITEM;

void create()
{
	set_name("ȭ��ͼ��", ({ "quanfa tupu"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ���������ͼ�ס�\n");
	}
}