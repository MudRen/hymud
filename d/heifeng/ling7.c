// Room: /d/heifeng/ling7.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ�����͵�С·��խ��ֻ����һ�����ߣ�������������
�£������ǳ���������ʯ�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ling6",
]));

	set("outdoors","heifeng");
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!me || arg != "����")
		return 0;

	write("�㳶���������˳�ȥ��\n");
	me->move(__DIR__"lu10");
	tell_room(__FILE__,sprintf("%s�����������˽�ȥ��\n",me->name()));
	return 1;
}
