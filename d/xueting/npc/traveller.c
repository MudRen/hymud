// traveller.c

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
	set("chat_chance", 40);
//        set("chat_msg", ({(: random_move :) }));
	set("combat_exp", 600+random(400));
	set("attitude", "friendly");
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	set_skill("sword", 50);
	set_skill("force", 40);
	
	setup();
	
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 200);
	set("score",5-random(10));
}

