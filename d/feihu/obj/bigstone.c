//大石头
//by steel
#include "ansi.h"
inherit ITEM;

void create()
{
  set_name("大石头",({"bigstone","stone"}) );
  set("unit","块");
  set("long",
     "这是一块平平整整的大石，上面好象有一个刀状的孔(hole)。\n");
 set("no_drop",1); 
  set("no_get",1); 
  set_weight(5000);
  set_max_encumbrance(30000); 
  setup();
}
int is_container()
{
   return 1;
}

void init()
{
  add_action("do_turn","turn");
}
int do_turn(string arg)
{
   object blade,evn,*ob,stone;
   stone=this_object();
   if(!arg)
   return notify_fail("你扭甚么呀，先生?\n");
   if(arg=="blade")
   {
   evn=environment();
   if(evn!=environment(this_player())) return 0;
   
   ob=all_inventory(this_object());
   if(sizeof(ob)!=1) return 0;
   blade=ob[0];
   
     if((string)blade->query("id")!="chuangwang baodao")
   return notify_fail(HIW"你的是什么破刀啊,切豆腐都不行。\n"NOR);
   
   if((int)this_player()->query("neili")<=1000)
   {
   message_vision(YEL"$N的内力不足了,恐怕转不动机关!\n"NOR,this_player());
   this_player()->set("neili",0);
   return 0;
   }
   this_player()->add("neili",-1000);
   message_vision(HIR"\n$N运足内力,大喝一声:起!!!....\n\n\n"NOR,this_player());
   write("只听轰隆隆一声巨响,巨石被挪开两尺,露出一个小洞。\n");
   if(!evn->query("exits/down")) 
   {
   evn->set("exits/down","/d/feihu/midong");            
   }
   call_out("close_midong",5);
  return 1;
  }
  else
  return notify_fail("唉，你太波恩乐!\n");
}

int close_midong()
{
  object evn,midong,stone;
  stone=this_object();
  evn=environment(stone);
  message("vision","轰隆一声响，巨石又回到了原位。\n",evn);
  evn->delete("exits/down");   
  midong=find_object("/d/feihu/midong");
 if (midong)
{
  midong->delete("exits/up");
  message("vision","头顶上发出轧轧的响声"
  "大概是出口和上了。\n",midong); 
}
  return 1;
}
