// Room: /d/heifeng/midao1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
������һ���ܵ������ϸɸɾ������ɼ��������˹������ܵ�
���ϵ�ʯ�ڹ���ˮ�顣
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"midao2",
  "up" : __DIR__"maowu",
]));

	setup();
	//create_door("east", "����", "west", DOOR_CLOSED,LOCKED,__DIR__"obj/key1");
}
