// Room: /d/heifeng/shinv.c

inherit ROOM;

void create()
{
	set("short", "ʹŮ��");
	set("long", @LONG
����һ���ª��ľ�巿���Ƿ���կ����ʹŮס�ķ��䣬ǽ��
��һ�Ŵ󴲣��ű߷������㡢����֮��Ĺ��ߡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corr07",
]));

	setup();
	replace_program(ROOM);
}
