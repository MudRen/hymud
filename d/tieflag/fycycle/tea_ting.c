 inherit ROOM;
void create()
{
        set("short", "茶亭");
        set("long", @LONG
这是一间简易的茶亭，专门供路人歇脚用。茶亭里摆着两张桌子，几只凳子。来往
的金狮镖局的镖车到了这里往往都要听一听，让走累了的挑夫和镖师喝口水，但也
因为如此，这里也是山西劫匪们最喜欢光顾的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"road2",
]));
        set("objects", ([
        __DIR__"npc/xiaofan": 1,
                    ]));
        set("outdoors", "fengyun");
        set("coor/x",-100);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
