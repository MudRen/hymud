
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({ "afei", "fei","feia" }) );
	set("gender", "����" );
        set("title", HIG "��Ϊ����" NOR);
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("long",
		"�����޵У���������\n"
		);
        set("force_factor", 200);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",59999);
        set("max_jing",59999);
	set("eff_qi",59999);
	set("qi",59999);
	set("eff_jing",59999);
	set("jing",59999);
        set("max_force", 30000);
        set("force", 30000);
	set("force_factor", 300);
	set("cor",200);
        set("combat_exp", 9999999);
        set("score", 90000);
       set("max_neili", 50000);
        set("neili", 50000);
	set("force_factor", 300);
	set("cor",200);
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("sword", 510);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("literate", 100);
                set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
	set_skill("dodge", 200);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
	set_skill("sharen-sword", 500);
        map_skill("sword", "sharen-sword");
set("pubmaster",1);

	setup();
	carry_object("clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say �ҵĽ�������ɱ�˵ģ����������Ȼ�����ģ�");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���ɶ�")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
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
