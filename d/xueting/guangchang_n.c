// Room: /d/xueting/square_n.c

inherit ROOM;

void create()
{
	set("short", "�㳡����");
	set("long", @LONG
������ѩͤ��㳡���ߣ�ƽ���Ǹ�����ͯ��Ϸ����ĵط�����
һ��ʮ�������м������ڣ�����һ����լԺ���������ߺ��������
�Ͽ��Կ���һ�����������������һ����ֱ�Ľֵ���
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/child" : 1,
//        __DIR__"npc/child2" : 1,
	]));
	
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"street02",
  "south" : __DIR__"guangchang",
  "west" : __DIR__"bank",
  "east" : __DIR__"school1",
]));
	set("no_clean_up", 0);
        set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
