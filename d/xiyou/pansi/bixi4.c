// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "碧溪");
  set ("long", @LONG

只见香兰沿溪而生，芳草连天。溪水清绿流音潺潺。环绕着石
屋。也听见野禽声聒聒，也看见幽鹿步徐徐。真正是个仙家去
绝妙处，凡世哪里寻得到。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"shiwu",
        "east"    : __DIR__"bixi5",
      ]));
  set("outdoors", "xy27");
  setup();
}

