// Room: /d/jindezheng/shulin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/kaifeng/yanqing",
  "north" : __DIR__"street3",
  "southwest" : __DIR__"shulin2",
]));
	set("outdoors", "/d/jindezheng");

	setup();
//	replace_program(ROOM);
}

