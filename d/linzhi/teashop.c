// Room: /d/linzhi/teashop.c

inherit ROOM;

void create()
{
	set("short", "��һǮׯ");
	set("long", @LONG
����һ���һ���ϵİ�һǮׯ�����������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"by15",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/qian" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
