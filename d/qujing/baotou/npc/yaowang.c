// create by snowcat 11/6/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����", ({"yao wang", "wang" }));
  set("title","��ʨ��");
  set("gender", "����");
  set("age", 40);
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_qi", 1000);
  set("max_jing", 1000);
  set("max_jing", 1000);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 70);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 40);
  set("combat_exp", 560000);
  set("combat_exp", 65600000);


  set("eff_dx",-80000);
  set("nkgain",100);
  
  setup();
  initlvl((700+random(700)),57);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baotou/obj/siming")->wield();
  
}

void die()
{
  object me = this_object();
  object where = environment();

  message_vision("ֻ��$Nˤ���ڵأ����˱��Ρ�ԭ����ֻ��ëʨ�ӣ�\n",me);
  set_name("��ëʨ��", ({"yao wang", "wang" }));
  delete("title");
  ::die();
}

void unconcious()
{
  die();
}
