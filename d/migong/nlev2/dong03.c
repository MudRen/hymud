
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
	set("short", CYN"ʯ��"NOR);
	set("long", CYN @LONG
����һ��������ʯ������Χ���Ǽ�Ӳ��ʯ�ڡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(18)+3),
		"south" : __DIR__"dong"+(random(13)+3),
                "west" : __DIR__"dong"+(random(8)+3),
                "north" : __DIR__"dong"+(random(3)+3),
	]));
          set("objects", ([
        __DIR__"npc/lev"+(random(9)+1) : 2,
              "/clone/box/gbox" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
