// x_lama.c С����

inherit NPC;

void create()
{
        set_name("С����",({
		"xiao lama",
		"xiao",
		"lama",
	}));
	set("long",
                "����ѩɽ�µ�С���һ�������������������Ų��á�\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

        set("age", 13);
        set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 500);
create_family("ѩɽ��", 4, "����");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
}
