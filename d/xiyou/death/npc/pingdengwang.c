//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("ƽ����", ({"pingdeng wang", "wang", "pingdeng"}));
  set("title", "����ʮ��֮");
  set("gender", "����");
  set("age", 70);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 900);
  set("max_gin", 600);
  set("max_sen", 600);
  set("force", 650);
  set("max_force", 1000);
  set("force_factor", 35);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 700000);
  set("daoxing", 600000);


  
  create_family("���޵ظ�", 1, "���");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

�
