inherit ROOM;
void create()
{
  set("short","涧水北岸");
  set("long",@LONG
接近洛阳城，路上的行人愈见增多，有的看起来腰缠万贯，有的却是一副化
子打扮。不时有身着劲装的江湖豪客匆匆走过，远处一队人推着沉重的大车走来
，却是镖局的镖师正在押镖赶路。
LONG);
  set("exits",([
    "east"   : __DIR__"nanmen",
    "west"   : __DIR__"mianchi",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

