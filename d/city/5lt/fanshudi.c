// Room: /d/5lt/fanshudi.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�鷬��أ���Ŀ���̣�����ʮ����ʢ��
LONG );
	set("exits", ([
		"westup"    : __DIR__"fenghuanglin",
		"southeast" : __DIR__"caodi",
		"northwest" : __DIR__"caomeidi",

	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -125);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}