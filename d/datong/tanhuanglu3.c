// Room: /open/dt/tanhuanglu3.c

inherit ROOM;

void create()
{
	set("short", "̹��·");
	set("long", @LONG
����·��������ȴȫ����ʯ�̾ͣ����ڴ�ͬȴ���Ǻ�����
·����Ҳû�м��ҵ��̣���������ȴ��ɨ��һ�ɶ�����·������
�����Ķ���һ�˳˽������������������Ĳ��Ǵ�ٹ��˾��Ǹ�
��С�㡣·������һ�ҹ���꣬��������Զ�ھ֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"guwandian",
  "east" : __DIR__"wyguard",
  "south" : __DIR__"lukou",
  "north" : __DIR__"tanhuanglu2",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
