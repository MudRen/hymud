// Room: /open/dt/hongchanglu6.c

inherit ROOM;

void create()
{
	set("short", "���·");
	set("long", @LONG
���·�������򣬼�֮���߶��ǵ��̣���ס�˴������߹�
���Ŀ�磬���Կ�������Ϊ�ྻ���������ϻ����洦�ɼ�ɳ����
����·���洦�ɼ��������������ؽֶ���һЩС�����������·
��û��ʲô��ĵ��̣�������Ա�⸮��������̹��·��������ʦ
ү��˼���ļҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu5",
  "east" : __DIR__"chensihuojia",
  "south" : __DIR__"tanhuanglu1",
  "north" : __DIR__"yuanwaifu",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
