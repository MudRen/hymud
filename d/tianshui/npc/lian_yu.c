// lian_yu.c

inherit NPC;

void create()
{
	set_name("����", ({ "lian yu" }) );
	// rset short ��ζ�� ji2
	set("gender", "Ů��" );
	set("age", 19);
	set("str", 25);
	set("per", 30);
	set("long", @LONG
����ʩ��ױ�������Ľ�ë�ʹ���һλ���������Ĳ����ˡ�
LONG
);
	set("class","jiyuan");
	set("combat_exp", 100);
	set("attitude", "friendly");
set("no_get",1);
	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);
set("no_get",1);
	setup();
	carry_object(__DIR__"obj/p_necklace");	
	carry_object(__DIR__"obj/hanmei_skirt")->wear();
}

void init()
{	
	object *inv;
	int i;

	::init();
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		{
		if(!inv[i]->query_temp("jiyuan/order")) continue;
		remove_call_out("greeting");
		call_out("greeting", 1, inv[i]);
		}
	add_action("do_sleep","sleep");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || !ob->query_temp("jiyuan/order")) return;
	message_vision("\n$N��$nӯӯһ����ū�����ź����ˡ�ū������(lian yu)��\n",this_object(),ob);
	message_vision("ȥū�ġ���ζ�����ɣ���ү�ú�����ū�Ĺ⾰��(accept lian yu)\n",this_object());
}

int accept_object(object who,object ob)
{
	object obj;
	if(!who->query_temp("jiyuan/shangqian") || who->query_temp("jiyuan/shangqian") != "����") return 0;
	if(!ob->query("money_id")) return 0;
	if(ob->value() < 10000)
		{
		message_vision("$N˵����ү�ٶ��ͼ����ɡ�\n",this_object());
		return 1;
		}
	if(obj = present("hong xiu",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	if(obj = present("wan xiang",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	if(obj = present("xiang yu",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	message_vision("$N���˵�˵������л$n��ү���͡�ү�������ɡ�\n",this_object(),who);
	who->set_leader(this_object());
	who->delete_temp("jiyuan");
	who->set_temp("jiyuan/sleep",this_object()->name());
		//command("say testtest");
	//command("go west");
	this_object()->move("/d/tianshui/ji2");
	who->move("/d/tianshui/ji2");
	call_out("can_sleeping",2,who);
	return 1;
}

void can_sleeping(object who)
{
	object mother;
	if( !who || environment(who) != environment() )
	{
	message_vision("$N̾�˿��������ˡ�\n",this_object());
	if(mother = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
	}
	message_vision("$N�����ߺ��������һ����\n",this_object());
	command("remove skirt");
	message_vision("$N������$n˵��ү����(sleep)�ɣ�ū�Ҷ�...�Ȳ����ˡ�\n",this_object(),who);
	return;
}

int do_sleep(string arg)
{
	object *inv,me = this_player();
	int i;
	if(!me->query_temp("jiyuan/sleep") || me->query_temp("jiyuan/sleep") != "����")
		return 0;
	message_vision("$N����ͨ�죬�ͺ�һ������$n������......\n",me,this_object());
	message_vision("$NͻȻ����һ����ѣ......\n",me);
	me->delete_temp("jiyuan");
	me->unconcious();
	command("get all");
	call_out("do_dest",1,me);
	return 1;
}

void do_dest(object me)
{
	object *inv;
	int i;
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
		{
if (inv[i]->query("money_id"))
		destruct(inv[i]);
		}
	call_out("go_out",1);
}

void go_out()
{
	object mother;
	command("wear skirt");
	message_vision("$Nһ����Ц�����˳�ȥ��\n",this_object());
	if(mother = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		mother->delete_temp("have_full");
	destruct(this_object());
}

