// Room: /d/heifeng/lin5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ɽ����һ��Ũ�ܵ�С���֣���Ӱ��涣�ɽ�紵���Ĵ�
��ɳɳ�����죬ʹ������һ��Σ���ķ��ĸо���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaolu4",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}
