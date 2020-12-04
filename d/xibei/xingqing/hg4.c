
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "元昊宫");
	set("long",
"西夏皇宫，中书省，枢密院，三司等中央行政衙署均设在宫城内。整个皇宫与\n"
"元昊宫连成一片，金壁辉煌的宫殿建筑群与平民居住的低矮土屋形成鲜明对比。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hg3",


]));

        set("objects", ([
               "/kungfu/class/hu/xiaofeng" : 1,
               //"/kungfu/class/hu/en2" : 1,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
              