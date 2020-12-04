//fuzhai_gelou.c 阁楼
//Hydra

inherit ROOM;

void create()
{
    set("short","阁楼");
    set("long", @LONG
漂亮的小阁楼，这里是张家小姐住的地方。
LONG
    );
    set("exits", ([ 
        "up"            :       __DIR__"fuzhai_gelou2",
        "south"         :       __DIR__"fuzhai_zoulang2",
    ]) );

    set("objects",([
        __DIR__"npc/yahuan"     :   1,
    ]) );
        setup();
}

int valid_leave( object me,string dir )
{
    object ob;
    if ( dir == "up" && !me->query_temp("凉州/can_enter_gelou"))
    {
        if(objectp(ob=present("ya huan",environment(me)))
         && ob->can_act() )
            return notify_fail("丫鬟拦住了你，上面是小姐的闺房，你怎么乱闯啊？\n");
        else
            return notify_fail("人家的闺房你也闯啊？\n");
    }
    return ::valid_leave(me,dir);
}
