// Room: /d/jinghai/xiuxishi.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
����һ����Ϣ�ҡ�

LONG
	);
        set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaolu1",
]));

	setup();
	replace_program(ROOM);
}
