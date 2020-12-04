// rewritten by snowcat on 4/12/1997
#include "cloudfog.h"

inherit NPC;
#include "/d/migong/romnpc2.c"

void create()
{
  set_name("云里雾", ({"cloud fog", "cloud"}));
  set("long", "红孩儿手下六健将，其中又是云里雾"+
              "和雾里云最受红孩儿的喜爱，洞中的群妖都受过他俩的指导。\n");
  set("gender", "男性");
  set("age", 20);
  set("attitude", "heroism");
  set("shen_type", 1);
  set("con", 30+random(5));
  set("max_qi", 500);
  set("max_jing", 500);
  set("max_jing", 500);
  set("neili", 500);
  set("max_neili", 500);
  set("force_factor", 20);
  set("max_neili", 500);
  set("neili", 500);
  set("combat_exp", 240000);
  set("combat_exp", 200000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("staff", 50);
  set_skill("spells", 30);
  set_skill("force", 50);
  create_family("翠云山芭蕉洞",3,"弟子");
  setup();
  initlvl((300+random(300)),25);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}



void init()
{
  ::init();
  set("inquiry", ([
        "princess" :   (: test_player :),
        "铁扇公主" :   (: test_player :),
        "公主"     :   (: test_player :),
      ]));
}


