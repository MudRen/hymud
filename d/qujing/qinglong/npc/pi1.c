// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("辟寒大王", ({ "pihan dawang", "dawang" }));
  set("title", "玄英洞");   
  set("long", "一位妖怪，鼻子上长着一根角。");
  set("gender", "男性");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 1400);
  set("max_jing", 1400);
  set("max_jing", 1400);
  set("neili", 1400);
  set("max_neili", 1400);
  set("force_factor", 90);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 80);
  set("combat_exp", 640000);
  set("combat_exp", 65800000);


  set("env/wimpy", 50);
  setup();
   initlvl((800+random(800)),39);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/axe")->wield();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object prince = new ("/d/qujing/jinping/npc/fuling");
  if (ob)
  {
    ob->set_temp("obstacle/jinping_pi1_killed",1);
  prince->announce_success (ob);
  destruct (prince); 
  }
  message_vision ("\n$N扑倒在地，还原为一头犀牛。\n",me);
  message_vision ("\n天空四木禽星一闪，犀牛被一道光捉了去！\n",me);
::die();
}



void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

�