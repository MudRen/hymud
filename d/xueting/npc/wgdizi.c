// dizi.c

inherit NPC;

void create()
{
	set_name("��ݵ���", ({ "wuguan dizi" }) );

	if(random(10)<7)
		set("gender", "����" );
	else
		set("gender", "Ů��" );

	set("age", 20+random(15));
	//set("class","huashan");

	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10+random(40));

	set("long", "����һ��������ݵ�����ĵ��ӡ�\n");
	create_family("�������", 5, "����");

        set("combat_exp", 400000);

        set_skill("unarmed", 120);
        set_skill("literate", 80);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	if(random(10)<7)
		carry_object("/clone/weapon/gangjian")->wield();            
	carry_object("/clone/misc/cloth")->wear();  
}
