// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("����", ({"qiao zi","zi"}));
  set("gender", "����");
  set("age", 30);
  set("combat_exp", 10000);
  set("per", 25);
  set_skill("parry", 40);
  set_skill("unarmed", 40);
  set_skill("dodge", 50);
  set("max_jing",400);
  set("max_qi",400);
  set("max_jing",400);
  set("neili",400);
  set("max_neili",400);
  set("max_neili",400);
  set("force_factor",30);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/obj/weapon/axe/tiefu")->wield();
}
