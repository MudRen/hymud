// Room: /open/dt/tanhuanglu2.c

inherit ROOM;

void create()
{
	set("short", "̹��·");
	set("long", @LONG
����·��������ȴȫ����ʯ�̾ͣ����ڴ�ͬȴ���Ǻ�����
·����Ҳû�м��ҵ��̣���������ȴ��ɨ��һ�ɶ�����·������
�����Ķ���һ�˳˽������������������Ĳ��Ǵ�ٹ��˾��Ǹ�
��С�㡣·������ʯ���֣�������Ѳ������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"youfujie3",
  "east" : __DIR__"xunpufang",
  "south" : __DIR__"tanhuanglu3",
  "north" : __DIR__"tanhuanglu1",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
