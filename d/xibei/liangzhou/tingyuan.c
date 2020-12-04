//tingyuan.c

inherit ROOM;

void create()
{
        set("short","庭院");
        set("long", @LONG
素雅洁净的庭院,用碎石铺地, 东南和西北角各有一棵高大的古槐,古
槐枝干粗大,枝叶茂密,几乎遮住了整个院落,阳光从树叶的缝隙间洒入,在
碎石地面上留下飘乎不定的影子.两个僧人拿两只扫把,正在打扫庭院. 往
里进就是大殿,左右各有一排厢房.
LONG
        );
        
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "shanmen",
                "north"         :       __DIR__ "dadian",
                "west"          :       __DIR__ "er1",
                "east"          :       __DIR__ "er2",
                ])
        );
        set("objects",([
            __DIR__"npc/monk" : 1,
        ]) );
//      replace_program(ROOM);
        setup();
}

