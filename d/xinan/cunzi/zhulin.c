//Writen by lnwm
//zhulin.c

inherit ROOM;

void create()
{
    set("short", "竹林");
    set("long", @LONG
茂密的一片竹海，竹子并不粗大，但个个挺拔苍翠，微风拂过时发出
沙沙的声音，引人遐思。砍竹子的山民正埋头工作着，这里的竹子因为质
地优良，所以山民们将它们砍伐下来买到山下。可以用来扎成竹排，放流
在四川盆地交错的河道之中。
LONG
    );
    set("exits", ([
        "southwest"     :    __DIR__ "lroad2",
        "northeast"     :    __DIR__ "zahuopu",	
        ]));
    set("objects", ([           
         __DIR__ "npc/kanzhu" : 1,
    ]) );
    set("woods",1);
    set("outdoors","lnwm");
    setup();
}


