// Room: /d/linzhi/silkshop.c

inherit ROOM;

void create()
{
	set("short", "��һ����");
	set("long", @LONG
����һ���һ���ϵİ�һ���̡����������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"by01",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/tang" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
