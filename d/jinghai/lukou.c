// Room: /d/jinghai/lukou.c

inherit ROOM;

void create()
{
	set("short", "��·���");
	set("long", @LONG
������·��ڡ�



LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"xiaolu1",
  "southwest" : __DIR__"muqiao",
//  "east" : __DIR__"matou1",
  "west" : __DIR__"shulin3",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
