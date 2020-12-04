// Room: /d/fuzhou/fzroad5.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
福建境内数不尽的山坎相连。密林幽谷相继，终日不见天光。
山中毒虫猛兽出没无常，行路艰辛。路边有一年轻汉子倚在树上
冷眼看着你。
LONG );
	set("exits", ([
		"westup"    : __DIR__"fzroad6",
		"northeast" : __DIR__"fzroad4",
		"north" : "/d/jinyong/book8/fuzhou/fzroad5",
	]));
        set("objects", ([
		"/d/qingcheng/npc/fang" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
        if ( !me->query_temp("jinyong/book8/biaoju_ask") && dir == "north" )
        	return notify_fail("里面江湖人士寻仇，你进去找死啊！\n");
        return ::valid_leave(me, dir);
}