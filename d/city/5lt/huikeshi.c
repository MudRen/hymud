// Room: /d/5lt/huikeshi.c
inherit  ROOM;

#include <room.h>


void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�����Ǵ�֧���Ļ���ҡ�����������Ŀ�Ľ��졢��״������֤�飬
���㲻���������ۡ�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"czoffice",
	]));
	set("objects",  ([
	]));
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
        create_door("north", "ľ��", "south", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
