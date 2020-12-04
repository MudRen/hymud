// chashang.c

inherit NPC;

string *tea = ({
    "tuocha",
    "hongcha",
    "lvcha",
    "huacha",
    "moguo",
});
            


void create()
{
	set_name("茶商", ({ "cha shang","trader"}));
    set("gender", "男性" );
	set("age", 15+random(50));
	set("str", 20 + random(40) );
	set("qi",400);
	set("max_kee",400);
	set("eff_kee",400);
	set("jing",400);
	set("max_sen",400);
	set("eff_sen",400);
	
	set("long",
		"这是一名远道去大理采购茶叶的茶商，他满面风尘之色。\n");
	set("chat_chance", 6);
        set("chat_msg", ({
(: random_move :)
 }));
	set("combat_exp", 10000+random(40000));
    set("social_exp", 10000+random(40000));
	set("attitude", "friendly");

	setup();
    carry_object( "/clone/weapon/gangdao")->wield();
   	carry_object( "/clone/misc/cloth")->wear();

	set("possitive_score",100-random(400));
}

