// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山上一望无边的绿色森林，狂风吹过，林涛怒吼，远处的兽吼
声阵阵传来。山路盘山而绕，岩崖看上去十分陡峭，路面崎岖
且极为狭窄。

LONG);

  set("exits", ([
        "westup"   : __DIR__"shanlu2",
        "eastdown"   : __DIR__"dongshan",
      ]));
  set("outdoors", "xy35");

  setup();
}



