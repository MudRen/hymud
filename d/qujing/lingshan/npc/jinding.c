//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("�𶥴���", ({ "jinding daxian", "jinding", "daxian" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 100);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 2000);
  set("max_jing", 2000);
  set("max_jing", 2000);
  set("neili", 2000);
  set("max_neili", 2000);
  set("force_factor", 80);
  set("max_neili", 2000);
  set("neili", 2000);
  set("mana_factor", 80);
  set("combat_exp", 1000000);
  set("combat_exp", 1500000);


  setup();
          initlvl((300+random(300)),random(63));
  carry_object("/d/obj/weapon/sword/changjian")->wield();
  carry_object("/d/obj/cloth/daopao")->wear();
}

�
