// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang1a.c

inherit ROOM;

void create ()
{
  set ("short", "城墙");
  set ("long", @LONG

高大的城墙，有三丈多高，由灰岩夹黄土筑成。城墙上斑斑驳驳，
看起来已经有些年代了，沿着长长的墙铺有一条结实的土石路，
可以行人走车。

LONG);

  set("exits", ([
        "south"        : __DIR__"qiang2a",
        "east"         : __DIR__"qiang1b",
      ]));

  set("outdoors", "xy15");
  setup();
}

