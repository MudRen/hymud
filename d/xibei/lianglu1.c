//lianglu1.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
一条坦荡的黄土官道向东西延伸,从这里你就将离开中原,进入西北.
东边就是西北重镇兰州宽敞的西城楼,往西是一片苍茫的平原,大道笔直地向西.
不时有几匹快马从你身边急驰而过,马上的官差吆喝着,显然有紧急的公务.

LONG
        );
        set("exits", ([ 
                "east"          :        __DIR__"huangye2",            
                "west"          :       __DIR__ "lianglu2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

