//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("������", ({"chuguan wang", "wang", "chuguan"}));
  set("title", "����ʮ��֮");
  set("gender", "����");
  set("age", 60);
  set("class", "youling");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 500);
  set("force", 750);
  set("max_force", 1000);
  set("force_factor", 50);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 50);
  set("combat_exp", 700000);
  set("daoxing", 600000);

  set_skill("unarmed", 150);
 
  create_family("���޵ظ�", 1, "���");
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}
