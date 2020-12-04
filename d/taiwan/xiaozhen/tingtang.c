// Room: /d/taiwan/tingtang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ��С����,�������д����˵ĵط�,��Ȼ��Ϊû�˴�ɨ,���������� 
����һ��ҳ�.������Ҿ߰ڷŵ�һ˿����.����������������. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"room2",
  "south" : __DIR__"xiaolou",
  "east" : __DIR__"room1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zongwuwei.c" : 1,
  __DIR__"obj/xiao_table.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
