#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong89",
		"south" : __DIR__"dong01",
    "west" : __DIR__"dong3"+(random(9)+1),
    "east" : __DIR__"dong4"+(random(9)+1),                	
                	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong01",
		"west" : __DIR__"dong89",
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),
  
                	]));

if (random(2)==1)
	set("exits", ([
		"east" : __DIR__"dong01",
		"west" : __DIR__"dong89",
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),

                	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 3,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
