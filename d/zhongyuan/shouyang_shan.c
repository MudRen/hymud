inherit ROOM;
void create()
{
  set("short","首阳山");
  set("long",@LONG
传说周武王灭殷商后，孤竹国君的儿子伯夷，叔齐二人因不肯吃周朝的粮食
，就躲进首阳山上，活活饿死。至今山上还有一座石坊，纪录着当年这二人的事
迹。
LONG);
  set("exits",([
    "eastdown"   : __DIR__"zhongnan_shan",
 "westup"   : "/d/quanzhen/shanjiao",
 ]));
   set("outdoors","zhongyuan");

  setup();
}

