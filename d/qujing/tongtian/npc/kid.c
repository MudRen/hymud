// by snowcat  11/22/1997

inherit NPC;

void create()
{
  set_name("Сͯ", ({"kid"}));
  if (random(2))
    set("gender", "����");
  else
    set("gender", "Ů��");
  set("combat_exp", random(1000));
  set("age", 3+random(5));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_jing",1000);
  set("max_qi",1000);
  set("max_jing",1000);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}


