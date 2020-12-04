// bandit_guard.c

inherit NPC;

void create()
{
	int n = random(2);
	set_name("���", ({ "bandit" }) );

	set("gender", "����");
	set("age", 33);
	set("long", "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 20000);

	set("vendetta_mark", "heifeng_tufei");

	set("bellicosity", 600);
	set("attitude", "heroism");
	set_skill("unarmed", 60);
	if(n)
		set_skill("club", 80);
	else
		set_skill("blade", 80);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	setup();
	if(n)
		carry_object(__DIR__"obj/spear")->wield();
	else
		carry_object(__DIR__"obj/blade")->wield();
	carry_object("/clone/misc/cloth")->wear();
}