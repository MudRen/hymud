//road11.c.驿道
//date:1997.8.26
//by dan

inherit ROOM;
void create()

{
    set("short","驿道");
    set("long",@LONG
脚下是黄土铺成的路面，整齐干净，不时有行人从身边擦肩而过. 周围建筑
较少, 只有一些供路人休息的凉棚。皇帝出外视察，军队出征都从这里经过，这
条驿道是都城和外界联系的交通要道。由于又要打仗，驿道上负责治安的马鹞
军加紧对来往客商的盘查，以防有细作混入，千万别招惹他们。从这里往北似乎
就是一品堂所在.
LONG);
   
    set("exits",([
        "north"   : __DIR__"road23",
        "east"    : __DIR__"road12",
        "west"    : __DIR__"road10",
    ]));
    set("outdoors","xingqing");
    setup();
}

