// Room: /d/5lt/yuelanshi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ�֧���������ҡ��Դ��������Ƚ��Ķ�ý���豸������ͳ�
��������ϯ��
LONG );
	set("exits", ([
		"south" : __DIR__"chuandashi",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}