// Room: /d/5lt/caodi.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
һƬƽ���Ĳݵ�һֱ��ɽ�����죬ż����Щ�в�����Ŀ�Ĵ���С��
�ڲݴ��г�û��ʮ�����ڵ����ҡ�
LONG);
	set("exits", ([
		"south"      : __DIR__"qsroad",
		"northwest"  : __DIR__"fanshudi",
		"eastup"     : __DIR__"shanlu",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -120);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}