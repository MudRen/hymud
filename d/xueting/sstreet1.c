// Room: /d/xueting/sstreet1.c

inherit ROOM;

void create()
{
	set("short", "ѩͤ�ֵ�");
	set("long", @LONG
������ѩͤ���ϱ���������Ľֵ���������һ���ջ��������
��һ���ӻ��̣��ֵ�����ͨ���㳡�ϱߣ����ϴ���һ����������⡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//  "west"  : __DIR__"store",
  "north" : __DIR__"guangchang_s",
  "south" : __DIR__"sgate",
  "east"  : __DIR__"temple",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
