// Room: /u/xiaozhen/linlu4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ����С�������ϣ����¿���һƬС���֣�������
һ��ܴ����ʯ�塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"linlu3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/xia" : 1,
	__DIR__"npc/toumu" : 1,
	__DIR__"obj/stone" : 1,
]));
	setup();
}

void init()
{
	add_action("do_za","za");
}

int do_za(string arg)
{
	object me = this_player(), obj;

	if(!objectp(obj = present("stone",me)))
		return 0;

	if(!arg)
		return notify_fail("��Ҫ��ʯ����ʲô��\n");

	if((arg != "ʯ��") && (arg != "��ʯ��"))
		return notify_fail("��Ҫ��ʯ����ʲô��\n");

	if(!query("exits/down"))
	{
		set("exits/down" , __DIR__"didong1");
		message_vision("������ʯ��������ʯ����ȥ��һ�°�ʯ�������ˡ�\n",me);
		destruct(obj);
	}

	return 1;
}
