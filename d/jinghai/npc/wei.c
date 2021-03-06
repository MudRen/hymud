// wei.c

inherit NPC;

int ask_anhao(object me);

string *anhao = ({
"你好",
"我好",
"大家好",
"早晨",
"明天",
"晚上",
"天气太冷",
"天气很热",
"中暑",
"感冒",
});

void create()
{
        set_name("魏天行", ({"wei tianxing","wei"}));
        set("long", "一位彪形大汉,贼眉鼠眼的扫视这四周。\n");
        set("gender","男性");
        set("title","朱雀堂堂副主");

	set("chat_chance",2);
        set("chat_msg",({
        "魏天行叹了口气道:我的本事哪比不上一个妇道人家!想不到却当个副的。\n"
}));

	set("no_exp_gain",1);
	

	set("inquiry",([
	"暗号" : (: ask_anhao :),
	"口令" : (: ask_anhao :),
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

	write(name()+"笑嘻嘻的说道：“想知道暗号好办，五两银子。”\n");
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
		return notify_fail(name()+"说道：“五两银子，一文也不能少。”\n");

	n = sizeof(anhao);

	passwd = sprintf("%s%s%s",anhao[random(n)],anhao[random(n)],anhao[random(n)]);

	command("nod");
	command(sprintf("tell %s 暗号就是：%s。",me->query("id"),passwd));

	me->set_temp("jinghai_wm_passwd",passwd);
	me->delete_temp("jinghai_wei_asked");

	return 1;
}
