// Room: /d/jinghai/jhd22.c

inherit ROOM;

void create()
{
	set("short", "山庄侧厅");
	set("long", @LONG
这里是靖海首领们练习武功的地方，每年外驻的首脑们都要
回到这里接受武功和韬略上的进一步训练。在此之间也可以互相
交流经验，靖海派之所以能在武林中屹立数十年而不倒，很大一
部分原因就在于他们能够集思广益。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd20",
]));
        set("objects",([
]));

	setup();
	replace_program(ROOM);
}
