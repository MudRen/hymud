// Room: /d/fengtian/fu.c

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һλ������լԺ���������ס�Ų��������ĸ���������
��Щ��Ҳ������һЩ�������������ø�լԺ�������Ǹ��ɵй�
�ľ޸���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm3",
]));

	setup();
	replace_program(ROOM);
}
