// Room: /d/jinghai/shulin2.c

inherit ROOM;

void create()
{
	set("short", "�һ�����");
	set("long", @LONG
�����һ����С�


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin3",
  "west" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
