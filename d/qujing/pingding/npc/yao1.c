// created by snowcat on 4/11/1997

inherit NPC;

void create()
{
  int i = random(9)+10;
  string str;
  set_name("С��", ({"xiao yao","yao"}));
  set("gender", "����");
  set("age", 20);
  set("combat_exp", 20000*i);
  set("attitude","aggressive");
  set("per", 15);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("staff", 10*i);
  set_skill("club", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_jing",100*i);
  set("max_qi",100*i);
  set("max_jing",100*i);
  set("neili",100*i);
  set("max_neili",100*i);
  set("max_neili",100*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/pingding/obj/armor")->wear();
  str = "/d/qujing/pingding/obj/weapon0";
  str[strlen(str)-1] = '0'+random(10);
  carry_object(str)->wield();
}
�