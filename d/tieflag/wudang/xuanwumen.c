 inherit ROOM;
void create()
{
        set("short", "玄武门");
        set("long", @LONG
你拾阶而上，缓缓上行。不刻已来到玄岳门。玄岳门高十二米，
宽十二点四米。它代表着道教所信仰的“五城十二楼”，相传这个地
方是等侯和相遇神仙的场所。又为“十二重楼”穴道，故又寓意此地
是阴阳交界处，为真武山第一道神门，被称为仙界第一关。在真武山
有“进了玄岳门，性命交给神”的说法。意思是说，凡人进了这神门
仙界后，是生是死，是福是祸，就由不得自己了。所以自古来真武山
朝山进香的人进了玄岳门后都神情肃穆，不敢高声谈笑。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"road2",
                "southup" : __DIR__"rock",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-100);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}      
