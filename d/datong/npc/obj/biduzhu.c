// biduzhu.c

inherit ITEM;

void create()
{
	set_name("�ܶ���", ({ "bidu zhu"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�Ų����۵ĺ����ӡ�\n");
	}
}