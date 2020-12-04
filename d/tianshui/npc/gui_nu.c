// gui_nu.c

inherit NPC;

void create()
{
	set_name("��ū", ({ "gui nu" }) );
	set("gender", "����" );
	set("age", 38);
	set("long",
		"���ǳ���԰�����ӵĹ�ū��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("class","jiyuan");

	set("per",20);
	set("str",30);
	set("con",30);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",5);
	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1200);
	set("max_gin",1000);
	set("max_sen",1000);

	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("unarmed",200);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_killing","kill");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(ob->query("gender") == "����") {
		if(ob->query_temp("jiyuan/order"))
			message_vision( "��ū����$N��ͷ��������λү������������֤ˬ͸��\n",ob);
		else
			message_vision( "��ū����$N��ͷ��������λү����һ�����ƺú����棿\n",ob);
	}
	if(ob->query("gender") == "Ů��" ){
		if(ob->query("age") <= 22)
			message_vision( "��ū��$N΢Ц������λ" + RANK_D->query_respect(ob)
				+ "�뵽���������̴�������������������ˡ�\n",ob);
		else
			message_vision( "��ū����$NЦ�����ò������С����������\n",ob);
	}
}
/*
int do_killing(string arg)
{
	object obj,player = this_player();
	if(objectp(obj = present(arg,environment())) && living(obj))
	{
		if(obj->query("class") == "jiyuan")
			{
			message_vision("$N����������������Ұ���ѵ�������ˣ���\n",this_object());
			set("combat_exp",2000000);
			set_skill("force",200);
			set_skill("dodge",200);
			set_skill("parry",200);
			set_skill("unarmed",200);
			set("force_factor",100);
			player->delete_temp("jiyuan");
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
			if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
				obj->delete_temp("have_full");
			return 0;
			}
		return 0;
	}
	return 0;
}

int heal_up()
{
	if( environment() && !is_fighting() )
	{
		set("combat_exp",100);
		set_skill("force",20);
		set_skill("dodge",20);
		set_skill("parry",20);
		set_skill("unarmed",20);
		set("force_factor",5);
		return 1;
	}
	return ::heal_up() + 1;
}
*/