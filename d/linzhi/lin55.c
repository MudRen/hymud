// Room: /d/linzhi/lin55.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������֣��ɴ�һֱ������һƬ�Ű��֣����߲�Զ������
���£�������������ɽ��ĹȺ�ˣ��򶫷����߿��Ե���һ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin54",
  "northwest" : __DIR__"lin64",
  "southwest" : __DIR__"lin62",
  "southeast" : __DIR__"lin56",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
