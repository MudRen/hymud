#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ԭʼɭ��"NOR);
	set("long", GRN @LONG
����һ��ԭʼɭ�֣�ɭ�����������ڣ�ˮ���������������Ǹ��ֶ��
LONG NOR);
	set("exits", ([
		"southeast" : "/clone/quarry/dong88",
		"west" : __DIR__"dong12",
		"east" : __DIR__"dong"+(10+random(90)),
                	]));
         set("objects", ([
              __DIR__"npc/"+(random(38)+1) : 1,
             //__DIR__"npc/"+(random(38)+1) : 1,
             __DIR__"npc/2" : 1,
             __DIR__"npc/5" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
