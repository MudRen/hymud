// cunmin.c

inherit NPC;



void create()
{
	set_name("����", ({ "cun min","min"}));
	if(random(10)<7)
	    set("gender", "����" );
	else
	    set("gender", "Ů��" );
	set("age", 15+random(50));
	set("long",
		"����һ��̫�ʹ�Ĵ���\n");
	set("chat_chance", 10);
        set("chat_msg", ({
(: random_move :)
 }));
	set("combat_exp", 600+random(400));
        set("social_exp", 600+random(400));
	set("attitude", "friendly");
       
        set_temp("apply/attack",20+random(100) );
        set_temp("apply/defense",20+random(100) );
        set_temp("apply/damage",random(5) );
        set_temp("apply/armor",random(5) );
	setup();
        if( random(10) > 7 )
            carry_object(__DIR__"obj/chutou")->wield();
        	carry_object(__DIR__"obj/cloth2")->wear();
	add_money("coin", 100);
	set("score",5-random(10));
}

