// woodcutter.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("���Է�", ({ "qiao fu" }) );
        set("gender", "����" );
        set("age", 56);
        set("long", "����һλ��ͷ�׷������Է�������������ͨͨ��\n");

	set("combat_exp", 5000);

	set("str", 30);

	set("inquiry",([
	"����֥" : "���Ͼͳ�����֥������һ����϶��С�����򼡻��˭Ҳ���Ҳɣ�\n",
	"��֥" : "���Ͼͳ�����֥������һ����϶��С�����򼡻��˭Ҳ���Ҳɣ�\n",
	"���" : (: ask_me :),
	"�����" : (: ask_me :),
]));

	set("chat_chance", 15);
        set("chat_msg", ({
		"���Է�˵����ǰ��������һֻ����򼣬�����ˣ�\n",
		"���Է�˵����ǰ�����и������С���ӱ���򼶾���ˡ�\n",
	}) );

        setup();
	carry_object(__DIR__"obj/lumber_axe")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	if(who->query("class") == "shaolin"
	&& who->query("quest/shaolin_quest/name") == "����֥"
	&& !who->query("quest/shaolin_quest/asked"))
	{
		who->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
			"��˵��ͬ�����Ű������һ�֡��ٶ��须ר���ܿ�����򼶾��") );
		who->set("quest/shaolin_quest/asked",1);
	}
	return "�Ƕ����Ķ�������������Ҫ�Ǳ�ҧ���Ǿ�����޽���Ҳ�Ȳ����㡣
\t������˵��ͬ�����Ű������һ�֡��ٶ��须ר���ܿ�����򼶾��";
}