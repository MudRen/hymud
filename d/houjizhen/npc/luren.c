// luren.c
//by dicky

inherit NPC;

void create()
{
	seteuid(getuid());
	set_name("·��", ({"lu ren",}));
	set("gender", "����");
	set("age", 20);
	set("long", "����һ����·��");
	set("attitude","peaceful");
	set("generation",0);
	set("winner","none");
	set("str",20);
	set("con",20);
	set("int",20);
	set("dex",20);

	set("max_jing",500);
	set("jing",500);
	set("qi",500);
	set("max_qi",500);
        set("max_sen",500);

	set("shen_type",1);
	set("no_clean_up",1);
	set("combat_exp",50000);
	set_skill("force",50);
	set_skill("unarmed",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	setup();
}
