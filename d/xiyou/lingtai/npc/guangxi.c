// guang.c

inherit NPC;
inherit F_MASTER;
int borrow_me(object ob);
int borr_me(object ob);
void create()
{
        set_name("������", ({"guang xizi", "guang"}));
        set("title", "�����ܹ�");
        set("gender", "����" );
        set("age", 53);
        set("long", "һ����������ü��Ŀ�ĵ�ʿ��������һ��������ţ�\n");
	set("class", "toaist");
        set("combat_exp", 180000);
	set("daoxing", 250000);

        set("attitude", "friendly");
	
        set("per", 30);
	set("str", 25);
        create_family("����ɽ���Ƕ�", 2, "����");

	set("chat_msg", ({
		"������Ц��������������ɹ��ˣ�\n",
}));
	set("chat_chance", 5);
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
	carry_object("/d/xiyou/lingtai/obj/daoguan")->wear();
}
