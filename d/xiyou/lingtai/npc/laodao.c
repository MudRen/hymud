// worker.c

inherit NPC;

void create()
{
        set_name("�ϵ�ʿ", ({"laodao"}));
        set("gender", "����" );
        set("age", 73);
        set("long", "һλ�ϵ�ʿ��üë�ͺ��Ӷ����ˣ�\n");
        set("combat_exp", 20000);
	set("daoxing", 50000);

        set("attitude", "peaceful");
        set_skill("unarmed", 30);
   
        set("max_force", 300);
        set("force_factor", 2);
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
	carry_object("/d/obj/book/stickbook");
}

