// tangzi.c

inherit NPC;
 
void create()
{
	set_name("������", ({"tangzi shou",}));
	set("long", "��λ����Զ�ھֵ������֡�\n");
	set("gender","����");
	set("title","��Զ�ھ�");

	set("age",38);
	set("con",30);
	set("str",30);
	set("max_kee",900);
	set("max_gin",750);
	set("max_sen",750);

	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("unarmed",60);
	set_skill("blade",60);

	set("combat_exp",120000);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
