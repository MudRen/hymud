
// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({-200,4750,10}));
	set("short", "�����ܶ���");
        set("long",
"��������վ��һ�����Ľ������У�����������ɫ��ϸɰ���������������Ŭ���ز�������\n"
"��Զ�Ǿ����������¾��������ڴˡ�\n"
);
 set("exits", ([ /* sizeof() = 2 */
    "north" : __DIR__"txgate",

]));
	set("objects", ([
  __DIR__"npc/wujiang" : 2,
		__DIR__"npc/txtrainer2": 1]) ); 
        set("outdoors", "ny");
        set("clean_up",1);


        setup();
}

