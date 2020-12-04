// xiaoyao_weng.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ң��", ({ "xiaoyao weng","weng" }) );
        set("gender", "����");
        set("age", 75);
        set("long",     "����һλ�뷢�԰׵����ˣ������⣬������멣�һ���ɷ���ǡ�\n");
        set("combat_exp", 1000000);
        set("score", 1000);
        set("attitude", "friendly");
	set("per",100);
	set("kar",100);
	set("str",100);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",500);
	set("max_atman",5000);
	set("atman",5000);
	set("max_mana",5000);
	set("mana",5000);
	set("max_kee",5000);
	set("max_gin",5000);
	set("max_sen",5000);
	
	set_skill("unarmed",280);
	set_skill("parry", 280);
	set_skill("dodge", 280);

	set("inquiry",([
	"�ٲݾ�" : "������ũ�ϱ鳢�ٲݣ��������ʱ��д��һ�����ٲݾ�����
��������˺ܶ��ҩ��ҩ�Ժ�ҩ�����Ʒ������Ϸ�Ǳ���о��в�ҩ��
ʮ��Ҳ�����ĵã����ܵõ����ٲݾ�����ԭ����Ϸ���ĵ����޴��飬
Ϊ�����츣������֪����������η���\n",
]));
	set("chat_chance",5);
	set("chat_msg",({
	"��ң��˵����������ũ�ϱ鳢�ٲݣ�д��һ�����ٲݾ�����\n",
	"��ң��˵������֪���ٲݾ�����������η����Ƿ񻹴���������\n",
}));
        setup();

        carry_object(__DIR__"obj/he_chang")->wear();
}

void init()
{
	add_action("do_answer","answer");
}

int recognize_apprentice(object who)
{
	if( !who->query_temp("xiaoyao_weng/learn")) return 0;
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->name() == "�ٲݾ�(�ϲ�)")
	{
	if( who->query_temp("xiaoyao_weng/book_two"))
		{
	write("��ң��˵������л�����롶�ٲݾ������˾�Ϊ���������츣��С���Ϸ�Ǳ��һ����
����������Ϊ���ݴ�(huan-rong)����������(zhouyi) ��Ը�����������㣬
������ϰ�����ż���Ҫ��ȴ���׼�Ķ�Թ���ʧ����֪���Ƿ����´ξ��ģ�
(answer yes/no)\n");
		who->delete_temp("xiaoyao_weng");
		who->set_temp("xiaoyao_weng/one_and_two",1);
		return 1;
		}
	write("��ң��˵�������ǡ��ٲݾ������ϲ���лл�㡣��֪�²��������...\n");
	who->set_temp("xiaoyao_weng/book_one",1);
	return 1;
	}

	if(ob->name() == "�ٲݾ�(�²�)")
	{
	if( who->query_temp("xiaoyao_weng/book_one"))
		{
	write("��ң��˵������л�����롶�ٲݾ������˾�Ϊ���������츣��С���Ϸ�Ǳ��һ����
����������Ϊ���ݴ�(huan-rong)����������(zhouyi) ��Ը�����������㣬
������ϰ�����ż���Ҫ��ȴ���׼�Ķ�Թ���ʧ����֪���Ƿ����´ξ��ģ�
(answer yes/no)\n");
		who->delete_temp("xiaoyao_weng");
		who->set_temp("xiaoyao_weng/one_and_two",1);
		return 1;
		}
	write("��ң��˵�������ǡ��ٲݾ������²���лл�㡣��֪�ϲ��������...\n");
	who->set_temp("xiaoyao_weng/book_two",1);
	return 1;
	}

	return 0;
}

int do_answer(string arg)
{
	object obj,me = this_player();
	if(!arg || arg == "") return 0;
	if(arg != "yes" && arg != "no") return 0;
	if(!me->query_temp("xiaoyao_weng/one_and_two")) return 0;
	if(arg == "yes")
	{
	write("��ң��˵�����ã��ã���λ"+RANK_D->query_respect(me)+"���Ǵ�ӱ���۸����ߣ����ܴ󳹴���\n");
	me->delete_temp("xiaoyao_weng");
	me->set_temp("xiaoyao_weng/learn",1);
	return 1;
	}

	if(arg == "no")
	{
	obj = new(__DIR__"obj/yaopai");
	obj->move(this_object());
	command("give yao pai to "+(string)me->query("id"));
	me->delete_temp("xiaoyao_weng");
	write("��ң��˵������������λ"+RANK_D->query_respect(me)+"��Ե�Ѷϣ�������һ���˼�������������Ϊ֮��\n");
	return 1;
	}
}