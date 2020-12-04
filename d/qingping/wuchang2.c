 inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
这是武场北端，虽然不大，可是各种设施一应俱全，最多的是梅花桩，
想必清平门下极为注重轻功及下盘功夫，另有砖石，沙包，可练硬功，地上
脚窝深陷，可见众弟子平时必是极为刻苦。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wuchang1",
])); 
   set("item_desc", ([
      "梅花桩" : "梅花桩是由五根离地四尺的木桩组成，因为形状象梅花而的名，是用来
练习轻功的。\n",
   ]));
        set("outdoors","qingping");
        set("coor/x",120);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        
} 
void init()
{
   add_action("do_lian", "lian");
} 
int do_lian(string arg)
{
   object me;
   int  s, amount, da;
  
   if(!arg || arg != "move") return 0;
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("在战斗中练习，想找死吗！\n");
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成，不能练习。\n");
   me->start_busy(2);
   s = (int)me->query_skill("move", 1);
   if( random(me->query("kar")) > 9) {
      if(s >= 100) {
         message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);
         tell_object(me, "你的轻功好象没有什么长进。\n");
         return 1;
      } 
      if(s >= 50) {
         message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);
      } else {
         message_vision("\n$N小心地跳上了梅花桩，胆战心惊地走了一圈，赶快又跳了下来。\n", me);
      }
      tell_object(me, "你的轻功好象长进了一些。\n");
      amount =  (me->query("int") + me->query("cps")) - 20;
      if(amount < 1) amount = 1;
      me->improve_skill("move", amount);
      da = 30*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("qi", da);
   } else {
      message_vision("\n$N拔身而起，潇洒地在梅花桩上走了一圈。\n", me);
      message_vision("\n$N哎呀一声从梅花桩上掉了下来。\n", me);
      da = 200*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("qi", da);
   }
   return 1;
}  
