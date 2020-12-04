// chaboshi.c �販ʿ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�販ʿ", ({ "cha boshi", "boshi", "cha" }));
	set("title", "�������");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 25);
	set("combat_exp", 800);
	set("attitude", "friendly");

        set("vendor_goods", ({
        	"/d/city/npc/tea/qimen_hongcha",
        	"/d/city/npc/tea/tie_guanyin",
        	"/d/city/npc/tea/wuyi_yancha",
        	"/d/city/npc/tea/xinyang_maojian",
        	"/d/city/npc/tea/maojian",
        	"/d/city/npc/tea/yinzhen",
        	"/d/city/npc/tea/guapian",
        	"/d/city/npc/tea/maofeng",
        	"/d/city/npc/tea/longjing",
                "/d/city/npc/tea/biluo_chun",

        }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	say("�販ʿЦ���е�˵������λ" + RANK_D->query_respect(ob) + "����������ȱ��Ȳ裬�մ�ɽ�����µ�Ȫˮ��ġ�\n");
}
