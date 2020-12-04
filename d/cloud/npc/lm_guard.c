
// lm_guard.c

inherit NPC;

void create()
{
	set_name("������Ů", ({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("str", 18);
	set("cor", 18);
    set("max_force", 180);
    set("force", 180);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
    С����������ׯ��Ů���ӣ���˵���ε�������������͸���İ�����
�˸е��������۸���
LONG
);
	set("combat_exp", 50000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"��Ů˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
		"��Ů˵������Ҫ��������ȡ�֣�����ׯ���ı��ӣ�\n",
		"��Ů���еı���Խ��Խ�죬����Ӧ�Ӳ�Ͼ��\n",
		"��Ů˵�����㵱����ׯ��Ů�Ӻ��۸�ô����\n"
	}) );
	set("inquiry", ([
		"��ֹƼ": "ׯ��������Ҳ������������е�ô��",
		"����ׯ": "ׯ���Ը����������ҽ���",
	]) );

	set_skill("whip", 40);
	set_skill("parry", 20);
        set_skill("dodge", 40);
	

        set_skill("snowwhip", 330);

        map_skill("whip", "snowwhip");

	setup();
	
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

