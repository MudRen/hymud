inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
这是朝廷为传公文，调军队，役使数十万民工修成的大道。路上不
时有身着官服的人策马飞奔而过。行人见了，都远远避过一边。路南有
一条小路直通华山。东面就是潼关了。
LONG);
  set("exits",([
    "west"   : __DIR__"guandao5",
    "east"   : __DIR__"tongguan",
//  "south": __DIR__"xiaolu1", 
  ]));
   set("outdoors","zhongyuan");
  setup();
}

