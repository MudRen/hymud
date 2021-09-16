// Room: /d/jinghai/jhd28.c

inherit ROOM;

void create()
{
	set("short", "小渔村");
	set("long", @LONG
这个渔村只有十几户人家，但在靖海派还没有成立的时候他
们已经在这个岛上生存了不知多少代了，据说他们以前是住在山
里的，只是后来靖海派要把总坛设在这里，他们才在这片平静的
海滩上安了家。不过因为靖海派赶走了这一带的海盗，他们对靖
海派敬若神明，所以一点怨言也没有。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"jhd30",
  "north" : __DIR__"jhd6",
  "east" : __DIR__"jhd29",
]));
        set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
