inherit ROOM;
void create()
{
  set("short","南门");
  set("long",@LONG
出了南阳城向南，越过白河，穿过一片肥沃的农田再往南过了汉江，就是襄
阳了，白河自城下缓缓流向南方，偶尔有渔夫在河上张网捕鱼，东面是桐柏山，
翻山过去，再过了大胜关就可抵达江淮地区。
LONG);
  set("exits",([
    "north"   : __DIR__"nanyang_jie",
    "southwest"  : __DIR__"baihe_an",
  ]));
   set("outdoors","zhongyuan");
  setup();
   replace_program(ROOM);
}

