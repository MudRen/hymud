// Room: /open/dt/shizilukou.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
���·�ͽ����������ｻ����һ����ˣ��������������
���·�������Ǽ������͸����¥������Ϊ���������˼��ַ�
�����󡣽ֱ߲�ʱ�й�������������������Ƕ���ţƤ��ţ��֮
�����Ʒ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu3",
  "east" : __DIR__"hongchanglu4",
  "south" : __DIR__"jinyangjie3",
  "north" : __DIR__"jinyangjie2",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
