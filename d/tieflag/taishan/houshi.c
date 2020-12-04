 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","后石邬");
  set("long",@LONG
这是泰山之尾，到了这里便无处可登了，地如其名，遍地怪石嶙峋
往下是南天门，临崖俯视，云海渺茫，细看石上，历代文人骚客，留诗
无数，一路苍松万壑涛，旷达清幽不由得让人豪情顿起，禁不住仰天
长啸。
LONG
  );
  set("exits",([
        "south" : __DIR__"nantian",
               ]));
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2400);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}
