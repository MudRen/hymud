// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山路极为崎岖险恶，岩崖狼牙一般突兀而起，石壁陡峭，远处
有猛的吼声断断续续地传来，近处野林风吹草动，令人毛骨悚
然，不禁放慢了脚步。

LONG);

  set("exits", ([
        "southdown"   : __DIR__"shanlu3",
      ]));
  set("objects", ([
        __DIR__"npc/dzgg"  : 1,
      ]));
  set("outdoors", "xy34");

  setup();
}



