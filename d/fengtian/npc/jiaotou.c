// jiaotou.c

inherit NPC;
 
void create()
{
	set_name("��ݽ�ͷ", ({"wuguan jiaotou", "jiaotou"}));
	set("long", "��λ����ݵĽ�ͷ���ڶ��ٵ�����������\n");
	set("gender","����");

	set("age",38);
	set("con",30);
	set("str",30);
	set("max_kee",900);
	set("max_gin",750);
	set("max_sen",750);
	set("max_force",500);
	set("force",500);
	set("force_factor",10);

	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("unarmed",70);

	set("combat_exp",150000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
