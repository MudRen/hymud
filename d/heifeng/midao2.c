// Room: /d/heifeng/midao2.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mishi1",
  "west" : __DIR__"midao1",
  "east" : __DIR__"midao3",
]));

	setup();
	//create_door("west", "����", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/key1");
}
