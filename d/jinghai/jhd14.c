// Room: /d/jinghai/jhd14.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ������ı����⣬��ǽ��һ�ſ��ı����ܣ�������
�����˸�ʽ�����ı�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jhd10",
]));
	set("objects", ([
	__DIR__"obj/changmao"       : 2,
	__DIR__"obj/blade"       : 2,
	__DIR__"obj/sword"       : 2,
]));

	setup();
	replace_program(ROOM);
}
