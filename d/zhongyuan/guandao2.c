inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
这是朝廷为传公文，调军队，役使数十万民工修成的大道。四周是一马平川
。路上不时有身着官服的人策马飞奔而过。行人见了，都远远避过一边。南边有
一条山路，曲曲折折地通上秦岭。
LONG);
  set("exits",([
    "west"   : __DIR__"guandao1",
       "east" : __DIR__"erfang",
      "southwest" : "/d/xinan/shanlu1",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

