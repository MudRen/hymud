
// judge_guard.c

inherit NPC;

void create()
{
	set_name("����", ({ "judge guard","guard" }) );
	set("gender", "����" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
   �������Ĵ��������̳����ĸ�ͽ. 
LONG
);
	set("combat_exp", 8000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"����˵������Ҫ��������ȡ�֣����Ĳ�ͷ����ץȥ����!\n",
		"�������еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"����˵������������������ĵط�����\n"
	}) );

	set_skill("blade", 40);
	set_skill("parry", 30);
        set_skill("dodge", 50);
	


	setup();
	
    carry_object("/clone/weapon/gangdao")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

