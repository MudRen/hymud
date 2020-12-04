// liumang.c
// by dicky

inherit NPC;
int ask_shoujuan();

void create()
{
        set_name("С��å", ({"xiao liumang","liumang"}) );
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ�����ֺ��е�С��å��\n");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        set("inquiry", ([
		"����":(: ask_shoujuan :),
        ]));

        set("chat_chance", 2);
        set("chat_msg", ({
                "��å�������ֵ�˵�������������а������������һ�����ƣ���\n"
                "С���־�Ȼ������һ����������\n",
                "��å����ǽ�Ǵ����˯���ˣ�˯����Ҳ��֪�뵽��ʲ�ᣬ�����\n"
                "�ߵ����ҿ�������ѩ�׵Ĵ��ȣ��Ҿ����ˡ������ġ�ඡ�\n",
                "��å�������Լ��Ŀڴ���̾�˿���˵��������Ǯ����С����ƭȥ\n"
                "�ˣ�����ȥ�Ҵ����ˡ�\n",
                "��å���¶��һ˿аЦ��˵����������������湻������������\n"
                "�̵Ĺ�����������\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 3);
}

int ask_shoujuan()
{
	object ob;
	ob=this_player();
	if (ob->query_temp("ganjiang/have_ask"))
	{
	command("kick "+ob->query("id")+"\n");
	command("say ��ղŲ������ʹ���ô�������ں�æ����Ҫ��������ң�");
	return 1;
	}
	
	if (!ob->query_temp("ganjiang/shoujuan"))
	{
	command("hehe");
	command("say "+RANK_D->query_respect(ob)+"������֪����ѽ������......��������Ҷ����ˣ�
���ǿ��������Ŷ��\n");
	command("say "+RANK_D->query_respect(ob)+"���Ҹ������,������������湻������������
�̵Ĺ���������!\n");
	command("say "+RANK_D->query_respect(ob)+"����Ҫ��ҪҲȥ���ԣ��������������������Ŷ��
ֻҪ������ȥ��������һ������������������\n");
	command("haha");
	ob->set_temp("ganjiang/shoujuan",1);
	ob->set_temp("ganjiang/have_ask",1);
	message_vision(
                "\nС��å��$Nһ���־\n",
                this_player(), this_object() );
	new(__DIR__"obj/shoujuan")->move(ob);
	return 1;
	} 
	else 
	{
	command("say ����......��Ҳ�����������ô��");
	return 1;
	}
}
