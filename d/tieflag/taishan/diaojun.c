 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","调军岭");
  set("long",@LONG
地势险要，两壁悬崖夹道，一夫当关，万夫莫开，过了夹道，眼前
不由得豁然开朗，一片广阔的平地呈现眼前，在这怪山奇石中有这么一
个开阔的所在，也是令人匪夷所思，故历代镇守将军，无不扼守此地，
调兵遣将，故有调军岭的美名。
LONG
  );
  set("exits",([
        "southwest" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/ghost" : 5,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",330);
        set("coor/y",2400);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}   
