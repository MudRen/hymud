//lianglu2.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
一条坦荡的黄土官道向东西延伸,官道穿过布满灌木和石砾的平原.
向东就是兰州的西门,路上不时有西来的客商和小贩,他们因就要到达旅行的终点
而不免加快了脚步.因漫长的旅途而写满疲惫的脸上也多少露出了笑意.
不时有几匹快马从你身边急驰而过,马上的官差吆喝着,显然有紧急的公务.

LONG
        );
        set("exits", ([ 
                "east"          :       __DIR__ "lianglu1",            
                "west"          :       __DIR__ "lianglu3",
                ])
        );
//      replace_program(ROOM);
        setup();
}

