
// mother.c

inherit NPC;

void create()
{
	set_name("�ĸ", ({ "mother" }) );
	set("gender", "Ů��" );
	set("age", 49);
	set("str", 10);
	set("per", 26);
	set("long", @LONG
    �ĸ�Ǹ�Ũױ��Ĩ������Ů�ӣ����΢�֣�ȫ��������ⱦ����
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	set_skill("unarmed", 100);
	set_skill("parry", 50);

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"�ĸ˵�����㵱������ʲô�ط�����������ɧ�ţ�\n",
	}) );
	set("inquiry", ([
		"����Ժ": "��ѽ�������������ﰡ����������",
	]) );

	setup();
	
        carry_object("/clone/misc/cloth")->wear();

}

