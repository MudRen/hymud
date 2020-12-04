// Room: /u/xiaozhen/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，由于地处关内外的交界处，生意到
很兴隆，大箱小箱堆了一地，各种货物应有尽有。由于老板人缘
很好，信誉卓著，小小的店铺竟成了内外货物的集散地。掌柜的
懒洋洋地躺在一只躺椅上，小伙计招呼着来往的客人。�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/seller" : 1
]));
	setup();
	replace_program(ROOM);
}
