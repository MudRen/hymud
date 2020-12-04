// laozhe.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("��ü����������", ({ "lao zhe" }) );
        set("gender", "����");
        set("age", 67);
        set("long", "����һλ�������Ƶ����ߡ�\n");

	set("no_kill", 1);

	set("chat_chance", 2);
        set("chat_msg", ({
		"���߲��ϵ�̾��������\n",
		"���ߵ���̾���������ô�죬����ô�ͺ�����������ѽ����������ˡ�����\n",
}) );

	set("inquiry",([
	"̾��" : (: ask_me :),
	"�ǳ�" : (: ask_me :),
]));

	set("max_kee",800);
	set("max_gin",600);
	set("max_sen",600);

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob = previous_object(), master;

	if(!ob
	|| !ob->is_hs_quest_xiuxiu()
	|| !objectp(master = ob->query_my_master()))
		return;

	call_out("do_thanks",2,ob,master);
}

protected void do_thanks(object xiu, object who)
{
	object silver;

	if(!xiu
	|| (environment(xiu) != environment())
	|| !who
	|| (environment(who) != environment()) )
		return;

	who->set("quest/huashan_quest/finish", 1);
	message_vision("$N��������Ķ�$n˵�������������Ǽҵľ�������ˣ�лл������\nС�϶����е������͸������Ա���ġ�\n",this_object(),who);

	silver = new(SILVER_OB);
	silver->set_amount(15);
	silver->move(this_object());
	command(sprintf("give silver to %s",who->query("id")));
	message_vision("$N�м�����$n����һ�ۣ���������ȥ��\n",xiu,who);
	destruct(xiu);
}

string ask_me(object who)
{
	if( (who->query("class") != "huashan")
	|| (who->query("quest/huashan_quest/name") != "����չ���ܵ��ټ�") )
		return "˵��Ҳû�á���������������";

	if(who->query("quest/huashan_quest/asked_zhang"))
		return "���Ǻ���˵�����ﲻ��æ�����˰ɣ�������������ѽ����������";

	who->set("quest/huashan_quest/asked_zhang",1);
	who->add("quest/huashan_quest/hint","\n      ��Ӧ��ͬ���ġ����ߡ�ȥ����������Ѱ\n     ��չ���ܡ������ѣ���ȡ����㡻��\n");

	return "������������һ����å����һ���ˣ�˵��˵���Ǽ���Ů��
�ò�����Ҫ����������ѹկ���ˣ�����������Ҳû��ס��
�ҵ���Ů�����㡻�����������ˡ�������˵���ǵ�ͷĿ��
����չ���ܡ���ƽʱ�̾��ڡ�������һ������λ������
���ҵ�С��Ů�ɡ�����";
}
