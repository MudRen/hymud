// meihua_lu.c 梅花鹿

inherit NPC;



void create()
{
	set_name("梅花鹿", ({ "meihua lu", "lu" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只美丽可爱，四处蹦蹦跳跳的梅花鹿。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "犄角", "身体", "前蹄", "后蹄" }) );
	set("verbs", ({ "hoof", "ding" }) );

	set("combat_exp", 500);

//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}
/*
void init()
{
//        object ob;
        ::init();
//        if(interactive(ob=this_player())&& !is_fighting()){
//            remove_call_out("greeting");
//	call_out("greeting",random(10),ob);
            }
}

void greeting(object ob)
{
        if(!ob||!present(ob,environment(this_object()) )||
        is_fighting() ||random(4)<2)return;
        say("梅花鹿仿佛受了什么惊吓，撒开蹄子跑开了。\n");
        this_object()->random_move();
}
*/
void die()
{
        message_vision("$N发出几声凄惨的叫声，躺到地上不动了。\n",
        this_object() );
	::die();
}
