// long2.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("����",({"bi an","bi","an","long","bian","dragon"}));
  set("long","�������Ӳ��������������ã������˵ڶ��ӣ�ƽ�����ϡ�\n");
  set("gender", "����");
  set("age", 39);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force",1000);
  set("max_force", 1000);
  set("force_factor", 80);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",40);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/xiyou/sea/obj/dragonblade")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu2");
}

int accept_fight(object me)
{
  command("consider");
  command("grin");
  command("say �����춪��һ�����飬һ��������"+RANK_D->query_rude(me)+"͵�ģ�");
  command("kill "+ me->query("id"));
  return 1;
}




