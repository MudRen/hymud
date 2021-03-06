 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("上官金虹", ({ "master shangguan", "master", "master shang" }) );
    set("nickname", RED"龙凤双环"NOR);
    set("gender", "男性" );
    set("class", "assassin");
    set("age", 44);
    set("cor", 40);
    set("cps", 30);
    set("int", 30);
    set("pubmaster",1);
    set("per", 30);
    set("ill_boss",5);
        set("reward_npc", 1);
        set("difficulty", 30);
    set("attitude","friendly");
    set("max_neili", 55000);
    set("neili", 55000);
    set("force_factor",80+random(50));
    set("max_mana",2000);
    set("mana",2000); 
    set("long",
        "
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出一丝
得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松弛，一个
人的精神若松弛，就容易造成错误。
\n"
        );
    create_family("金钱帮  ", 1, "帮主");
       set("rank_nogen",0);  
    set("combat_exp", 8000000);
    set("score", 200+random(200000));
    set("agi",25);
    set("int",30);
          set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);

        set("combat_exp", 90000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "hammer.longfengshuangfei" :),
        }) );
        set_skill("dodge", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
        set_skill("jingxing",520);
        set_skill("hammer", 550);
        set_skill("jinhong-steps",520);
        set_skill("longfenghuan",550);
        map_skill("dodge", "jinhong-steps");
        map_skill("hammer", "longfenghuan");
        map_skill("parry", "longfenghuan");
        map_skill("force", "jingxing");
     
    set("ranks",({"帮众","副香主","香主","副堂主","堂主",
                   "副坛主","坛主","副舵主","舵主",
                      "护法","大护法","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));  
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/longfenghuan")->wield();
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
        if(id_class == "assassin"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N喝道：在我面前杀我帮的弟子，不想活了！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
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



