// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�վƺ�", ({"jiuhu", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�վƵľƺ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 55);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�վ�",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
