inherit ROOM;
void create()
{
  set("short","白河岸边");
  set("long",@LONG
一条小河弯弯曲曲地向南流去，两岸都是高高的芦苇丛，向北是南阳城，向
南沿河而下就是襄阳城。路西有几间民舍，一个白布幌子上歪歪扭扭地写着一个
“酒”字。天上不时传来麻雀的“叽叽喳喳”的叫声。河上有几只渔船正在打鱼，
渔夫撒网的姿势很是好看。
LONG);
  set("exits",([
    "northeast"   : "/d/nanyang/nanmen",
    "south"  : __DIR__"fancheng",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

