// mama.c

inherit NPC;
 
void create()
{
	set_name("�����", ({"ma ma"}));
	set("long", "����һλ������ϵ���𱡣\n");
	set("gender","Ů��");

	set("age",45);
	set("con",20);
	set("str",20);

	set("combat_exp",100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
