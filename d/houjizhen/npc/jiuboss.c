// jiuboss.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("÷����", ({ "mei shijie", "boss" }));
	set("title", "�ƹ��ϰ�");
	set("shen_type", 1);
	set("gender", "����");
	set("age", 50);
	set("per", 10);
	set("long",
		"\n������Ƚ��䵭�������е��ˣ�����·��һȳһȳ��\n");

        set("max_sen",4000);
        set("max_qi", 4000);
        set("qi", 4000);
	set("max_jing", 4000);
	set("jing", 4000);
	set("max_neili", 400);
	set("neili", 400);
	set("force_factor", 40);

	set("combat_exp", 200000);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
	"÷���ܺ�Ȼ˵����֪��ʲôʱ��������и�������\n",
	"÷���ܺ�Ȼ˵�������ҵ�Ƣ������ã���ҿ�ҪС���ˡ�\n",
	}));

        set("inquiry", ([
		"here" :  "���ﶼ��֪����ʲô�ط����������������֪���ˡ�\n",
		"����ˮ" :  "��֪���ȾƸ���ˮ�ķֱ��𣿾ƣ�Խ��Խů��ˮ��Խ��Խ������\n",
		"ɱ��" :  "\n����Щ�����ǲ�Ը���ᣬ������Щ���㲻���ټ����е��������Բ����㣬Ҳ����\n���Ҫɱ�����ǣ������㲻�ҡ������ֻ�������ò�ֵ����ʵɱ�ˣ������ס���\n�и����ѣ������书�ǳ��ã�������������е����ѣ�ֻҪ��������һ������\n����һ�����԰���ɱ���Ǹ��ˣ��㾡�ܿ���һ�¡���ʵɱһ�����Ǻ����ף�����\nΪ������ܶ��˶���ð����գ���֪����Ը��ô(decide)��\n",
       ]) );

	setup();
        add_money("silver", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
	{
        add_action("do_decide", "decide");
	}

int do_decide(string arg)
{
	object ob;
    	ob=this_player();

	if (!arg)
	{
	command("?");
	command("say �������ʲôѽ����ֻ��Ҫ�ش�yes����no��\n");
	return 1;
	}
	
	if (arg=="yes")
	{	
	command("haha");
	command("say �����ģ��ӽ��Ժ������������֯��һԱ�ˣ�\n");	
	command("say �úøɣ���һ�����г�Ϣ��\n");
	ob->set_temp("heiyi/pass",1);
	return 1;
	}

	if (arg=="no")
	return notify_fail("�ٺ٣���Ȼ����������Ҳ����ǿ�㣬����������������ɡ�\n");
	return 0;
}
