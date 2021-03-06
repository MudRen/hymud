// 楚州燕归客店 /d/city/chuzhou/kedian.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

int do_sleep();

void create()
{
    set("short", MAG"燕归客店二楼"NOR);
    set("long", @LONG
这里是客店的二楼，清净幽雅，一间间木板隔开的小小房间里面，仅容一床
一桌一张藤椅。房间虽然小，但是很洁净，门口挂着素雅的门帘，隐约可见有不
少人在床上酣然入梦。窗外传来燕子的叽喳声，更让人觉得室内的寂静，颇有些
“鸟鸣山更幽”的味道。
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "down"      : __DIR__"kedian",
        ]));
    set("sleep_room", "inn");        
    set("objects", ([
    ]));        
    setup();
}

void init()
{
    add_action("do_sleep", "sleep");
}    

int do_sleep()
{
    object me = this_player();
    if( me->query_temp("can_sleep") )
    {
        me->delete_temp("can_sleep");
        return 0;
    }
    message_vision("$N正要上床睡觉，只听小二在楼下大叫：“客人，给了钱再睡啊！”\n"
        + "几间屋里的客人被惊醒，不满地探出头来看着$N，仿佛是看耍把戏的狗熊。\n", me);
    return 1;
}
            