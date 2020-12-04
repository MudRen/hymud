// Room: /d/taiwan/matou.c

inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
һ��СС����ͷ,�ôִ��ľ���Ƴɵĸ���ֱ���򺣱�,����С����ͣ 
�����Ա�,����ˮ����æ����ê. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 2 */
  "in" : __DIR__"chuan",
  "south" : __DIR__"road",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/worker.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
