
// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({-10,-50,0}));
	set("short", "������ݽ�����");
        set("long",
"��������վ��һ�����Ľ������У�����������ɫ��ϸɰ���������������Ŭ���ز�������\n"
"������һ��ߴ�ı������������������ʦ������Ϣ�Ĵ�����\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"weapon_storage",
  "east" : __DIR__"school1",
   "west" : __DIR__"schoolhall",
]));
        set("outdoors", "ny");
        set("clean_up",1);

        setup();
        replace_program(ROOM);
}
