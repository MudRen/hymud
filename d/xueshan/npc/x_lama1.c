
inherit NPC;


void create()
{
set_name("С����",({
		"xiao lama",
		"xiao",
		"lama",
	}));
	set("long",
"����ѩɽ�µ�С����,���Ϲ��������Ц��\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 500);
	set("score", 100);
create_family("ѩɽ��", 4, "����");

	set_skill("force", 215);
	set_skill("dodge", 215);
	set_skill("unarmed", 215);
	set_skill("parry", 215);


	setup();
	carry_object("/clone/misc/cloth")->wear();

}



