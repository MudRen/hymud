// yi_girl.c

inherit NPC;

void create()
{
	set_name("����Ů��", ({ "girl" }) );
	set("gender", "����" );
	set("age", 12);
	set("long", "һ�����ݵ�СŮ��������������ȴ�������ݡ�\n");
	set("per", 35);
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed", 50);
	set_skill("parry", 90);
	set_skill("dodge",90);

	setup();
	add_money("coin", 20);
	carry_object("/clone/misc/cloth")->wear();
}
