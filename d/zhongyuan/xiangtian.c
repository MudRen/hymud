inherit ROOM;
void create()
{
  set("short","乡田");
  set("long",@LONG
这里是长安城东郊。四周都是整齐的田陇，田间散着间低矮的茅屋。远处有
一个小村庄，几缕炊烟缓缓地飘散在空中。
LONG);
  set("exits",([
    "northwest"   : __DIR__"beijiao",
    "southwest"   : __DIR__"zhongnan_shan",
  ]));
   set("outdoors","zhongyuan");
setup();
}

