// Room: /d/taiwan/undertree.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����е�һ���ճ�,�м�ֱ��һ�øߴ������,֦������˿�㴹����, 
�߲��������ӵ���ð����,����С����Χ�Ÿ�����ƮƮ������,�����ڽ� 
��Щʲô. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"road2",
  "southwest" : __DIR__"tree1",
]));
	set("outdoors", "/d/taiwan");
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/laoren.c" : 1,
  __DIR__"npc/kid1.c" : 1,
  __DIR__"npc/kid2.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
