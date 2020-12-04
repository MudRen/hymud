// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("金鳞怪", ({ "jinlin guai", "jinglin", "guai" }));
  set("title", "通天河");   
  set("long", "一位身着金甲的妖怪。\n");
  set("gender", "男性");
  set("age", 76);
  set("attitude", "aggressive");
  set("per", 30);
  set("max_qi", 170000);
  set("max_jing", 170000);
  set("max_jing", 170000);
  set("neili", 170000);
  set("max_neili", 170000);
  set("force_factor", 10000);
  set("max_neili", 600);
  set("neili", 600);
  set("mana_factor", 20);
  set("combat_exp", 1500000);
  set("combat_exp", 29000000);

  set_skill("spells", 30);

  set_skill("dodge", 80);
  set_skill("dragonstep", 70);
  set_skill("parry", 85);
  set_skill("force", 70);

  setup();
  initlvl((400+random(400)),10);
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/hammer/bahammer")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
object chen = new ("/d/qujing/tongtian/npc/chen");
  if (ob)
  {
    ob->set_temp("obstacle/tongtian_killed",1);
  chen->announce_success (ob);
  destruct (chen); 
  }
  message_vision ("\n$N一甩尾巴，现出金鱼的原身。\n",me);
  message_vision ("\n天上怒喝一声：金鱼，归我莲花池也！\n",me);
  message_vision ("金鱼闻声，乖乖地一纵身扭着腰摇晃着头游走了。\n",me);
::die();
}

void chen_appearing (object who)
{
  


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