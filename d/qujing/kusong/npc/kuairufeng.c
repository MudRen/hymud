//Cracked by Roath
inherit NPC;

void create()
{
  set_name("快如风", ({"kuairu feng","feng"}));
  set("gender", "男性");
  set("age", 10);
  set("title", "火云洞健将");
  set("long","一个贼眉鼠眼的小妖精。\n");
  set("combat_exp", 100000+random(3000));
  set("combat_exp", 100000);

  set("per", 15);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set("max_jing",8000);
  set("max_qi",8000);
  set("max_jing",8000);

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

�