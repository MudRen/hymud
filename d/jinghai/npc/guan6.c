// guan6.c

inherit NPC;

int ask_wuming(object who);
int ask_taohua(object who);

void create()
{
        set_name("�Ϲ���", ({ "guan shi","guan" }) );

        set("class","jinghai");
        set("title","��ȸ��");

        set("gender", "����" );
        set("age", 63);
	

        set("long", "����һλ��������ͷ�ӡ�\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "������" : (: ask_wuming :),
        "wuming" : (: ask_wuming :),
        "�һ���" : (: ask_taohua :),
        "taohua" : (: ask_taohua :),
]));
 
        set("combat_exp", 10000);
        set("str", 17);
        
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("force",10);

        setup();
 
        carry_object("/clone/misc/cloth")->wear();
carry_object(__DIR__"obj/bailing");
}

int ask_wuming(object who)
{
        object ob;
who=this_player();
        if(!who)
                return 0;


        if(who->query("class") != "jinghai")
		return 0;
	if(who->query_temp("jinghai_have_ling/bai"))
	{
		command("say �����������Ʋ����Ѿ��������ˡ�\n");
		return 1;
	}

        ob = new(__DIR__"obj/bailing");
	ob->move(this_object());
  ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/bai",1);

        command("say ��������");
        command("fear");
        command("say �ðɣ��Ҹ���������ơ���Ҫ����Ϊ֮����");
        command("give bai ling to "+who->query("id"));
        return 1;
}

int ask_taohua(object who)
{
        object ob;
who=this_player();
        if(!who)
        return 0;

        if(who->query("class") != "jinghai")
		return 0;

	if(who->query_temp("jinghai_have_ling/zhu"))
	{
		command("say �һ��������Ʋ����Ѿ��������ˡ�\n");
		return 1;
	}

        ob = new(__DIR__"obj/zhuling");
        ob->move(this_object());
        



        ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/zhu",1);

        command("say �һ����Ǹ��ط������˼����ð���");
        command("think");
        command("give zhu ling to "+who->query("id"));
        return 1;
}

