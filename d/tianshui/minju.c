// Room: /d/tianshui/minju.c

inherit ROOM;

void create()
{
	set("short", "Ժ��");
	set("long", @LONG
������һ�����͵����СԺ��Ժ���ұ���һ��ĥ�̣�����ĥ
����һ�ھ�����ֻ��ĸ����Ժ�����ҡ��ڵ����š�Ժ������ʰ
�úܸɾ����ɵ���ȴ�м���Ѫ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wroad2",
  "north" : __DIR__"minju2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hen" : 2,
]));

	set("cannot_build_home",1);

	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
