// Room: /d/linzhi/by05.c

inherit ROOM;

void create()
{
	set("short", "���л���ʯ·");
	set("long", @LONG
���������ֻ��·�������������������������æµ�š�
����һ��������¥լ��������ǰ��������Ǳ��������ү��ס����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"byhouse_gate",
  "west" : __DIR__"by04",
  "north" : __DIR__"by06",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
