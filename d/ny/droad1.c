
// Room: /d/snow/droad1.c

inherit ROOM;

void create()
{
        set("coor",({-20,5000,13}));
	set("short", "ɽ·");
	set("long",
"����һ�����������߹���ɽ·��·�ߵ��Ӳ��ѽ�С·�ڸǡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown": __DIR__"droad0",
  "northup": __DIR__"droad2",
]));
	set("outdoors", "ny");
	setup();
	replace_program(ROOM);
}
