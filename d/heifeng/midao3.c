// Room: /d/heifeng/midao3.c

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
  "south" : __DIR__"midao4",
  "west" : __DIR__"midao2",
]));

	setup();
}
