// Room: /d/fengtian/mu.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
���ֵֽ�ľ������һ���¿��ŵ�С�꣬������һЩ�򵥵�ľ
�ƼҾߣ�����һЩľ�Ƶ�������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll2",
]));

	setup();
	replace_program(ROOM);
}
