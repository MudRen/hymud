// Room: /d/fengtian/midian.c

inherit ROOM;

void create()
{
	set("short", "�׵�");
	set("long", @LONG
������һ���׵꣬�ſڹ�����������д�ţ�ͯ�����ۣ��׵�
���ϰ��Ǹ���ʵ�ˣ�������ڵľ��������˲�ʩһЩʳ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd2",
]));

	setup();
	replace_program(ROOM);
}
