
// trainee.c

inherit NPC;

void create()
{
	set_name("��ݵ���", ({ "trainee" }) );
	set("gender", "����" );
	set("age", 19);
	set("long", "�㿴��һλ��ĸߴ�ĺ��ӣ���������ز�������\n");
       set("cor",30);
       set("con",30);
       set("max_kee",250);
       set("kee",250);
	set("combat_exp", 100);
	setup();
	carry_object(__DIR__"obj/linen")->wear();
}
