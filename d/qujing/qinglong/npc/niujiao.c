// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("ţ�Ǵ���", ({ "niujiao dawang", "dawang" }));
  set("long", "һλ���֣������ϳ���һ���ǡ�");
  set("gender", "����");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 1400);
  set("max_jing", 1400);
  set("max_jing", 1400);
  set("neili", 1400);
  set("max_neili", 1400);
  set("force_factor", 10);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 80);
  set("combat_exp", 1540000);
  set("combat_exp", 551500000);


  setup();
   initlvl((800+random(800)),0);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N�˵��ڵأ���ԭΪһͷϬţ��\n",me);
::die();
}

