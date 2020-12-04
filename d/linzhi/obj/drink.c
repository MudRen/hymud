// wineskin.c  �ƴ�
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

mapping *data=({
(["name":"������",	"id":"drink",	"mw":-1,	]),
(["name":"����",	"id":"drink",	"mw":-1,	]),
(["name":"����",	"id":"drink",	"mw":-1,	]),
(["name":"����",	"id":"drink",	"mw":-1,	]),				
(["name":"���Ͳ�",	"id":"drink",	"mw":-1,	]),				
(["name":"��ˮ",	"id":"drink",	"mw":-1,	]),				
(["name":"ţƤ��",	"id":"drink",	"mw":-1,	]),				

});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ"+query("name")+"�Ĵ��룬���װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 25,
		"drunk_apply": 3,
	]));
}
