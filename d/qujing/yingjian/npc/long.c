//Cracked by Roath

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("小白龙", ({"bai long","long","dragon"}));
          set("long","他本是西海龙王敖闰之子，因犯了逆仵之罪，被贬下人间。\n");
          set("gender", "男性");
          set("age", 23);
          set("per",30);        
          set("str",60);        
          set("combat_exp", 5000000);
          set("per", 30);
          set("max_qi", 4200);
          set("qi",4200);
          set("force_factor",200);
          set("max_jing", 2800);
          set("env/wimpy",60);
          set("jing",2800);
          set("combat_exp", 7000000);
          set("neili", 4000);
          set("max_neili", 2000);
          set("max_neili", 1800);
          set("neili", 1600);
          set_skill("unarmed", 220);
          set_skill("dodge", 300);
          set_skill("force", 200);
          set_skill("parry", 180);
          set_skill("hammer", 190);
          set_skill("staff", 80);


         setup();
         initlvl((200+random(100)),6);
        carry_object("/d/obj/cloth/longpao")->wear();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}
void destruct_me (object me)
{
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
        tell_room(environment(me),HIY"小白龙摇身一变，变得和小鱼苗一模一样。\n"NOR);
        tell_room(environment(me),"小白龙逃跑失败.....\n");
        this_object()->set_name("[31m小鱼苗[m",({"xiao yumiao","fish"}));
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object pusa = new ("/d/qujing/yingjian/npc/pusa");


  if (ob)
  {
    ob->set_temp("obstacle/long_killed",1);
    call_out ("pusa_appearing",1,ob);
    pusa->announce_success (ob);
  destruct (pusa); 
  }
  message_vision ("\n只见小鱼苗嘶叫一声，冲天而起，原来是条真龙。\n",ob);
::die();
}



void unconcious ()
{
  die ();
}
