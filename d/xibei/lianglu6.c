//lianglu6.c

inherit ROOM;

void create()
{
        set("short", "沙砾路");
        set("long", @LONG
你走在河西走廊宽敞的驿道上，向西就是凉州，自古河西的咽喉，兵家必争之地。
在西南你能看见祁连山巍峨的群山,山峰映在蔚蓝的天空下，你感到胸怀为之一宽。
虽然这里被称为走廊，但实际上是一片非常宽阔的平原，祁连山雪蜂的积雪融化后
流入这片土地，灌溉了这里的万顷良田。
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu5",            
                "northwest"     :       __DIR__ "lianglu7",
                ])
        );
//      replace_program(ROOM);
        setup();
}

