// chi.c
// by dicky

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIW "浴仙池" NOR);
        set("long", @LONG
浴仙池是瀑布下面的一潭清水，池边不远就是危岩。浴仙池寓于一片白雾
中，有若白云深处的仙山琼池。若是云收雾敛、碧空万里、月朗中天时，便觉
万籁俱寂，清光无限，宛若身在天宫，彻体生凉。
LONG
);
        set("outdoors", "taxue");
        set("xxc", 1);
        setup();
}

void init()
{
   object me, room;
    me = this_player();
    if (!(room = find_object(__DIR__"pubu")))
          room = load_object(__DIR__"pubu");
    if(interactive(me)){ 
        tell_room(environment(me), me->name()+"扑通一声跳了进来。\n", ({ me }));
        tell_object(me, "你扑通一声跳进了池水。\n");    
        tell_room(room, "只听“扑通”一声，"+me->name()+"已经跳进了池水里。\n");    
        call_out("do_swim", 1, this_player());       
       }
    add_action("do_no", "quit");
    add_action("do_no", "dazuo");
    add_action("do_no", "practice");
    add_action("do_no", "lian");
    add_action("do_no", "respirate");
    add_action("do_no", "exercise");
    add_action("do_no", "tuna");
    add_action("do_halt", "halt");
}

int do_no()
{
        write("在这里不准许做这类事情！\n");
        return 1;
}

int do_swim(object me)
{
        if(!living(me)) return 0;        
        
        if(me->query_con() < 25){
          tell_object(me, HIB "不料池水冰冷刺骨，你猛得一颤，连忙爬出池外！\n"NOR);
          tell_room(environment(me), me->name()+"全身哆嗦，急急忙忙地又爬了上去！\n", ({ me }));
          me->move(__DIR__"pubu");
          tell_room(environment(me), me->name()+"急急忙忙地从浴仙池中跳了上来，全身发白，直打哆嗦！\n", ({ me }));
          me->start_busy(2);
          me->receive_damage("jing", 100);
          me->receive_damage("qi", 100);
         
          return 1;
          }
        tell_object(me, GRN "\n你在清凉的池水中尽情嬉戏，不过你还是担心有人在路旁走过窥探。\n"NOR);
        me->set_temp("swimming", 1);
        me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"GRN" <游水中> "NOR}));             
        me->receive_damage("qi", (int)me->query("kar") * 4 );
        call_out("do_pa", (20+random(40)-(me->query("con"))), me); 
        me->start_busy(6);      
        return 1;         
}

int do_pa(object me)
{
  if(!environment(me)->query("xxc")) return 0;
     if(!living(me)){
          message_vision("\n一阵清风吹来，将昏迷的$N推到池边。\n", me);
          me->move(__DIR__"pubu");
          me->delete_temp("swimming");
          me->delete_temp("apply/short");
          message_vision("\n一阵徐徐清风吹来，将昏迷的$N推到了池边。\n", me);
          return 1;
          }
     
     tell_object(me, HIY "\n突然一阵清风吹来，你哆嗦了一下，连忙爬出浴仙池。\n" NOR );     
     tell_room(environment(me), "一阵清风吹过，"+me->name()+"轻轻哆嗦了一下，爬上池边穿好衣服。\n", ({ me }));
     me->delete_temp("swimming");
     me->delete_temp("apply/short");
     me->move(__DIR__"pubu");
     tell_room(environment(me), me->name()+"精神抖擞地从浴仙池中爬了上来。\n", ({ me })); 
     return 1;         
}

int do_halt()
{
      object me = this_player();
      remove_call_out("do_pa");

   if (me->is_busy())
        return notify_fail("你正忙着哪！\n");
     tell_object(me, HIY "\n突然你想起了什么事，连忙爬上池边穿好衣服。\n" NOR );
     tell_room(environment(me), me->name()+"好象想起了什么似的，急忙爬上池边穿好衣服。\n", ({ me }));
     me->delete_temp("swimming");
     me->delete_temp("apply/short");
     me->move(__DIR__"pubu");
     tell_room(environment(me), me->name()+"急急忙忙地从浴仙池中爬了上来。\n", ({ me })); 
     return 1;         
}

