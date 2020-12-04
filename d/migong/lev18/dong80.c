#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"不归的迷宫"NOR);
	set("long", HIM @LONG
   你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。城市大道在
这里被瓦砾堆给堵死了。这片残破萧条的景像和城门附近雄伟瑰丽的建筑
真是个极为讽刺的对比，你的直觉告诉你还是往回走才能找到出路。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(5)+3),
		"east" : __DIR__"dong81",
		"north" : __DIR__"dong7"+(random(5)+3),
		"south" : __DIR__"dong7"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(5)+4),
		"east" : __DIR__"dong7"+(random(5)+3),
		"north" : __DIR__"dong81",
		"south" : __DIR__"dong7"+(random(4)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 3,
              __DIR__"npc/lev6" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
