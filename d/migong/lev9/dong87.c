#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
		set("short", WHT"����ʯ��"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ����¡� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong7"+(random(4)+5),
		"south" : __DIR__"dong88",
                "west" : __DIR__"dong01",
                "north" : __DIR__"dong6"+(random(8)+1),
	]));

        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
              "/clone/box/gbox" : random(2),
                ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}