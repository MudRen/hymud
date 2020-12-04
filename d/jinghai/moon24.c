// Room: /d/jinghai/moon24.c

inherit ROOM;

void create()
{
	set("short", "帆船甲板上");
	set("long", @LONG
强劲的海风吹得帆船直晃，你不禁一个踉跄，差点掉到海里
去，这是一艘双桅快船，尖尖的船头，修长的船身好像一只木梭，
做工非常精细，看来这只船如果开动起来能追得上它的很少。船
身没有任何标志，似乎不是水寨里的船。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon16",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
