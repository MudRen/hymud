// Room: /d/jinghai/muqiao.c

inherit ROOM;

void create()
{
	set("short", "Сľ����");
	set("long", @LONG
����Сľ���ϡ�

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaoxi",
  "northeast" : __DIR__"lukou",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
