inherit NPC;
int give_me(object ob);

void create()
{
       set_name("��˶�", ({"gui badou", "gui"}));

	set("long","���׵Ĵ���ӣ��Բ��ǹ������ƣ����һử��������\n");
       	set("gender", "����");
       	set("age", 56);
        set("title", "��ʦ");
        set("per", 10);
        set("max_kee", 1000);
        set("max_sen",700);
       	set("attitude", "peaceful");
       	set_skill("unarmed",100);
       	set_skill("dodge",100);
        set_skill("parry", 100);
       	set_skill("literate",100);
	set_skill("force", 100);
	set_skill("spells", 100);
        set("combat_exp", 200000);
  set("daoxing", 500000);

	set("force", 400);
	set("force_factor",20);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("mana_factor", 20);


        setup();
add_money("silver", 60);
       carry_object("/clone/misc/cloth")->wear();

}

