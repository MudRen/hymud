// Room: /d/jinghai/houmen.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
�������ɽׯ����

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taohuayuan",
  "northeast" : __DIR__"shulin1",
  "west" : __DIR__"kongdi",
  "south" : __DIR__"bingqishi",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
