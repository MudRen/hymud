
// soldier.c

inherit NPC;

void create()
{
	set_name("�س���ʿ", ({ "soldier" }) );
	set("gender", "����" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
   ���ʿ��������װ,����ְ��,�þ�����Ŀ��ע����ÿһ����. 
LONG
);
	set("combat_exp", 5000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"����˵������Ҫ��������ȡ�֣����Ľ�������ɱ���㣡\n",
		"�������еĽ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"����˵�����㵱��Զ������Ǻ��۸�ô����\n"
	}) );

	set_skill("sword", 40);
	set_skill("parry", 20);
        set_skill("dodge", 40);
	


	setup();
	
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

