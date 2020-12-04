// Room: /d/quanzhou/chating.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
        set("short", "茶亭");
        set("long", @LONG
这是一家路边的小茶亭，赶山路的人常在此处歇歇脚。亭子里
有几张桌子和几支条凳。周围是一片树林。
LONG );
        set("exits", ([
                "west" : "/d/quanzhou/qzroad4",
        ]));
        set("objects", ([
		"/d/jinyong/book8/quanzhou/npc/xiang" : 1,
		"/d/jinyong/book8/quanzhou/npc/riyuedizi" : 3,
		"/d/jinyong/book8/quanzhou/npc/taishandizi" : 3,
        ]));
        set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("xiangsay", 1, who);  
}

void xiangsay(object who)
{
	object xiang = present("xiang wentian", environment(who));
	if(xiang)
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"一起来歇歇脚，品品茶吧！\n",xiang,who);
	}
}