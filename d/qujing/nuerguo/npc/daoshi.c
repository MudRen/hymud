// daoshi.c

inherit NPC;

void create()
{
  set_name("道士", ({"daoshi"}));
  set("gender", "男性" );
  set("age", 43);
  set("long", "他正懒洋洋地晒太阳。见了你显出一副爱搭不理的样子。\n");
  set("class","taoist");
  set("combat_exp", 10000);
  set("combat_exp", 20000);

  set("attitude", "peaceful");
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set("per", 15);
  set("max_qi", 300);
  set("max_jing", 200);
  set("max_jing", 300);
  set("neili", 100);
  set("max_neili", 100);
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

�