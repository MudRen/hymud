//Cracked by Roath
inherit NPC;

void create()
{
  set_name("����", ({"mahuang guai","guai"}));
  set("gender", "����");
  set("age", 40);
  set("long","һ����ͷ���Ե���������\n");
  set("combat_exp", 300000+random(3000));
  set("combat_exp", 250000);

  set("per", 15);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 120);
  set_skill("spells", 120);
  set_skill("dagger", 120);
  set("max_jing",8000);
  set("max_qi",8000);
  set("max_jing",8000);
  set("max_neili", 5000);
  set("neili", 500);
  set("force_factor", 25);
  set("max_neili", 500);
  set("neili", 500);
  set("mana_factor", 25);
  

  setup();
  carry_object("/d/qujing/kusong/obj/needle1")->wield();
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

�