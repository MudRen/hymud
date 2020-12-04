// Room: /d/jinghai/jhd3.c

inherit ROOM;

void create()
{
	set("short", "镇海祠");
	set("long", @LONG
这里是一座小小的庙宇，不知道是什么年月建成的，虽然已
经很破旧了，但桌案上的香炉里依然香烟缭绕。这个庙里供的是
一尊龙神，据说附近的渔民为能够安心地出海打鱼，每次出海前
都要到这里祈祷海底的龙王能够让大海风平浪静，所以这里也叫
镇海祠。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jhd1",
  "northeast" : __DIR__"jhd4",
  "west" : __DIR__"jhd7",
  "south" : __DIR__"jhd5",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
