// xiaoer.c С��

inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
                "/d/quanzhen/npc/obj/jitui",
                "/d/quanzhen/npc/obj/jiudai",
                "/d/quanzhen/npc/obj/baozi",
        }));
        
        set("inquiry", ([
	     "���": (: ask_me :),
       	]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        mapping myfam;

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "����������⣬ЪЪ�Űɡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                	if(ob->query("jinyong/book8"))
                	{
	                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
	                                + "����������\n");
	                        break;                	
	                }
                	else
                	{
	                        say( "��С��������˵������λ" + RANK_D->query_respect(ob)
	                                + "��¥�����˴�����£���Ǹ�к����ܣ���ൣ����\n");
	                        ob->set_temp("jinyong/book8/xiaoer",1);
	                        break;
                    	}
        }
}

int ask_me()
{
	int i;

	object who = this_player();
	if(!who->query_temp("jinyong/book8/xiaoer"))
	{
		message_vision("$N��$n˵���� ʲô��ܣ� �͹�ǧ�����˵������С������⡣\n",this_object(),who);
		return 1;
	}
	else
	{
		message_vision("$N��$n˵���� ¥�����˸��Գ�����ɵ����£�������һ����ɽ�ɵĽ����������ء�\n",this_object(),who);
		message_vision("�ҿ��͹�Ҳ��������ʿ���ܷ��æȰ��һ�£�С��м�������\n",this_object());
		who->delete_temp("jinyong/book8/xiaoer");
		who->move("/p/jinyong/book8/quanzhen/jiulou2");
		return 1;
	}
}