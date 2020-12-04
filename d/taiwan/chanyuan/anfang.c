
#include <ansi.h>
inherit ROOM;

int do_flee();

void create ()
{
  set ("short",HIB"暗房"NOR);
  set ("long", @LONG
这是净念禅院的一个暗房，伸手不见不指。据说这里有许多净念禅
院的宝物，也不知是真是假。据说有很多武林高手来这里盗宝，但是最
后都是踪迹皆无。
LONG);

  set("exits", ([ 
	  "out":__DIR__"caodi2",	
         ]));
 
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   object ob;
   
   add_action("do_flee","flee");
   
   ob=previous_object();
   
   if(!ob) return;
   if(!ob->query_temp("try_bai_buju_actoin1"))
   return;
   if(ob->query_temp("link_killer"))
   return;
   call_out("do_kill",1,ob);
}

void do_kill(object ob)
{
  object killer;
  
  if(!ob)
  return;
  
  killer=new(__DIR__"npc/killer");
  killer->move(environment(ob));
  ob->add_temp_array("job_temp_killer",killer);
  ob->set_temp("link_killer",killer);
  killer->set("target_id",ob->query("id"));
  
  tell_object(ob,HIB"你突然发现一个黑影朝你扑了过来！！\n\n"NOR+
                 "如果你想逃跑，可以使用 flee。\n\n");
  killer->kill_ob(ob);
  return;
}

int do_flee()
{
   object ob,killer;
   string msg;
   
   ob=this_player();
   
   if(!ob->is_fighting())
   return notify_fail("你没有战斗，不用逃跑！");
   
   killer=ob->query_temp("link_killer");
   if(!objectp(killer))
   return 0;
   if(!ob->is_fighting(killer))
   return 0;
   
   msg="$N高声叫道：鬼啊，鬼啊！！！\n\n";
   message_vision(msg,ob);
   "/cmds/std/go.c"->do_flee(ob);
   destruct(killer);
   ob->delete_temp("try_bai_buju_actoin1");
   ob->set_temp("try_bai_buju_fail",1);
   ob->set("mud_flags/try_bai_buju_time",time());
   return 1;
}
   