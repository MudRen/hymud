// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("����ɮ", ({"shousi seng", "seng"}));
  set("gender", "����");
  set("combat_exp", 1000+random(50000));
  set("combat_exp", 50000);

  set("age", 40+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",6);
  set("max_jing",6000);
  set("max_qi",6000);
  set("max_jing",6000);
  set("max_neili",4000);
  set("max_neili",4000);
  set_skill("unarmed", 30+random(90));
  set_skill("dodge", 30+random(90));
  set_skill("parry", 30+random(90));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}


�