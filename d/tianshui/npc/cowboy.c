// cowboy.c

inherit NPC;
void create()
{
	set_name("��ͯ", ({ "mu tong", "tong" }) );
	set("gender", "����" );
	set("age", 17);
	set("long", "һ�����������ͯ�� \n");
	set("combat_exp", 7000);
	set("per", 30);
	set("attitude", "friendly");
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("unarmed",10);
	setup();
	add_money("coin", 5);
	carry_object("/clone/misc/cloth")->wear();
}