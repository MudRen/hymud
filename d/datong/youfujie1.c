// Room: /open/dt/youfujie1.c

inherit ROOM;

void create()
{
	set("short", "�Ҹ���");
	set("long", @LONG
����Ϊ������������ʱ��Ҳ����ʵ����һ���Խ����һλ
������Ϸ������뵽��һ�����⣺��Ȼ�����־������ڽ�����
�����棬����ͽ��Ҹ��ֺ��ˡ������ֺ̣ܶ���ȴλ�ڳ��е���
�ģ��Ǵ�ͬ��������ĵش�����������Դ�;�¥����������
¥�����߽��Ž����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jinyangjie4",
  "east" : __DIR__"youfujie2",
  "south" : __DIR__"wanhualou",
  "north" : __DIR__"qingyuanhe",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
