// muren.c ľ��

inherit NPC;
//inherit F_CLEAN_UP;

void create()
{
	set_name("ľ��", ({ "mu ren", "mu", "wood man", "wood" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "һ�������õı���ľ�ˣ��������ɣ���ͬ����һ�㡣\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("max_gin", 100);
	set("max_force", 300);
	set("jiali", 10);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}

