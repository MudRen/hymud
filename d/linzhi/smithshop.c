// Room: /d/linzhi/smithshop.c

inherit ROOM;

void create()
{
	set("short", "�������ʷ�");
	set("long", @LONG
����һ���һ���ϵ��������ʷ������������˲��࣬
ֻ�м���С������һ����ˣ���������Ҳ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"by14",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/smith" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
