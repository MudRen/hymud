// Room: /d/taiwan/room1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��һ�������뵽,�����ź��Ȼ�Ǹ�ɽ�������,����¥��ɽ����,
����ô��������ڴ˽�¥,��Ȼ��������.��һ�ۿ�ȥ,ɽ�������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tingtang",
  "northeast" : __DIR__"shandong1",
]));

	setup();
	replace_program(ROOM);
}
