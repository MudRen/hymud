//Cracked by Roath
inherit NPC;
#include "/d/migong/romnpc2.c"


void create()
{
  set_name("�����", ({"jiru huo","huo"}));
  set("gender", "����");
  set("age", 10);
  set("title", "���ƶ�����");
  set("long","һ����ü���۵�С������\n");
  set("combat_exp", 100000+random(3000));
  set("combat_exp", 100000);

  set("per", 15);

  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
 

  set("max_jing",800);
  set("max_qi",800);

  set("neili", 400);
  set("max_neili", 400);
  set("force_factor", 20);
  set("neili", 400);
  set("max_neili", 400);
  set("mana_factor", 20);



  create_family("���ƶ�", 3, "��");

  setup();
     initlvl((260+random(260)),7);
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}


