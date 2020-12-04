// zhou.c



inherit NPC;
inherit F_DEALER;



void create()
{
        set_name("���ϰ�", ({ "zhang boss","zhang" }) );
        set("gender", "����" );
        	set_max_encumbrance(100000000);
        set("age", 42);
        set("long",
                "�Һ�����ϳ���һ˫������С�۾���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");

        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;
	command("say ���̾������˵����ţ�����ȫ��Ӫҵ������׿������ӭ�ݹˡ�\n");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}