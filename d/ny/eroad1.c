
// Room: /d/snow/eroad1.c


inherit ROOM;

void create()
{
	set("coor",({1100,4600,10}));
	set("short", "����С��");
	set("long",
"����һ����ͨ�Ļ���С������������������һ·������ɽ����Զ����һ���������������\n"
"��Զ������Զ�ǵĽֵ���\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"eroad2",
//  "north" : "/d/snow/temple",
  "northwest" : __DIR__"road12",
]));
	set("outdoors", "ny");

	setup();
//        replace_program(ROOM);
}
