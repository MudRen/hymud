// Room: /d/linzhi/shop.c

inherit ROOM;

void create()
{
	set("short", "�ӻ����ʷ�");
	set("long", @LONG
����һ���һ���ϵ��ӻ����ʷ������������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"by03",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 1,
 	__DIR__"npc/yang" : 1,
]));
	setup();
	replace_program(ROOM);
}
