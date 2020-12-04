inherit ROOM;
void create()
{
    set("short","秦州府");
    set("long",@LONG
秦州乃是西北地区最为富庶之地，人口稠密，农田一片接着一片，都是靠了
渭水浇灌。官府征发民工从这里直到兰州，沿河修了数不清的运河水渠，将大量
的荒地变成了良田。
    南面群山叠嶂；向北地势渐高，梯田中夹着几座高山。
LONG);
    set("exits",([
        "east"   : __DIR__"yidao2",
        "west"  : __DIR__"yidao3",
        "northeast"  : __DIR__"shanlu1",
    ]));
        set("objects", ([
                 __DIR__"npc/keshang" : 1,
                ]) );
set("outdoors","xibei");
    setup();
} 

