//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("楚江王", ({"chujiang wang", "wang", "chujiang"}));
  set("title", "阴间十王之");
  set("gender", "男性");
  set("age", 80);
  set("class", "youling");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 900);
  set("max_gin", 900);
  set("max_sen", 900);
  set("force", 1150);
  set("max_force", 1000);
  set("force_factor", 50);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 40);
  set("combat_exp", 720000);
  set("daoxing", 600000);

  
  
  create_family("阎罗地府", 1, "你好");
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}
