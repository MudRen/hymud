// Room: /d/paiyun/lin4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���֣���Ҷ��ס�����⣬�������������ƺ���һ������
�Ķ���������ñ���һ����粻�ɵļӿ��˽Ų���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu9",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
