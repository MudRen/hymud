// Room: /d/5lt/caomeidi.c

inherit ROOM;
void create()
{
	set("short","��ݮ��");
	set("long", @LONG
������һ���ݮ�أ��ʺ�Ĳ�ݮɢ�����̲��У����˸е������
�⡣
LONG	);
	set("exits", ([
		"southeast" : __DIR__"fanshudi",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(10),
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -130);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}