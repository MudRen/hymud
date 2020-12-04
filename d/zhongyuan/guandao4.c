inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
这是朝廷为传公文，调军队，役使数十万民工修成的大道。四周皆是一马平
川。北面有一座不大的古墓，碑上模模糊糊地有“赞候萧何之墓”几个字。道路
上行人很多，不时有一队队骑马的过客飞奔而过；也偶尔有军士身背信囊，胯下
驿马跑得如一溜烟一般。
LONG);
  set("exits",([
    "west"   : __DIR__"guandao3",
    "east"   : __DIR__"guandao5",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

