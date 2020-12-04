#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
宽阔平坦的大道笔直地通向开封，道宽十余丈，路面上的黄土压得结结实实
，飞马驰过也只是轻起尘埃。道边是两排高大的垂杨柳。一队队商旅车队在大道
上首尾相连，望不到头，行人络绎不绝，谈吐服饰各异；临近开封，路上越发热
闹起来；大道两边也出现了很多市坊，集市。叫卖声不绝于耳。
LONG HIY @TEXT
    东面四十里外，开封城宏伟的外郭城墙隐隐现于地平线处。
TEXT NOR);
  set("exits",([
    "northeast" : "/d/kaifeng/yanqing",
    "west"  : __DIR__"guandao11",
    "east"  : __DIR__"yunhe0",	
  ]));
    set("outdoors","zhongyuan");
  setup();
}
