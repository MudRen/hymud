//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "河边");
  set ("long", @LONG

河边尽是枯木黄土，别无他物，竟然连一只蚂蚁也没有。前方立
了一块石碑，上写着“[1;33m流沙河[m”三个大字，下面有四句真言“八
百流沙界，三千弱水深；鹅毛飘不起，芦花定底沉。”原来四周
荒芜竟是这条河所至！
LONG);
  set("exits", ([
        "westup":   "/d/qujing/village/road1",
        "eastdown"  : __DIR__"river",
        ]));
  set("outdoors", "xy7");
  setup();
}
void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        object zhou;


        message_vision(HIY "$N纵身一跃，跳进了深涧。\n" NOR, me);
        me->move(__DIR__"hedi1");
        message_vision(HIY "$N从涧上跳了下来。\n"NOR,me);
        return 1;
}
