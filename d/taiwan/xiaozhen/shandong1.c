// Room: /d/taiwan/shandong1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ͨ��ɽ�е����,���ߵ�ʯ�����������Զ����һ��ҹ����
��������,��������ط���Щ��ɭ�ֲ�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room1",
  "north" : __DIR__"shandong2",
]));

	setup();
	replace_program(ROOM);
}
