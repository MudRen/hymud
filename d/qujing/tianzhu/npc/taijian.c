// snowcat 12 9 1997

inherit NPC;

void create()
{
  set_name("̫��", ({"tai jian", "jian"}));
  set("gender", "����");
  set("combat_exp", 40000);
  set("age", 40);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("force_factor",10);
  set("max_jing",500);
  set("max_qi",500);
  set("max_jing",500);
  set("max_neili",600);
  set("max_neili",600);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  setup();
  set_temp("no_return",1);
  carry_object("/d/qujing/tianzhu/obj/guanpao")->wear();
}

