// design by ���ֺ�(find) . all right reserved.

// m_boss.c

inherit NPC;

string ask_me(object who);

string *biaozi = ({
"hong_xiu",
"lian_yu",
"wan_xiang",
"xiang_yu"
});

void create()
{
	set_name("���", ({ "m_boss" }) );
	set("gender", "Ů��" );
	set("age", 35);
	set("str", 20);
	set("per", 28);
	set("long", @LONG
һλŨױ��Ĩ�İ�������������ȴ棬ȫ��������
�ⱦ����������������������ϰ����ˡ�
LONG
);
	set("combat_exp", 100);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);

	set("inquiry", ([
		"����԰": "������ǳ���԰ѽ����������Ķ��Զ��������",
		"����" : (: ask_me :),
	]) );

	setup();
	
	carry_object(__DIR__"obj/xiu_shoes")->wear();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

void init()
{	
	object who = this_player();

	::init();
	if( interactive(who) && !is_fighting() && !who->query_temp("order") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
	add_action("ask_order","order");
}

void greeting(object who)
{
	if( !who || environment(who) != environment() ) return;
	if(who->query("gender") == "����" && !who->query_temp("jiyuan/order"))
	{
		if(1==2)
			message_vision( "������$N΢Ц������������Ķ��Զ��������"+
			"��ү��������ɣ�һ�������ú�ˬˬ��\n",who);
		else
			message_vision( "������$N΢Ц������λ"+RANK_D->query_respect(who)+
			"Ҫ��Ҫ��һ�����ƣ��ҰѺ����ǽг���������\n",who);
	}
	if(who->query("gender") == "Ů��")
		message_vision( "�����ֵ�����$N˵������λ"+RANK_D->query_respect(who)+
			"���������ֵط�����ʲô��\n",who);
}

string ask_me(object who)
{
	object me = this_player();
	if(me->query("gender") == "Ů��")
		return "��Ҳ���ڻ���,���ǿ�û��С��������\n";
	else
		return "ү����Сָͷ���Ǿͷ����ˣ��ſڵ�������д�ţ�ү��ϸ������";
}

int ask_order(string arg)
{
	object mgold,me = this_player();

	if(1==2)
		return notify_fail("����������Ϣ�أ�����������������ɡ�\n");

	if(query_temp("cant_order")) return 0;
	if( me->query("gender") == "Ů��")
		return notify_fail("��Ҳ���ڻ���,���ǿ�û��С��������\n");
	if(!arg)
		return notify_fail("��Ҫ�����ֻ��ƣ�\n");
	if(arg != "putong" && arg != "yinwei" && arg != "jinwei")
		return notify_fail("��Ҫ�����ֻ��ƣ�\n");
	if(!mgold = present("gold_money", me))
		return notify_fail("ûǮ���������⣡\n");
	if(query_temp("have_full"))
		return notify_fail("¥���Ѿ����˰��ˣ�ү��һ����ɡ�\n");
	if(me->query_temp("on_rided"))
		return notify_fail("ү��ô�������ﵽ���������棬���ǵĹ����ʲôѽ��\n");

	if(arg == "putong")
	{
		if((int)mgold->query_amount() < 5)
			return notify_fail("Ǯ��������ʲô���ƣ�\n");
		command("say ллү�����˾��ǿͣ�ү����¥���ҽи�����������");
		set_temp("cant_order",1);
		mgold->set_amount((int)mgold->query_amount() - 5);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_putong",3,me);
		return 1;
	}

	else if(arg == "yinwei")
	{
		if((int)mgold->query_amount() < 10)
			return notify_fail("Ǯ��������ʲô���ƣ�\n");
		set_temp("cant_order",1);
		command("say ү���Ǵ������¥���룬�ҽм�������ú�������");
		mgold->set_amount((int)mgold->query_amount() - 10);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_yinwei",3,me);
		return 1;
	}

	else if(arg == "jinwei")
	{
		if((int)mgold->query_amount() < 20)
			return notify_fail("Ǯ��������ʲô���ƣ�\n");
		set_temp("cant_order",1);
		command("say үĪ���ǲ���������ү������¥���ҽй����Ƕ���������");
		mgold->set_amount((int)mgold->query_amount() - 20);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_jinwei",3,me);
		return 1;
	}
}

void order_putong(object me)
{
	object ji;
	if(environment(me) != environment())
		{
		if(query_temp("have_wait")) {
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}
		tell_object(environment(me),"��𱺰�ţ�"+me->name()+"��ү���϶�¥��\n");
		set_temp("have_wait",1);
		call_out("order_putong",3,me);
		}
	else {
	ji = new(__DIR__+biaozi[random(4)]);
	message_vision("\n��𱺰����"+ji->name()+"���ӿ�����\n",this_object());
	ji->move(environment());
	tell_object(environment(),ji->name()+"���˳�����\n\n");
	command("tell "+(string)me->query("id")+" ү�ú���ɣ���������������ˡ�");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}

void order_yinwei(object me)
{
	object ji_one,ji_two;
	int i;

	if(environment(me) != environment())
	{
		if(query_temp("have_wait"))
			{
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}

		tell_object(environment(me),"��𱺰�ţ�"+me->name()+"��ү���϶�¥��\n");
		set_temp("have_wait",1);
		call_out("order_yinwei",3,me);
	}

	else
	{
	i = random(4);
	ji_one = new(__DIR__+biaozi[i]);
	if(i == 3 ) i = 0;
	else i += 1;
	ji_two = new(__DIR__+biaozi[i]);
	message_vision("\n��𱺰�������������ӿ�����\n\n",this_object());

	ji_one->move(environment());
	tell_object(environment(),ji_one->name()+"���˳�����\n");
	ji_two->move(environment());
	tell_object(environment(),ji_two->name()+"���˳�����\n\n");

	command("tell "+(string)me->query("id")+" ү�ú���ɣ����ǽ�����������ˡ�");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}

void order_jinwei(object me)
{
	object ji_o,ji_t,ji_s,ji_f;

	if(environment(me) != environment())
	{
		if(query_temp("have_wait")) {
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}
		tell_object(environment(me),"��𱺰�ţ�"+me->name()+"��ү���϶�¥��\n");
		set_temp("have_wait",1);
		call_out("order_jinwei",3,me);
	}
	else
	{

	ji_o = new(__DIR__+biaozi[0]);
	ji_t = new(__DIR__+biaozi[1]);
	ji_s = new(__DIR__+biaozi[2]);
	ji_f = new(__DIR__+biaozi[3]);

	message_vision("\n��𱺰���������Ƕ������Ӳ���ү����\n\n",this_object());

	ji_o->move(environment());
	tell_object(environment(),ji_o->name()+"���˳�����\n");
	ji_t->move(environment());
	tell_object(environment(),ji_t->name()+"���˳�����\n");
	ji_s->move(environment());
	tell_object(environment(),ji_s->name()+"���˳�����\n");
	ji_f->move(environment());
	tell_object(environment(),ji_f->name()+"���˳�����\n\n");

	command("tell "+(string)me->query("id")+" ү�ú���ɣ����ǽ���ȫ�������ˡ�");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}