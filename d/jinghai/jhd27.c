// Room: /d/jinghai/jhd27.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����ɽ���ϡ�

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"jhd6",
]));
        set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
