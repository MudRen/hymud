// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("��ף", ({"miao zhu", "zhu"}));
  set("gender", "����");
  set("age", 40);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 30000);
  set("combat_exp", 30000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("max_jing",200);
  set("max_qi",200);
  set("max_jing",200);
  set("max_neili",100);
  set("max_neili",100);
  set("force_factor",12);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

�