
// trainee.c

inherit NPC;

void create()
{
	set_name("�̹�", ({ "smoker" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "�㿴��һλ��ĸߴ�ĺ��ӡ�\n");
	set("combat_exp", 100);
        set("dodge",10);
        set("unarmed",10);	
        setup();
	carry_object("/clone/misc/cloth")->wear();
}
