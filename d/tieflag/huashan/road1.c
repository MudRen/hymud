 inherit ROOM;
void midnight_event();
void sunrise_event();
void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，平坦的地势让人一眼望不到边际，地面上布满了沙石
土块，一条黄土路笔直的伸向西方，路旁的地生长着一丛丛的灌木杂草，灰黑色的
叶片给你一种沉重郁闷的感觉。
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"road2",
        "southeast" : "/d/huashan/yunupath1",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-550);
    set("coor/y",-10);
    set("coor/z",0);
    //NATURE_D->add_day_event(20, 2, this_object(), (: midnight_event :)); 
        setup();
} 
