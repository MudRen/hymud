inherit ROOM;
void create()
{
  set("short","长安北郊");
  set("long",@LONG
这里再往南就是古都长安的北门了。前朝屡以长安为都，至隋唐，长安城日
渐扩大，有上百万人居住。无奈时过境迁，唐末的纷飞战火，使这座不世之都一
日之间化为废墟，就此衰落下去。那些曾经是辉煌一时的巨大宏伟的宫殿的地方，
现在却都已变成了农田。
LONG);
  set("exits",([
    "northeast"   : __DIR__"guandao3",
    "northwest"   : __DIR__"erfang",
  "southeast" : __DIR__"xiangtian",
  "south" : "/d/city4/road6",
  ]));
  setup();
   set("outdoors","zhongyuan");
}

