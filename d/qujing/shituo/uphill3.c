// Room: some place in 西牛贺洲
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "狮驼岭");
  set ("long", @LONG
此山叫做八百里狮驼岭，中间有座狮驼洞，洞里有三个魔头。
狮驼岭是大鹏金翅雕的生息之地，奇珍异兽不计其数，但世人
对此却知之甚少。洞里有三个老妖，有四万八千小妖，专在那
里吃人。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"uphill4",
"southdown": __DIR__"uphill2",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/yao" : random(5)]));
        set("no_clean_up", 0);
	set("outdoors", "xy28");
        setup();
}

