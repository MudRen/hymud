inherit ROOM;
void create()
{
  set("short","土路");
  set("long",@LONG
这一带正是中原腹地，地势平坦,遍地良田.但是因为北面的黄河经常泛滥，
给当地的老百姓带来了无尽的灾难。
东面是著名的中岳嵩山。
LONG);
  set("exits",([
    "northwest"   : __DIR__"longmen",
        ///"eastup" : "/d/menpai/shaolin/shanlu_xiaojing",
    "south"  : __DIR__"tulu2",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

