
inherit ITEM;
void create()
{
	set_name("ʪ������", ({"shenxiang", "shipo"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������۵�����,ÿ���Դ��϶�����ֻ�۾�.\n");
		set("unit", "��");
             set("no_get",1);
	}
setup();
}
