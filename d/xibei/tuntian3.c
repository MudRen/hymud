inherit ROOM;
void create()
{
    set("short","河套屯田");
    set("long",@LONG
接近边境，大部分的农田都是由驻防官军在闲时耕种，自种自食。越往西北
去，定居的百姓就越少，只有一队队的商旅在驿道上来往。
    西北地平线处依稀可见兰州城郭。
LONG);
    set("exits",([
        "south"   : __DIR__"junzhai1",
       "west" : "/d/lanzhou/nanmen",
    ]));
    set("outdoors","xibei");
    setup();
}

