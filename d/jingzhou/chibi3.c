// /d/jingzhou/chibi3.c
// netkill /98/9/10/


inherit ROOM;

void create()
{
        set("short",  "小路" );
        set("long", @LONG
这是一条通向江边的小路，路十分的陡，走起来得小心一点，四
周静悄悄的，只闻的鸟儿歌唱的声音。
LONG
        );
        set("outdoors", "jingzhou");

        set("exits", ([
                "northup" : __DIR__"chibi2",
		"westdown" : __DIR__"chibi4",                
        ]));

             
        setup();
        replace_program(ROOM);
} 
