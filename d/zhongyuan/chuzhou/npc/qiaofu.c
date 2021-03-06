// 楚州樵夫 /d/city/chuzhou/npc/qiaofu.c
// by lala, 1997-12-14

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("樵夫", ({ "qiao fu", "qiao", "fu", "woodman", "axeman" }) );
    set("gender", "男性" );
    set("combat_exp", 2500);

        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    set("chat_chance", 10);
    set("chat_msg",({
        "樵夫叹气道：“谁买我的烧柴啊？”\n",}) );
    set("attitude", "friendly");
    set("env/wimpy", 70);     
    set("no_leave_chuzhou", 1);

	set("vendor_goods", ({
		__DIR__"obj/chai",
	}));    
    set( "talk_msg", ({
        "“要是学武……这儿一带好象没有什么有名的武馆。”",
        "“现在日子过得虽然紧，但是总还能过。”",
        "“据说这儿大街上的乞丐有什么丐帮的，所以大家都不敢惹。”",
        "“哎，您买点我的柴禾吧。”",
    }));
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("clone/weapon/gangdao")->wield();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}    
