// Room: /d/datong/tanhuanglu1.c

inherit ROOM;

void create()
{
	set("short", "̹��·");
	set("long", @LONG
����·��������ȴȫ����ʯ�̾ͣ����ڴ�ͬȴ���Ǻ�����
·����Ҳû�м��ҵ��̣���������ȴ��ɨ��һ�ɶ�����·������
�����Ķ���һ�˳˽������������������Ĳ��Ǵ�ٹ��˾��Ǹ�
��С�㡣·������һ���鱦�꣬�����ǻ�������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhubaodian",
  "east" : __DIR__"huaandao1",
  "south" : __DIR__"tanhuanglu2",
  "north" : __DIR__"hongchanglu6",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
