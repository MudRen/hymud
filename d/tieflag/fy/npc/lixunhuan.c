 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��Ѱ��", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"С��ɵ�"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("reward_npc", 1);
        set("difficulty", 40);
        set("attitude","friendly");
        set("max_neili", 35000);
        set("neili", 35000);
        set("courage",1000);
        	set("max_qi",999999);
        set("max_jing",999999);
	set("eff_qi",59999);
	set("qi",59999);
	set("eff_jing",59999);
	set("jing",59999);
        set("force_factor", 3); 
        set("rank_info/respect", "��̽��"); 
        set("long",
"��Ѱ�������̽�������н����º�С��ɵ���
һ�ַɵ��������ڰ������ı����������е�����
�������ѣ��������鷢��\n"                
        );
        create_family("����һ��", 2, "�˽�");
        set("student_title","�˽�");
        set("combat_exp", 10000000);
        set("score", 200000); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "��Ѱ����ͣ���ڿȣ��������һ˿��Ѫ��\n",
                "��Ѱ������ɫԽ���԰��ˡ�\n",
"��Ѱ��̾���������������������ľ��\n",
        }) );
        set("pubmaster",1);
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 380);
        set("hxweapon", 1);

        set_skill("throwing", 500);
        set_skill("feidao", 520);
        set_skill("force", 40);
        set_skill("literate", 400);
        set_skill("taiji-shengong",100);
        map_skill("throwing", "feidao");
        map_skill("force", "taiji-shengong");
        //map_skill("sword", "taiji-jian");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.xiaolifeidao" :),
                (: perform_action, "throwing.xiaolifeidao" :),
        }) );

        setup();
       carry_object(__DIR__"obj/xlfd_knife")->wield();
        carry_object(__DIR__"obj/whitecloth")->wear();
} 

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}


void reset()
{
        set("already",0);
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
