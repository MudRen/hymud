// Room: /d/heifeng/lu8.c

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
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"lu9",
  "southwest" : __DIR__"lu7",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
