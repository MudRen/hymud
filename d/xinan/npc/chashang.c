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
	set_name("����", ({ "cha shang","trader"}));
    set("gender", "����" );
	set("age", 15+random(50));
	set("str", 20 + random(40) );
	set("qi",400);
	set("max_kee",400);
	set("eff_kee",400);
	set("jing",400);
	set("max_sen",400);
	set("eff_sen",400);
	
	set("long",
		"����һ��Զ��ȥ����ɹ���Ҷ�Ĳ��̣�������糾֮ɫ��\n");
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

