// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"yun qing", "yun"}));
        set("gender", "����" );
        set("age", 33);
        set("long",
"����ɽ���Ƕ������������еĽܳ����\n�䲻�Ǻܴ�������ʦ��ȴ�ܿ�������\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("����ɽ���Ƕ�", 3, "����");

        set("eff_dx", 30000);
        set("nkgain", 200);

      

	set("str", 30);
        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
	carry_object("/d/xiyou/lingtai/obj/daoguanq")->wear();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}
