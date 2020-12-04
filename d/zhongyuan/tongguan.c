inherit ROOM;
void create()
{
  set("short","潼关");
  set("long",@LONG
潼关是八百里关中的最后屏障。它的南北都是高山峻岭，黄河夹关而过。“
一夫当关，万夫莫开”。唐黄巢暴动时，三十万义军攻之不克，后来还是找到一
条小路绕过关口才得以通过。汹涌的黄河在此由从滚滚南下改折向东去，河对岸
是风陵渡渡口；一座浮桥横架河上，两岸上各有四尊丈高的铜牛拴住铁索。
LONG);
  set("exits",([
    "west"   : __DIR__"guandao6",
//    "northeast" : __DIR__"fengling_du",
    "southeast"   : __DIR__"hangu_guan",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

