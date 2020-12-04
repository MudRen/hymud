// wan.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("������", ({ "wan ming ren" }) );

	set("gender", "����" );
	

	set("age", 35);
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 100);

	set("long", "����һ��ר������ҩ�ĵ����������ʡ�\n");
	

        set("combat_exp", 800000);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("inquiry",([
	"����" : (: ask_me :),
	"ҩ��" : (: ask_me :),
	"����" : (: ask_me :),
]));

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	carry_object("/clone/misc/cloth")->wear();  
}

string ask_me(object who)
{
	object ob;

	if(  (who->query("quest/huashan_quest/name") != "ҩ��") )
		return 0;

	if(who->query("quest/huashan_quest/wan_give"))
		return "�������Ƕ��������ˣ��Ͻ�ȥ�ְɡ�";

	if(!ob = present("shui piao",who))
	{
		ob = new(__DIR__"obj/piao");
		if(!ob->move(who))
		{
			ob->move(environment());
			message_vision("$N��һ��ˮư���ڵ��ϡ�\n",this_object());
		}
		else
			message_vision("$N��$nһ��ˮư��\n",this_object(),who);
	}

	ob = new(__DIR__"obj/huafei");
	if(!ob->move(who))
	{
		ob->move(environment());
		message_vision("$N��һ�黨�ʷ��ڵ��ϡ�\n",this_object());
	}
	else
		message_vision("$N��$nһ�黨�ʡ�\n",this_object(),who);

	who->set("quest/huashan_quest/wan_give",1);

	return "�Ͻ�ȥ�ְɣ����˾��������ˡ�";
}

int accept_object(object who, object ob)
{
	if(!ob->is_yao_miao() || !ob->is_success())
		return 0;

	if(  (who->query("quest/huashan_quest/name") != "ҩ��") )
		return 0;

	who->set("quest/huashan_quest/finish",1);

	if(find_call_out("do_dest") == -1)
		call_out("do_dest",1);
	return 1;
}

protected void do_dest()
{
	object *inv = all_inventory(this_object());

	inv = filter_array(all_inventory(this_object()),(: !$1->query("equipped") :));

	if(sizeof(inv))
		foreach(object ob in inv)
			destruct(ob);
}
