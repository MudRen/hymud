// create by snowcat 11/6/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����", ({"yao wang", "wang" }));
  set("title","��̫��");
  set("gender", "����");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_qi", 1300);
  set("max_jing", 1300);
  set("max_jing", 1300);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 90);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 40);
  set("combat_exp", 960000);
  set("combat_exp", 51500000);

  set_skill("unarmed", 90);


  
  setup();
  initlvl((650+random(650)),1);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
  object where = environment();
  object ob = query_temp("my_killer");

  if (where)
  {
    message("sound","\n\nֻ���ð�������߽У����������飬������Ҳ����\n",where);
    message("sound", "\n��������һ���������˽�ë��ԭ�Σ���һ�������ȥ��\n\n", 
            where);
  }
  if (ob)
    ob->set_temp("obstacle/zhuzi_killed",1);

  destruct (this_object());
}

void unconcious()
{
  die();
}
