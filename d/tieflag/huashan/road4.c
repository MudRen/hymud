 inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "黄土路");
        set("long", @LONG
跟北面景色截然不同，这里是丘陵地带，四周充满了绿意，路旁不时有一块块
农人开垦出来的田地，向南望只见山峰秀丽挺拔一片苍翠，一条小土路绕过丘陵蜿
蜒的向南方伸展。
LONG
        );
    set("exits", ([ 
                "north" : __DIR__"road3",
                "south" : __DIR__"shanmen",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-560);
    set("coor/y",-15);
    set("coor/z",0);
//    NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
        setup(); 
}
