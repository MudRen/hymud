inherit ROOM;
void create()
{
        set("short","洛阳城南");
  set("long",@LONG
洛阳是当今京都，繁华异常，尚未入城，已见卖杂货的，卖花儿的，耍百戏
的，练把式的，在城门外一片吆五喝六，甚是热闹。城楼下站着几个官兵在盘查
来往过客。
LONG);
  set("exits",([
    "east"   : __DIR__"guandao7",
    "west"   : __DIR__"jianshui",
    "south"  : __DIR__"longmen",
    "northeast"  : "/d/luoyang/southgate",
  ]));
    set("outdoors","zhongyuan");
  set("valid_startroom","1");
  setup();
}

