// Room: /d/zuojiacun/ju1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ͨͨ��סլ��û��̫��ĳ��衣�ݵ������һ
���������Ļ������ţ��Ա߼���һ�Ѹɲ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu2",
]));
	set("objects",([
	"/clone/npc/man" : 2,
]));


	setup();
	replace_program(ROOM);
}
