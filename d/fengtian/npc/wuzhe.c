// wuzhe.c

inherit NPC;
 
void create()
{
	set_name("����", ({"wu zhe"}));
	set("long", "����һ�����⺷֮���Ĺ����
���������ӻ�����书��\n");
	set("gender","����");

	set("age",35);
	set("con",20);
	set("str",20);

	set_skill("unarmed",300);
	set_skill("dodge",390);
	set_skill("parry",390);
	set_skill("sword",370);


	set("combat_exp",1250000);

	setup();

	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
