// Room: /d/heifeng/lu9.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һƬŨ�ܵ�С���֣���Ӱ��涣�ż��һ��ɽ�紵����Ҷ
ɳɳ���죬ʹ�˲�������������Ũ�ܵ���ľ����Լ��һ�����ϵ�
С��������Ĳ�֪ͨ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lu8",
  "northup" : __DIR__"lu10",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
