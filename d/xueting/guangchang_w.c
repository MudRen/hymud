// Room: /d/xueting/square_w.c

inherit ROOM;

void create()
{
	set("short", "�㳡����");
	set("long", @LONG
������ѩͤ��㳡�����࣬�������Կ����㳡����Ĵ�������
һ��С��ջ���������߲�Զ������ջǰ��һ��������д��������
��ջ���ĸ����֣��㳡�����������ʯ�塣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"inn",
  "south" : __DIR__"guangchang_sw",
  "east" : __DIR__"guangchang.c",
]));
//	set("objects", ([ /* sizeof() == 1 */
//  "/d/snow/npc/zhangsan" : 1,
//]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
