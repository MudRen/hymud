 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "湖面");
        set("long", @LONG
湖很大，四周的群山在这里看来显得很小，水很清很冷，温柔地环绕在你
身体的四周，天上的白云缓慢地变换着形状，你几乎忘记了时间的存在，然而
冰冷的湖水却把你扯回到现实中，还是不要在这里待的太久。
LONG
        );
   set("objects", ([
      __DIR__"npc/frog" : 2,
   ]) );
        set("outdoors","shenshui");
        set("coor/x",200);
        set("coor/y",12300);
        set("coor/z",10);
        setup();
} 
void init()
{
   add_action("do_swim", "swim");
   remove_call_out("do_cold");
   call_out("do_cold",5, this_object()); 
} 
int do_cold(object ob) 
{
   object *inv;
   int  i, da; 
   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         message_vision("\n$N激灵灵打了一个冷战!\n", inv[i]);
         tell_object(inv[i], "还是快点离开这儿吧。\n");
         da = 50000 / (inv[i]->query("max_neili")+1);
         if(da>100) da = 50+random(50);
         if(da<10) da = 10+random(30);
         inv[i]->receive_damage("qi", da); 
      }
   }
   call_out("do_cold", 5+random(10), this_object());
} 
int do_swim()
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成。\n");
   me->start_busy(2);
   kar = (int)me->query("kar");
   k = kar - 15; if(k<1) k = 1;
   message_vision("\n$N奋力向湖边游去!", me);
   if(random(kar) < k) {
      message_vision("$N终于湿淋淋地爬到了岸上!\n\n", me);
      room = find_object(__DIR__"baishui");
      if(!objectp(room)) room = load_object(__DIR__"baishui");
      me->move(room);
      message("vision", me->name()+"湿淋淋地从湖里爬了上来。\n", environment(me), me);
   } else {
      message_vision("一股暗流又把$N冲了回来!\n", me);
   }
   return 1;
}        
