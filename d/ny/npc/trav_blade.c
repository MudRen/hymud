
//traveller.c
inherit NPC;

void create()
{
        set_name("�ÿ�", ({ "traveller"}));
        if(random(10)<7)
            set("gender", "����" );
        else
            set("gender", "Ů��" );
        set("age", 15+random(50));
        set("long",
                "����һλ��ѩͤ�������ÿ�.\n");
        set("chat_chance", 75);
        set("chat_msg", ({
(: random_move :)
 }));
        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 50);
	set_skill("throwing",30);
        set_skill("unarmed", 40);
        setup();
	carry_object(__DIR__"obj/throwing_knife")->wield();
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
        set("score",5-random(10));
}



