// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "������ݽ�����");
        set("long", @LONG
��������վ��һ�����Ľ������У�����������ɫ��ϸɰ����
������������Ŭ���ز�������������һ��ߴ�ı���������������
���ʦ������Ϣ�Ĵ�����
LONG
        );
       set("no_beg",1);
       set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"weapon_storage",
	"west"  : __DIR__"school1",
	"east"  : __DIR__"schoolhall",
]));
        set("objects", ([ /* sizeof() == 2 */
//  "/d/snow/npc/trainee" : 8,
//  "/d/snow/npc/fist_trainer" : 1,
	__DIR__"npc/wgdizi":6,
	]));
        set("outdoors", "xueting");

        create_door("west", "�������", "east", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
