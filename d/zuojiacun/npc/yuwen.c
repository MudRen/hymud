// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("������", ({ "yu weng", "fisherman", "laoyuweng" }) );
	set("gender", "����" );
	set("age", 60+random(10));
	set("long", "����һλ������������,����������,��Ȼ�Եá�
��������������,�����������������������.\n");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/hainan/obj/shuoyi")->wear();
}
