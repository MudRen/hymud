inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
这是朝廷为传公文，调军队，役使数十万民工修成的大道。四周皆是一马平
川，只有南面有一座高山，那就是“周幽王烽火戏诸侯”的骊山。山脚下有一片
宫楼废墟，据说正是当年杨贵妃沐浴的华清宫。
LONG);
  set("exits",([
    "southwest"   : __DIR__"beijiao",
    "east"   : __DIR__"guandao4",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

