// Room: /d/linzhi/yg01.c

inherit ROOM;

void create()
{
	set("short", "�׹��賡");
	set("long", @LONG
��������׹��賡��Ҳ�Ǳ��������ү�ĲƲ������ڵ���ԭ
������ʪ�ȴ�����Ҳ��ǿ�ң�������ֲ�ﺬ���ߣ������˲�
��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by12",
  "east" : __DIR__"yg02",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1900);
	setup();
	replace_program(ROOM);
}
