// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("�帣����", ({"dao zhang", "dao"}));
  set("gender", "����");
  set("combat_exp", 50000);
  set("combat_exp", 100000);

  set("age", 40);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",10);
  set("max_jing",3000);
  set("max_qi",3000);
  set("max_jing",3000);
  set("max_neili",4000);
  set("max_neili",4000);
  set_skill("unarmed", 50+random(90));
  set_skill("dodge", 50+random(90));
  set_skill("parry", 50+random(90));
  set_skill("force", 50+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


�