//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  if (random(2))
  {
    set_name("������", ({ "youpo sai", "youpo", "sai" }));
    set("gender", "����");
  }
  else
  {
    set_name("������", ({ "youpo yi", "youpo", "yi" }));
    set("gender", "Ů��");
  }
  set("title", "��ɽ");
  set("age", 60);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 800);
  set("max_jing", 800);
  set("max_jing", 800);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 40);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 40);
  set("combat_exp", 200000);
  set("combat_exp", 300000);

  set_skill("spells", 60);
  set_skill("buddhism", 60);


  setup();
          initlvl((300+random(300)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}
