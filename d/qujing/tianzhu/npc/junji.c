// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("������", ({"jun ji", "ji"}));
  set("gender", "����");
  set("age", 40);
  set("combat_exp", 20000);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set("max_jing",800);
  set("max_qi",800);
  set("max_jing",800);
  set("neili",800);
  set("max_neili",800);
  set("max_neili",800);
  set("force_factor",20);
  setup();
  set_temp("no_return",1);
  carry_object("/d/qujing/tianzhu/obj/guanpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}


