// long3.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("����",({"ya zi","zi","ya","long","yazi","dragon"}));
  set("long","�������Ӳ��������������ã������˵����ӣ�ƽ����ɱ��\n");
  set("gender", "����");
  set("age", 39);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "heroic");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force", 800);
  set("max_force", 800);
  set("max_mana", 800);
  set("mana", 800);
  set("force_factor",50);
  set("mana_factor",30);
  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
 

        set("nkgain", 400);


  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/xiyou/sea/obj/dragonfork")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu3");
}

int accept_fight(object me)
{
  command("hate");
  command("grin");
  command("say �þ�ûɱ���ˣ�"+RANK_D->query_rude(me)+"����������");
  command("kill "+ me->query("id"));
  return 1;
}








