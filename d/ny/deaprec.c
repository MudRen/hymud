
// Room: /d/snow/deaprec.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("coor",({-20,5040,20}));
        set("short", CYN"�����"NOR);
        set("long",
"[36m�����У����������������������[2;37;0m\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"droad2",
]));
        set("item_desc",([
                        "tablet":@TEXT
!!!!!!!!!����˹��ߣ�ɱ����!!!!!!!!!!
TEXT])); 
	setup();
}
