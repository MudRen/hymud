// wei.c

inherit NPC;

int ask_anhao(object me);

string *anhao = ({
"���",
"�Һ�",
"��Һ�",
"�糿",
"����",
"����",
"����̫��",
"��������",
"����",
"��ð",
});

void create()
{
        set_name("κ����", ({"wei tianxing","wei"}));
        set("long", "һλ���δ�,��ü���۵�ɨ�������ܡ�\n");
        set("gender","����");
        set("title","��ȸ���ø���");

	set("chat_chance",2);
        set("chat_msg",({
        "κ����̾�˿�����:�ҵı����ıȲ���һ�������˼�!�벻��ȴ�������ġ�\n"
}));

	set("no_exp_gain",1);
	

	set("inquiry",([
	"����" : (: ask_anhao :),
	"����" : (: ask_anhao :),
]));

        set("age",35);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("demon-blade",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);

        set("combat_exp",500000);

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_anhao(object me)
{
	me=this_player();
	if(!me || (me->query("class") != "jinghai"))
		return 0;

	write(name()+"Ц������˵��������֪�����źð죬�������ӡ���\n");
	me->set_temp("jinghai_wei_asked",1);
	return 1;
}

int accept_object(object me,object ob)
{
	string passwd;
	int n;

	if(!me
	|| (me->query("class") != "jinghai")
	|| !me->query_temp("jinghai_wei_asked"))
		return 0;

	if(!ob->query("money_id"))
		return 0;

	if(ob->value() < 500)
		return notify_fail(name()+"˵�������������ӣ�һ��Ҳ�����١���\n");

	n = sizeof(anhao);

	passwd = sprintf("%s%s%s",anhao[random(n)],anhao[random(n)],anhao[random(n)]);

	command("nod");
	command(sprintf("tell %s ���ž��ǣ�%s��",me->query("id"),passwd));

	me->set_temp("jinghai_wm_passwd",passwd);
	me->delete_temp("jinghai_wei_asked");

	return 1;
}
