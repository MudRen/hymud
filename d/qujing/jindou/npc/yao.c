// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "���",
  "̡��",
  "¹��",
  "�ù�",
  "����",
  "���",
  "���",
  "����",
  "����",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "����");
  set("age", 30*i);
  set("attitude", "aggressive");
  set("combat_exp", 30000*i);
  set("per", 10);
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
  carry_object("/d/qujing/jindou/obj/boots")->wear();
  carry_object("/d/qujing/jindou/obj/finger")->wear();
  carry_object("/d/qujing/jindou/obj/hands")->wear();
  carry_object("/d/qujing/jindou/obj/head")->wear();
  carry_object("/d/qujing/jindou/obj/waist")->wear();
  carry_object("/d/qujing/jindou/obj/neck")->wear();
  carry_object("/d/qujing/jindou/obj/wrists")->wear();
  str = "/d/qujing/jindou/obj/weapon0";
  str[strlen(str)-1] = '0'+random(5);
  carry_object(str)->wield();
}

�