//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("̩ɽ��", ({"taishan wang", "wang", "taishan"}));
       set("title", "����ʮ��֮");
	set("class", "youling");
       set("gender", "����");
       set("age", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 20);
       set("combat_exp", 700000);
  set("daoxing", 600000);



create_family("���޵ظ�", 1, "���");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

�
