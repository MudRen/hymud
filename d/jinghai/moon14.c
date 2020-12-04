// Room: /d/jinghai/moon14.c

inherit ROOM;

void create()
{
	set("short", "弟子休息室");
	set("long", @LONG
这是明月水寨的弟子们休息的地方，相较而言比营房的环境
要好的多了，虽然大家还是住在一间屋里，但这里的每个人都可
以得到一个固定床位，每张床边都有一个小小的橱柜，用于盛放
个人杂物。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moon11",
]));

	
        set("sleep_room", 1);
        set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
