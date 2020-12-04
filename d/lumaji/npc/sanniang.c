// sanniang.c

#include <ansi.h>


inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "san niang" }) );
	set("title","�ӻ�������");
        set("gender", "Ů��" );
        set("age", 35);
        set("long","��������΢Ц�ſ����㡣\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"������˵����������կ�Ĵ����˵��ǲ����������۸�����С�ϰ��ա���\n"NOR,
		CYN"������˵������ÿ�괺���������֣����ص����Ӷ�Ҫ������\n"NOR,
		CYN"������˵�������������ﾩ�ǲ�Զ����һ��Ұζȥ��Ҳ�������١���\n"NOR,
}));

	set("vendor_goods", ({
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
		"/clone/misc/chema",
	}));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n�������ⲻ�������ĵط����Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(1==2)
	{
		
		say( (time > 480) ? CYN"��ô����죬��һ���Ǹոϵ��������������ӵ�漢�ɡ�\n"NOR
			: ( (time <= 60) ? CYN"�������������Ҫ��·�ɣ��򼸸����Ӵ���·�ϡ�\n"NOR
			: CYN"�������˸�����˵�����͹���Ҫʲô�����ⶼ���ֳɵġ�\n"NOR ) );
		return;
	}
	else
		say( CYN"������Ц�����˵�����͹����������С������ľơ�\n"NOR);
}