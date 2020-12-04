// chunhua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_shoujuan();

void create()
{
	set_name("����", ({"chun hua", "chunhua"}));
	set("long", "����һ����ͨ��ũ��Ů�����û��м�����ɫ��\n");
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("age", 20);
	set("per", 22);
	set("str", 28);
	set("con", 23);
	set("dex", 28);

	set("combat_exp", 2000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
        set("inquiry", ([
		"�־�":(: ask_shoujuan :),
        ]));

	setup();

        carry_object(__DIR__"obj/skirt")->wear();
}

void init()
	{
        add_action("do_decide", "decide");
	}

int ask_shoujuan()
{
    object ob;
    ob=this_player();

    if(ob->query("gender") !="����")
    { 
	command("say ��λ"+RANK_D->query_respect(ob)+"����Ҳ�Ǹ�Ů�ԣ��ѵ���֪���־");
	return 1; 
    }

    if (  present("nvren shoujuan", this_player()) )
    {
	if (ob->query_temp("ganjiang/shoujuan") || ob->query_temp("ganjiang/decide") )
	{
	command("love "+ob->query("id"));
	command("say ��Ҳ֪��֪��ū�ҵ�����ѽ����Ȼ"+RANK_D->query_respect(ob)+"Զ������������ū
��Ϊ�㾡���һ����������������(decide)�ˣ������ū��!\n");
	command("touch "+ob->query("id")+"\n");
	ob->delete_temp("ganjiang/shoujuan",1);
	ob->set_temp("ganjiang/decide",1);
	return 1;
	} 
	else
	{
	command("say ��������ô����Ů�˵��־�ǲ�������ȥ͵������");
	command("xixi");
	return 1;
	}
    }
    else
    {
    command("say "+RANK_D->query_respect(ob)+"������ʲô�־꣬��������ū��˵˵���\n");
    command("love "+ob->query("id"));
    }
}

int do_decide(string arg)
{
	object ob;
	object ob1;
    	ob=this_player();

        if( !this_player()->query_temp("ganjiang/decide") )
                return 0;

	if (!arg)
	{
	command("?");
	command("say �������ʲôѽ����ֻ��Ҫ�ش�yes����no����Ҫ�˷������ʱ�䡣\n");
	return 1;
	}
	
	if (arg=="yes")
	{
	ob1 = present("nvren shoujuan", ob);
	destruct(ob1);
	message_vision(
		"$N������һ���־\n\n\n"NOR
                HIR"������$N�����Աߵ�˯�����������ѣ�˵��: ��㣬�Ҷ��Ȳ����ˡ�\n\n"NOR
                HIR"$N������ǽ��֣���Ƶĵƹ���һ�����˵�Ů������ʹ$N�������ԡ�\n\n"NOR
                HIR"$N�����Ŵ�������$N�������һ��ɾ�����ʧ�����޴����ڵİ��㸡��֮�С�\n\n"NOR
                HIR"......\n\n"NOR,
                this_player(), this_object());
	ob->unconcious();
        command("chat ����һ�����˵����ҵ�ʯ��ȹ��!");
	command("haha");
	command("get all from "+ob->query("id"));	
	ob->delete_temp("ganjiang/decide",1);
	return 1;
	}

	if (arg=="no")
	{
	ob1 = present("nvren shoujuan", ob);
	destruct(ob1);
	message_vision(
		"$N������һ���־\n\n",
                this_player(), this_object());
	command("say ��λ"+RANK_D->query_respect(ob)+"��֪�����Ǹ����ˣ����Ǹ�����˼ҵĺ��ӣ��ճ�
�޵��һ���������˼ң�����ȥ�����������ˣ�ʵ��û�а취��......\n");
	command("cry "+ob->query("id"));
	command("say ���Ҹ�����һ�����ܣ�ǰ����ȥ�����Ĳ�����ȥ���㣬ͻȻ
����Ů���ӵĽ���,��ʱū�ҷǳ����£����ԾͶ㵽������棬һ��һ��
���п���һ��Ů�������ˣ��굽��������ص�ȥ�ˣ����"+RANK_D->query_respect(ob)+"�ĳ�
�ã���ȥ�Ⱦ���λŮ���Ӱɣ�\n");
	ob->delete_temp("ganjiang/decide",1);
	ob->set_temp("ganjiang/heshang",1);
	return 1;
	}
	return 0;
}


