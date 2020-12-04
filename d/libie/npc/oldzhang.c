 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("老张头", ({ "old zhang", "zhang" }) );
        set("gender", "男性" );
        set("age", 65);
        set("str", 27);
        set("max_qi", 2000);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
一个浑身都是油腻，瘦骨嶙峋的老人。
LONG
);
        set("attitude", "peaceful"); 
        set("combat_exp", 10000);
        set("bellicosity", 0);
	set("vendor_goods", ({
                __DIR__"obj/hot_rice",
                __DIR__"obj/hot_greens",
                __DIR__"obj/hot_soup",
	}));
        
        setup(); 
        add_money("coin", 50); 
        carry_object("/clone/misc/cloth")->wear();
        
}
int accept_fight(object me)
{
        command("say 老头子哪里是您的对手？");
        return 0;
}
 
void init()
{       
        object ob; 
        ::init();
                        
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
 
void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    switch( random(5) )
    {
        case 0:
message_vision("$N不停叹着气，老泪纵横道：“你说那莲姑多好的娃儿，怎么会投井呢？”\n",this_object(),ob);
        break; 
        case 1:
message_vision("$N转身收拾碗筷，看到旁边桌上六个空空的青瓷大碗却停手不动，不禁叹息不止。”\n",this_object(),ob);
        break;
    }
}     
