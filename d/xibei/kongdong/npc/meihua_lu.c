// meihua_lu.c ÷��¹

inherit NPC;



void create()
{
	set_name("÷��¹", ({ "meihua lu", "lu" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻ�����ɰ����Ĵ��ı�������÷��¹��\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "����", "����", "ǰ��", "����" }) );
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
        say("÷��¹�·�����ʲô���ţ����������ܿ��ˡ�\n");
        this_object()->random_move();
}
*/
void die()
{
        message_vision("$N����������ҵĽ������ɵ����ϲ����ˡ�\n",
        this_object() );
	::die();
}
