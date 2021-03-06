 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","白龙池");
  set("long",@LONG
白龙池在建岱桥北，因上有百丈崖之飞流直下，恰似白龙顺峡越
涧直泻入池而得名。有巨石若圭卧于池北，上刻“玄圭石”。每当山洪
暴发，此石则岿然自若如巨舟行激流中；而届雨霁天晴，此石又伏岩
晒背有如巨龟出池，所以此石又名石舟，俗称晒龟石。北边的三元石
上刻“白龙池”、“龙潭”等大字。此石与玄圭石上遍布题刻，顾炎武考
得宋人题名15首，后人又考得16首，今均存。

LONG
  );
  set("exits",([
         "up":__DIR__"doumu",
         "down" :__DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"npc/ding" : 1,
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}
