 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","泮黄岭");
  set("long",@LONG
泰山多被苍松翠柏覆盖，郁郁苍苍，唯此山岩纵横，山石皆褚黄之
色，别有一番风味，更兼山石奇形怪状，饰之以黄色，与苍翠相映照，
实在别致。可能当年天帝见泰山甚美，做画记之，失手打翻了颜料，本
应为憾事，但天道盈亏，反倒加了泰山三分颜色。
LONG
  );
  set("exits",([
        "northeast" : __DIR__"diaojun",
        "north" : __DIR__"zhongxi",
        "southwest" : __DIR__"hutian",
               ]));
        set("objects", ([
                        ]) );
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}
