 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","黑龙潭");
  set("long",@LONG
在这凭轩临溪，见中溪之水自上山奔流而下，依次流入三个逐山势
而降低的小潭，水势虽不猛急，但是声色俱佳，故有“三潭叠瀑”之称
无数文人墨客留恋在此，吟下千古绝唱。
LONG
  );
  set("exits",([
         "up":__DIR__"hutian",
         "down" :__DIR__"wanxian",
        "west" : __DIR__"linghan",
        "eastup" : __DIR__"jingshi",
               ]));
        set("objects", ([
        __DIR__"npc/yaren" : 2,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}     
