// 楚州青云路 /d/city/chuzhou/qingyun_lu.c
// by lala, 1997-12-03

inherit ROOM;

void create()
{
    set("short", "青云路");
    set("long", @LONG
青云路是楚州城东北的一条不太宽的的路，顾名思义是取平步青云的口采，
按理说在城边上的道路应该是人迹罕至，然而这里却是人来人往，熙熙攘攘，十
分的热闹。原来，这里路东是赫赫有名的上清宫，传说这里的道士算命极准，而
宫里供奉的天尊亦极是灵验，所以许多人千里迢迢的来到楚州算命上香，以问吉
凶求保佑。整日里观中香火极为鼎盛，观中的道士也春风得意。在路的西北是一
家旧书店，名叫“七瑞书屋”，有不少书生文士进进出出。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"shangqinggong",
        "northwest" : __DIR__"qiruishuwu",
        "southwest" : __DIR__"beishi",
    ]));
    set("objects", ([
        __DIR__"npc/jinxiangke" :   2 + random(3),
    ]));
    setup();
}
        