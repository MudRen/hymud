// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("�ϸ�", ({"lao fu","fu"}));
  set("gender", "Ů��");
  set("age", 60);
  set("combat_exp", 1000);
  set("per", 19);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("dodge", 30);
  set("max_jing",100);
  set("max_qi",100);
  set("max_jing",100);
  set("neili",100);
  set("max_neili",100);
  set("max_neili",100);
  set("force_factor",4);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
