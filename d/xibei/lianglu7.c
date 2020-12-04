//lianglu7.c

inherit ROOM;

void create()
{
        set("short", "沙砾路");
        set("long", @LONG
一条沙石铺地的官道，穿过河西走廊，路两边是农舍和望不到边的田野，农夫在辛勤
地劳作，你几乎疑心这里是富饶的江南，只是这里的天更加高远，更加蔚蓝，你的心情
似乎也好了起来。向西已经能隐隐看到凉州城巍峨的城楼，有几匹快马从你身边向西
急驰而去，奔向凉州。
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu6",            
                "west"          :       __DIR__ "lianglu8",
                ])
        );
//      replace_program(ROOM);
        setup();
}

