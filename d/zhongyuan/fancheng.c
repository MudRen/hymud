inherit ROOM;
void create()
{
  set("short","樊城");
  set("long",@LONG
繁城位于汉江北岸，与襄阳城隔江而望，在汉中与江陵两地间经商的货船在
江上川流不息，载着满舱的粮米，布帛，瓷器，药材等货物匆匆驶过。北面是一
片肥沃的农田，屋舍林立，炊烟袅袅；南面的江上有一座竹子搭成的浮桥，过了
桥就是襄阳城下。
LONG);
  set("exits",([
    "north"   : __DIR__"baihe_an",
    "south"  : __DIR__"xiangyang",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

