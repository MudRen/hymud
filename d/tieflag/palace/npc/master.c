 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_challenge();
int leave();
void create()
{
    set_name("箫王孙", ({ "master xiao", "xiao","master" }) );
    set("gender", "男性" );
    set("nickname",HIY "黄衣客" NOR);
    set("reward_npc", 1);
    set("difficulty", 15);
    set("age", 45);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    set("class","yinshi");
    set("apprentice_available", 50);
    create_family("帝王谷", 1, "谷主");
    set("rank_nogen",1);
    set("ranks",({ "弟子","领班","小管家","管家","大管家",
                        CYN"隐者"NOR,CYN"隐士"NOR,HIC"侠隐"NOR }));; 
    set("long",
        "箫王孙的来历没有任何人知道．．．\n"
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
        "挑战": (: ask_challenge :),
                "tiaozhan": (: ask_challenge :),
                "蓝天锤" : (: ask_challenge :),
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
                say(HIW"\n箫王孙冷笑了一声：“蓝老儿还不死心吗？”\n"NOR);
                if (me->query("combat_exp")>1500000 && me->query("score")>10000)
                {
                        me->delete("marks/challenge_xiao_forlan");
                        message_vision(HIW"$N淡淡的对$n说：“你已学业有成，那么就替为师走一遭吧。用天雷破试试蓝天锤的盘古九式(challenge master lan).”\n"NOR,this_object(),me);
                   me->set("marks/challenge_lan",1);
                }else
                {
                        message_vision("$N冷笑到：“蓝老儿的锤法不堪一击，只可惜你火候未到，不能代为师教训他。。。”\n ",this_object());
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
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "yinshi"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：箫某的徒弟，容不得阁下来管教！\n"NOR, this_object(),player);
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
        message_vision(CYN"$N道，“我不勉强你留下。“\n"NOR, this_object());
        message_vision(CYN"$N说：只是这通天降太为险恶，不能落在外人手里。\n"NOR,this_object());
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
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
