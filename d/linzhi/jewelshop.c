// Room: /d/linzhi/jewelshop.c

inherit ROOM;

void create()
{
	set("short", "��ҩ���ʷ�");
	set("long", @LONG
����һ���һ���ϵĲ�ҩ���ʷ������������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"by07",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/clone/npc/man" : 1,
 	__DIR__"npc/yang2" : 1,
]));
	setup();
	replace_program(ROOM);
}
