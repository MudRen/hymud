// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "����",
  "�ǹ�",
  "���",
  "����",
  "���",
  "¹��",
  "���",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "����");
  set("age", 30*i);
  set("attitude", "aggressive");
  set("combat_exp", 20000*i);
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
  set("max_jing",500*i);
  set("max_qi",500*i);
  set("max_jing",500*i);
  set("neili",500*i);
  set("max_neili",600*i);
  set("max_neili",600*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  str = "/d/qujing/baotou/obj/weapon0";
  str[strlen(str)-1] = '0'+random(4);
  carry_object(str)->wield(); 
}
