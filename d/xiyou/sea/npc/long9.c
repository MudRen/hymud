// long1.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("��ͼ",({"shu tu","shu","tu","long","shutu","dragon"}));
  set("long","�������Ӳ��������������ã���ͼ�˵ھ��ӣ�ƽ���ñա�\n");
  set("gender", "����");
  set("age", 41);
  set("title", "��������֮");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 900);
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 80);
  set("max_mana", 900);
  set("mana", 900);
  set("force_factor",50);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
 
        set("nkgain", 400);

  setup();  


  carry_object("/d/xiyou/sea/obj/dragonsword")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu9");
}

int accept_fight(object me)
{
  command("fear");
  command("say ����ϲ����������ţ�������ϲ����ܡ�");
  command("say ������Ȼ" + RANK_D->query_respect(me) + "��Ȼ����У���Ҳֻ�÷����ˡ�");
  return 1;
}





