// Room: /d/lumaji/lu4.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ����ʯ�̳ɵ�С·���м䳤��һЩ�Ӳݡ�·�������һ��
С�ӻ��꣬�ұ���һƬ�ݵء�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zahuo",
  "south" : __DIR__"lu5",
  "north" : __DIR__"lu3",
  "east"  : __DIR__"caodi1",
]));
	set("objects", ([
		"/clone/npc/man" : 2,
	]));

	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}