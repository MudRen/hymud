// Room: /d/paiyun/lin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���֣���Ҷ��ס�����⣬�������������ƺ���һ������
�Ķ���������ñ���һ����粻�ɵļӿ��˽Ų���
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"lin1",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
