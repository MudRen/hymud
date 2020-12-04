// Room: /open/stst/sazai/lu4.c

inherit ROOM;




void create()
{
	set("short","野羊寨库房");
        set("long", @LONG
	这儿是野羊寨的库房，满屋子的柜子和架子。柜子里、架子上乱长八糟的
放了些兵器及防具，你可以用查看一下。如果你和野羊寨是同一帮会的还可以
在这儿拿取一些东西。不过由于这些东西都是抢来的，一般都无法变卖。
LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qianting",
]));
	set("objects",([
		"clone/weapon/gangdao":1,
		"clone/weapon/gangjian":1,
		"/d/city/npc/obj/jitui":1,	
		"/d/city/npc/obj/baozi":1,	
		"/d/city/npc/obj/jiudai":1,			
		__DIR__"npc/obj/banfu":1,
		__DIR__"npc/obj/tongjia":1,
__DIR__"npc/obj/gangjia":1,
					
]));
        setup();
}

