// Room: /d/green/path5.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ƽ����ʯ��·, ������Կ�����������ĳ��֣�����
��������������;�ĵ�·��������һ����С����ʯ·ͨ�����ڡ���
����һ��ʯ�ݣ��ԱߵĿյض���һЩʯ�ϡ��ϱ߿�ȥ��һƬ�����ԡ�
ʯ��·���������졣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//"north" : "/u/girlvillage/villagepath0",
  "west" : __DIR__"path6",
  "south" : __DIR__"diaoyuchi",
  "east" : __DIR__"work",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
