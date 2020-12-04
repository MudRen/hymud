
// Room: /d/snow/yamen_gate.c

#include <room.h>
inherit ROOM;


void create()
{
	set("coor",({-60,4870,10}));
	set("short", "���ô���");
	set("long",
"���������Զ�����ô���,���ص��ű�վ�����������ӵ�����,���ֱ߷���һ��˶���ţƤ\n"
"��!\n"
);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/judge_guard" : 2,
]));
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yamen_yard",
    "southeast" : __DIR__"yamen_square",
]));
    set("no_fight",0);
	set("no_clean_up", 0 );
	setup();
}

