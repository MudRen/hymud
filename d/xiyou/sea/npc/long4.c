// long1.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("����",({"ba xia","ba","xia","long","baxia","dragon"}));
  set("long","�������Ӳ��������������ã��Ѱ��µ����ӣ�ƽ���ø��ء�\n");
  set("gender", "����");
  set("age", 34);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 800);
  set("force", 1000);
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
  carry_object("/d/xiyou/sea/obj/dragonmace")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu4");
}

int accept_fight(object me)
{
  command("fear");
  command("say ����ƽ���´�ܣ�"+RANK_D->query_respect(this_player())+"���Ƿ���һ��ɣ�����");
  return 0;
}








