// Room: some place in 西牛贺洲
// hill.c

inherit ROOM;

void create()
{
  set ("short", "狮驼国");
  set ("long", @LONG
这座城，唤做狮驼国。狮驼王他五百年前吃了这城国王及文武官僚，满城
大小男女也尽被他吃了干净，因此上夺了他的江山，如今尽是些妖怪。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill1",
"south" : "/d/qujing/pansi/ling1",
]));

        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/xiaozuanfeng" : 1]));
        set("no_clean_up", 0);
	set("outdoors", "xy28");
        setup();
        replace_program(ROOM);
}

