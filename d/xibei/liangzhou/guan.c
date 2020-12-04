//guan.c

inherit ROOM;

void create()
{
        set("short", "凉州城关");
        set("long", @LONG
站在凉州高大的城门楼之上,四下远眺,天高云淡, 你不禁感到胸怀一
阵开阔.向东眺望,是河西走廊一望无迹的平原,一条大路笔直向西而去,向
北,可见长城由西向东,蜿蜒而去,长城以北是望不到边的戈壁, 西南,是天
然屏障祈连山脉的群峰.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "down"          :       __DIR__ "dongmen",            
                "north"         :       __DIR__ "madao1",
                "south"         :       __DIR__ "madao2",
                ])
        );

        set("objects", ([

                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
//      replace_program(ROOM);
        setup();
}

