#include <ansi.h>

inherit NPC;

void create()
{
  set_name("Ԫ����", ({ "yuan xiansheng", "xiansheng", "yuan" }) );
  set("gender", "����");
  set("age", 50);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_qi", 200);
  set("max_jing", 200);
  set("neili", 200);
  set("max_neili", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
}

