// Room: /d/heifeng/midao4.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
������һ���ܵ������ϸɸɾ������ɼ��������˹������ܵ�
���ϵ�ʯ�ڹ���ˮ�顣
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mishi2",
  "north" : __DIR__"midao3",
]));

	setup();
}
