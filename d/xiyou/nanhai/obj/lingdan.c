//Cracked by Roath
// lingdan.c �鵤 

inherit ITEM;


void create()
{
	set_name("�鵤", ({"lingdan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص��鵤������ȥ�ܹ�������Ѫ������ʱ��һ��ҩ�Ծͻ���ʧ���鵤Ҳ����Ӱ���ٵġ�\n");
		set("value", 500);
	}
	setup();
}

