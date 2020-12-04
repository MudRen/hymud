// Room: /d/taiwan/dayuan.c

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������Ժ�Ǹ��ķ���Ժ��,�������᷿,�����Ǵ���,���ڵ�Ժ���Ｗ 
��������������õ���,�������ֿ��Ÿ��ֿ��޹�. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dianhu.c" : 1,
  __DIR__"npc/yuming.c" : 1,
]));
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"house3",
  "north" : __DIR__"zhangfang",
  "east" : __DIR__"ting.c",
]));

	setup();
	replace_program(ROOM);
}
