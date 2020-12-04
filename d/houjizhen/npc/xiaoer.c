// waiter.c
// by dicky


inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("inquiry", ([
                "name" : "���ҵ����ƺ���С���ͺ��ˡ�",
                "rumors" : "��˵�������ղ���һЩʧ���˵��ֻ�����֪�ǲ�����ģ�",
                "here" : "����������ѽ���͹�����Ȼ��֪����",
           ]) );
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "��С������˵���������µ�һ�����ɾ������֡���\n",
                "��С������Ҵ�ķָ�����������µ�һ��ô����Ȼ��ؤ���ˡ���\n",
		       }) );
}

void init()
{       
        object ob;
        ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
        if (base_name(environment()) != query("startroom"))
                return;

        if(interactive(ob = this_player()) && visible(ob) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment()))
                return;
        switch(random(2)) {
                case 0:
                        say("��С��Ц�����˵������λ" + RANK_D->query_respect(ob) + 
                            "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say("��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob) +
                            "����������\n");
                        break;
        }
}


int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 500) 
        {
                tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
                who->set_temp("rent_paid",1);
                return 1;

        }
        return 0;
}

void relay_emote(object me,string arg)
{
        command(arg +" " + me->query("id"));
}
