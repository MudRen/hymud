inherit ROOM;
void create()
{
  set("short","渑池");
  set("long",@LONG
东周末年，蔺相如陪同赵惠王在此与秦昭王会晤，秦王欲加害赵王，多亏蔺
相如事先带来多名剑客相佑，方保得平安。西面就是著名的崤山，往东跨过涧水
，就是洛阳了。
LONG);
  set("exits",([
    "east"   : __DIR__"jianshui",
    "southwest"   : __DIR__"xiaoshan3",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

