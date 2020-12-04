// monk1.c

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("С����", ({ "monk"}) );
        set("gender", "����" );
        set("long","һλʮ�����С���У������������������㡣\n");
        set("age", 15);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 1000);
        set("score", 1000);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("literate", 50);

	set("sell_all_day",1);
	set("vendor_goods", ({
	__DIR__"obj/xiang",
	}));    
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}
void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");   		
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(1==2)
	{
		message_vision( "С���ж�$N˵����" + RANK_D->query_respect(ob)+
			"��ʱ�����������ǳ��ĿɼΡ�\n",ob);
		return;
	}
	message_vision( "С���ж�$N˵������λ" + RANK_D->query_respect(ob)+ "Ҫ��Ҫ�����㾴��\n",ob);
}
