// Room: /d/paiyun/lin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���֣���Ҷ��ס�����⣬�������������ƺ���һ������
�Ķ���������ñ���һ����粻�ɵļӿ��˽Ų���
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kongdi",
  "east" : __DIR__"lu3",
  "northwest" : __DIR__"lin3",
  "southeast" : __DIR__"dayuan",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
