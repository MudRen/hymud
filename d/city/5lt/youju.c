// Room: /d/5lt/youju.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�ʾ�");
	set  ("long",  @LONG
������һ���ʾ֡�ʱ���ƻ裬������Ա��æ��������ϵ�����׼���°ࡣ
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"sroad2",
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -160);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
