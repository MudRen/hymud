//puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("�����", ({"biancheng wang", "wang"}));
       set("title", "����ʮ��֮");
       set("gender", "����");
	set("class", "youling");
       set("age", 50);
       set("attitude", "friendly");
       set("per", 30);
        set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 450);
       set("max_force", 400);
       set("force_factor", 40);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 20);
	set("combat_exp", 600000);
  set("daoxing", 500000);

	
create_family("���޵ظ�", 1, "���");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
}