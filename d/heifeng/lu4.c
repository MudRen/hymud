// Room: /d/heifeng/lu4.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������һ��ƽ̹��ɽ·�������죬����һ����
᫵�С·ͨ��ɽ�£�·���Ƕ��͵�ɽ�ڣ�˳��ɽ��������ȥ����
�����е�ɽ����Լ�ɼ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu5",
  "westdown" : __DIR__"lu3",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
