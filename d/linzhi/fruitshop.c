// Room: /d/linzhi/fruitshop.c

inherit ROOM;

void create()
{
	set("short", "�ز����ʷ�");
	set("long", @LONG
����һ���һ���ϵ�ˮ���ز��̡����������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"by01",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/clone/npc/man" : 1,
 	__DIR__"npc/yang3" : 1,
]));
	setup();
	replace_program(ROOM);
}
