// Room: /d/jinghai/moon18.c

inherit ROOM;

void create()
{
	set("short", "山寨客房");
	set("long", @LONG
这里是一间简陋的小客房，明月寨有客人来访时都住在这里
。屋内摆设简单，只有木床，台案和大木[箱子]几样家设。因为
经常有人打扫，屋内非常干净整洁。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"moon8",
]));

        set("objects",([
        __DIR__"npc/guan3" : 1,
]));


	setup();
	replace_program(ROOM);
}
