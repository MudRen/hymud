inherit ROOM;
void create()
{
  set("short","襄阳城下");
  set("long",@LONG
襄阳背靠群山，北临汉江，江北是大片齐整的农田，人口稠密。许多条小河
在田野间穿过，汇入汉江。樊城就在江北，隔江相对；西边是一条小路，通向汉
水上游；沿江而下，则可到达江陵，岳阳，真州，扬州。
LONG);
  set("exits",([
    "north"   : __DIR__"fancheng",
    "west"  : __DIR__"xiaolu2",
   "southeast"  : "/d/xiangyang/westgate2",
     ]));
   set("outdoors","zhongyuan");
  setup();
}

