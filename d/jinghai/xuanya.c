// Room: /d/jinghai/xuanya.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ϡ�



LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shulin2",
  "southwest" : __DIR__"shulin1",
  "west" : __DIR__"xuanya1",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
