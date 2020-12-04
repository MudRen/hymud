 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_challenge();
int leave();
void create()
{
    set_name("������", ({ "master xiao", "xiao","master" }) );
    set("gender", "����" );
    set("nickname",HIY "���¿�" NOR);
    set("reward_npc", 1);
    set("difficulty", 15);
    set("age", 45);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    set("class","yinshi");
    set("apprentice_available", 50);
    create_family("������", 1, "����");
    set("rank_nogen",1);
    set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        CYN"����"NOR,CYN"��ʿ"NOR,HIC"����"NOR }));; 
    set("long",
        "�����������û���κ���֪��������\n"
        );
    set("force_factor", 40);
    set("max_neili", 93500);
        set("neili", 93500);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",92999);
	set("eff_qi",92999);
	set("qi",92999);
	set("eff_jing",92999);
	set("jing",92999);

        set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("whip", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("flying-dragon", 500);
	set_skill("thunderwhip", 530);
	set_skill("iceheart", 550);
	set_skill("zuixian-steps", 500);

	map_skill("unarmed", "flying-dragon");
        map_skill("whip", "thunderwhip");
        map_skill("force", "iceheart");
        map_skill("parry", "thunderwhip");
        map_skill("dodge", "zuixian-steps");
        set("dex",35);
        set("str",30);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "whip.tianleiyiji" :),
        }) );
	set("pubmaster",1);

        set("inquiry",([
        "challenge" : (: ask_challenge :),
        "��ս": (: ask_challenge :),
                "tiaozhan": (: ask_challenge :),
                "���촸" : (: ask_challenge :),
                "master lan" : (: ask_challenge :),
                "leave" : (: leave :),
    ]) );
    set("agi",25);
    set("int",30);

    setup();
    carry_object(__DIR__"obj/shenxue")->wear();
    carry_object(__DIR__"obj/baojia")->wear();
    carry_object(__DIR__"obj/zhiai")->wear();
    carry_object(__DIR__"obj/sidai")->wield();
}


int ask_challenge()
{
        object me;
        me = this_player();
        if ((string) me->query("class") == "yinshi" && me->query("marks/challenge_xiao_forlan"))
        {       
                say(HIW"\n��������Ц��һ���������϶����������𣿡�\n"NOR);
                if (me->query("combat_exp")>1500000 && me->query("score")>10000)
                {
                        me->delete("marks/challenge_xiao_forlan");
                        message_vision(HIW"$N�����Ķ�$n˵��������ѧҵ�гɣ���ô����Ϊʦ��һ��ɡ����������������촸���̹ž�ʽ(challenge master lan).��\n"NOR,this_object(),me);
                   me->set("marks/challenge_lan",1);
                }else
                {
                        message_vision("$N��Ц���������϶��Ĵ�������һ����ֻ��ϧ����δ�������ܴ�Ϊʦ��ѵ����������\n ",this_object());
                }
                return 1;
        }
        return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "yinshi"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ�����ĳ��ͽ�ܣ��ݲ��ø������̣ܽ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
   if (this_player()->query("class")!="yinshi") return 0;
        message_vision(CYN"$N�������Ҳ���ǿ�����¡���\n"NOR, this_object());
        message_vision(CYN"$N˵��ֻ����ͨ�콵̫Ϊ�ն񣬲��������������\n"NOR,this_object());
        return 1;
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
