// paotang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��С��", ({ "pao tang","tang","waiter" }) );
	set("title","�����ջ");
        set("gender", "����" );
        set("age", 22);
        set("long","С��������æ�ţ�����ʱҪ�ͽ����Ŀ��˴��к���\n");
        set("combat_exp", 50);
        set("attitude", "friendly");

        
	set("vendor_goods", ({
		__DIR__"obj/noodles",
		__DIR__"obj/ysd",
		"/d/city/npc/obj/baozi",
	}));
        
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
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
	}

	
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"С����Ц�����˵���������ջ���齲�ĺã���һ��Ҫ�ú�������\n"NOR);
                        break;
                case 1:
                        say( CYN"С����һ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
		}
	}
}
