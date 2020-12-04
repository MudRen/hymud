// shaonian.c

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("�����", ({ "zhuge wu","wu" }) );
	set("title","��׳����");

	set("gender", "����" );
	set("age", 25);
	set("str",30);

	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);
	set("max_qi",1200);

	set("long","��λ��׳���������������˵��ٹ��ӣ����׺��䣬
�����������ʦ��ϰ�������ڴ�ͬ����С��������
�Ը�����Ƥ��å�´����ࡣ\n");

	set("combat_exp", 5300000);

	set_skill("force",300);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("changquan",100);
	//set_skill("ganchan",100);

	//map_skill("unarmed","changquan");
	map_skill("dodge","ganchan");

	set("inquiry",([
	"ʯͷ" : (: ask_me :),
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me(object who)
{
	if(who->query("quest/shaolin_quest/asked_shijian") != "��ͬ��")
		return 0;

	if(who->query("quest/shaolin_quest/win_zhuge"))
	{
		tell_object(who,sprintf(CYN"%s˵������ȥ����С��ɣ�����ר�Ź��·��ģ���˵��������ȥ�ġ�\n"NOR,name()));
		return 1;
	}

	if(who->query("quest/shaolin_quest/asked_zhuge"))
	{
		write(sprintf(CYN"%s˵������Ը�����(fight)�����ˡ�\n"NOR,name()));
		return 1;
	}

	write(sprintf(CYN"%s˵����������ô���£�ǰ������ȥ�������棬·��һ��ʯ����ǰ����Ժ����
            һ���ʯͷ�Ͽ���С���ڴ�ȭ������һ��ȭ�����Ҿ�ϲ���ⶫ��
            �����´����·�����������������׽������Ҳû����������Ȼ��
            ���������Ҳ�����书�����ǱȻ��Ȼ�(fight)��\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_zhuge",1);

	return 1;
}

int accept_fight(object who)
{
	if(who->query("quest/shaolin_quest/name") != "ȭ��ͼ��")
		return 0;

	if(!who->query("quest/shaolin_quest/asked_zhuge"))
	{
		command("say ��ѽ���������֣�");
		return 1;
	}
	if(who->query("quest/shaolin_quest/win_zhuge"))
	{
		command("say С��˵ʲôҲ���Һ����ٴ��ˡ�");
		return 0;
	}

	if( ((query("qi")*100)/query("max_qi") < 90) || (query("force") < 300))
	{
		call_out("do_full",5+random(5));
		return notify_fail(name()+"�������е��ۣ�������Ъ������Ǵ�ս���ٺϡ�\n");
	}

	if(who->query_temp("weapon"))
		return notify_fail("˵����ֻ�ǱȻ��Ȼ�������ô���üһ��\n");

	command("say �ã�С�����������ĸ��У�");
	call_out("check_state",2,who);
	return 1;
}

private void check_state(object who)
{
	if(!who || environment(who) != environment())
		return;

	if(is_fighting())
	{
		if(member_array(who,query_enemy()) != -1)
			call_out("check_state",2,who);
		return;
	}

	if( (query("qi") * 100 / query("max_qi")) < 50 )
	{
		tell_object(who,sprintf(CYN"%s˵�����濴���������Ǹ����ָ��֣����շ�֪�������죬�������ˣ�
            С������ķ��ڷ������ˣ����Ǽҵ�Ѿ��С����ר�Ź�
            �·��ģ������ȥ����������˵��������ȥ�ġ�\n"NOR,name()));

		who->set("quest/shaolin_quest/win_zhuge",1);
		who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
			"Ѿ��С��������ר�Ź��·��ģ�����ȥ��������"));
	}
}

void do_full()
{
	set("eff_qi",query("max_qi"));
	set("qi",query("max_qi"));
	set("eff_jing",query("max_jing"));
	set("jing",query("max_jing"));
	set("eff_jingli",query("max_jingli"));
	set("jingli",query("max_jingli"));
}

int remove_enemy(object ob)
{
	int n;

	n = ::remove_enemy(ob);
	if(!is_fighting())
		call_out("do_full",3);
	return n;
}

int accept_kill(object who)
{
	return notify_fail("��һ��㲻�ܶ����ǲ��ܶ���\n");
}
