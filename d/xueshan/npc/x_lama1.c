
inherit NPC;


void create()
{
set_name("小喇嘛",({
		"xiao lama",
		"xiao",
		"lama",
	}));
	set("long",
"这是雪山寺的小喇嘛,脸上挂着天真的笑容\n"
	);


	set("gender", "男性");
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
create_family("雪山寺", 4, "弟子");

	set_skill("force", 215);
	set_skill("dodge", 215);
	set_skill("unarmed", 215);
	set_skill("parry", 215);


	setup();
	carry_object("/clone/misc/cloth")->wear();

}



