//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
	set_name("��˪��",({ "ling shuanghua", "ling"}));
	set("gender", "Ů��" );
	set("nickname", HIY"�˵����"NOR);
	set("title",HIM"֪��ǧ��"NOR);
	set("age", 18);
	set("long", 
"һ��������׵���Ů���ڹ��;ջ�����һ���ۻ����ӣ��������˵���ա�\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("max_qi",1000);
	set("max_jing",1000);
	set("max_neili",3000);
	set("qi",1000);
	set("jing",1000);
	set("neili",3000);
        set("combat_exp", 2000);	
	set("flower_count", 1);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"��˪�������˺죬�����������Բ�����������֣�СѾͷ�����˵����\n",
	}) );
	set("inquiry", ([
		            "����" : (: ask_me :),
            "�����" : (: ask_me :),
		"�̾�"   : (: ask_me :),
		"�̾ջ�" : (: ask_me :),

	]));
	setup();
	carry_object("/d/jiangling/obj/nenhuangshan")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
}


void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
             command("wanfu " + me->query("id"));
        command("say ��λ"+RANK_D->query_respect(me)+"����"+
                "���ջ��İɣ���֪�������ڻ�԰������ʲô����һ��ȥ�ͻᱻѬ���ģ�"+
                "�㻹����ذɡ�");
}

        
int accept_kill(object me)
{
        command("say ������������" + me->name() + "���" + RANK_D->query_rude(me) + "Ҫǿ���ң�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int ask_me()
{
        object who=this_player();
        if (who->query_temp("jinboxunhua")) {
                command("say �Ҳ��Ǹ��������������Ҳ̫�Ǹ��ˡ�");
                return 1;
        }
        command("say �������Ƕ��������Ѱ����Ҹ��ڻ�԰�����˾綾�Ľ�Ѯ����"
                + "���ȥ����ס�����Ϳ����ˡ�");
        who->set_temp("jinboxunhua",1);
        return 1;
}

