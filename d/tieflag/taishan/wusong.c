 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","五松亭");
  set("long",@LONG
“且依石栏观飞瀑，再渡云桥访爵松”说得便是这儿，传五大夫松
乃始皇避雨的所在，五大夫为秦二十等爵的第九级，可见此树实在是很
显赫的了。由此俯视，云步桥的瀑布散落九天，好似天河直下，气势
不凡。
LONG
  );
  set("exits",([
        "eastup" : __DIR__"chaoyang",
        "westup" : __DIR__"jiunu",
        "southdown" : __DIR__"buyun",
               ]));
        set("objects", ([
                __DIR__"obj/tree2" : 1,
       ]) ); 
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2390);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}    
