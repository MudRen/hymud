inherit ROOM;
void create()
{
  set("short","小路");
  set("long",@LONG
你走在一条林间小路上，脚下是厚厚的枯枝败叶，两边都是茂密的树林，各
种各样的小鸟在枝头歌唱。一直向西是武当山，东面就是襄阳了。
LONG);
  set("exits",([
    "northwest"   : __DIR__"wudang_shan",
    "east"  : __DIR__"xiangyang",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

