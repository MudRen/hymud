// Room: /d/heifeng/lin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ɽ����һ��Ũ�ܵ�С���֣���Ӱ��涣�ɽ�紵���Ĵ�
��ɳɳ�����죬ʹ������һ��Σ���ķ��ĸо���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"corr07",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
