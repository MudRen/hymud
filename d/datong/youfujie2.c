// Room: /open/dt/youfujie2.c

inherit ROOM;

void create()
{
	set("short", "�Ҹ���");
	set("long", @LONG
����Ϊ������������ʱ��Ҳ����ʵ����һ���Խ����һλ
������Ϸ������뵽��һ�����⣺��Ȼ�����־������ڽ�����
�����棬����ͽ��Ҹ��ֺ��ˡ������ֺ̣ܶ���ȴλ�ڳ��е���
�ģ��Ǵ�ͬ��������ĵش���������Ұζ����������������һ
������������ķ���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"youfujie1",
  "east" : __DIR__"youfujie3",
  "south" : __DIR__"ruyidufang",
  "north" : __DIR__"yeweizhai",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
