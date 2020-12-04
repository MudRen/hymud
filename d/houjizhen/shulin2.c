// shulin2.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "树林深处");
    set("long", @LONG
这是树林的深处，林中静悄悄的，偶尔传来野兽的嚎叫声，地面上绿
草如荫，茂密地生长着。树叶的缝隙间偶尔会有一只小鸟被惊起，四周看
不到边际。这里时常有毒蛇出没，最好不要在此久留。
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "west" : __DIR__"shulin3",
	    "northwest": __DIR__"shulin4",
	    "east" : __DIR__"shulin1",
          ]));

	set("objects",([
		__DIR__"npc/snake" : 1,
	]));

	setup();
	replace_program(ROOM);
}   