// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
这是一条青石大道。东面隐约可以看到长安城的城墙。北面有
座小山丘。
LONG );
        set("exits", ([
            "east" : __DIR__"xxroad1",
            "northup" : __DIR__"xxroad3",
            "westup" : "/d/qilian/bonanshan",            	
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

