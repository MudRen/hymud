//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("�ع���", ({"qinguang wang", "wang", "qinguang"}));
  set("title", "����ʮ��֮");
  set("gender", "����");
  set("age", 60);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 850);
  set("max_force", 800);
  set("force_factor", 60);
  set("max_mana", 800);
  set("mana", 1000);
  set("mana_factor", 30);
  set("combat_exp", 800000);
  set("daoxing", 700000);


  create_family("���޵ظ�", 2, "���");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  //        carry_object("/d/lingtai/obj/shoe")->wear();
  //        carry_object("/d/lingtai/obj/putibang")->wield();
}
void attempt_apprentice(object ob, object me)
{
  if (((int)ob->query("combat_exp") < 50000 )) {
    command("say " + RANK_D->query_rude(ob) + "�������֮���������ͽ�ܣ�");
    return;
  }
  command("haha");
  command("say �ܺã�" + RANK_D->query_respect(ob) +
	  "���Ŭ�������ձض��гɡ�\n");
  command("recruit " + ob->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "youling");
}

�