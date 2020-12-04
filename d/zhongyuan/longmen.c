inherit ROOM;
void create()
{
  set("short","龙门");
  set("long",@LONG
洛阳石窟，天下闻名。龙门山，香山夹伊河对峙，是洛阳的南面门户，山上
多凿有巨大的佛像，香火极盛，连福建四川等地的僧侣都有前来朝拜的。
    唐代大诗人白居易晚年居住在香山之上，自号“香山居士”，他死后，
就葬在这里。
LONG);
  set("exits",([
    "north"   : __DIR__"nanmen",
    "southeast"  : __DIR__"tulu1",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

