// Room: /d/fengtian/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ҷ�֪��������������������ĳ������𲻴�
�������Ǵ��˵㣬��˾����ô�������㿴��˾�������������﷢
Ƣ���أ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lang1",
]));

	setup();
	replace_program(ROOM);
}
