//writen by lnwm
//yuanluo.c

inherit ROOM;

void create()
{
    set("short", "农家院落");
    set("long", @LONG
干干净净的农家小院，看起来女主人一定勤快能干，整个院落都撒了
水，没有一片落叶。东首是这一家自己的菜园，西边是一个厨房，厨房
的门边挂着一长串红红的干辣椒。北边就是这家的堂屋。堂屋用砖石砌
成，显然这是一家比较富裕的农户。
LONG
        );
    set("exits", ([ 
                "east"      :       __DIR__ "caiyuan",
        "south"     :       __DIR__ "chaimen",
        "north"     :       __DIR__ "tangwu",
        "west"      :       __DIR__ "chufang",
        ]));
    
    set("outdoors","lnwm");
    setup();
}



