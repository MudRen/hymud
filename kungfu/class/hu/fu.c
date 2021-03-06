// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;

inherit NPC;
int ask_me();



void create()
{
        set_name("福康安", ({ "fu kangan", "fu" }));
        set("gender", "男性");
        set("nickname", HIR "王府大帅" NOR);

        set("age", 37);
        set("long", @LONG
这人就是王府大帅福康安。
LONG);
        set("attitude", "peaceful");
        set("str", 56);
        set("int", 38);
        set("con", 31);
        set("dex", 10);
    
        set("qi", 26000);
        set("max_qi", 26000);
        set("jing", 26000);
        set("max_jing", 26000);
        set("neili", 26500);
        set("max_neili", 26500);
        set("jiali", 160);
        set("level", 40);
        set("combat_exp", 8000000);
        set("vendetta/authority",1);
        set_skill("force", 290);
        set_skill("lengyue-shengong", 290);
        set_skill("blade", 460);
        set_skill("baisheng-daofa", 460);
        set_skill("hujia-daofa", 290);
        set_skill("zileidao", 290);
        set_skill("dodge", 290);
        set_skill("sixiang-bufa", 290);
        set_skill("parry", 290);
        set_skill("strike", 290);
        set_skill("tianchang-strike", 290);
        set_skill("cuff", 290);
        set_skill("hujia-quan", 290);
        set_skill("throwing", 200);
        set_skill("mantian-xing", 200);
        set_skill("literate", 290);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "zileidao");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "tianchang-strike");
        map_skill("cuff", "hujia-quan");
        //map_skill("throwing", "mantian-xing");

        prepare_skill("strike", "tianchang-strike");
        prepare_skill("cuff",   "hujia-quan");

        //create_family("五虎门", 1, "掌门");
        set("inquiry",([
                "掌门人大会" : (: ask_me :),
        ]));


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                 (: perform_action, "blade.posui" :),
                (: perform_action, "blade.tulong" :),                 	
                (: perform_action, "cuff.kuai" :),
                (: perform_action, "strike.huang" :),
                (: perform_action, "dodge.fei" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
	set_temp("apply/attack",100);
	set_temp("apply/defense",100);
	set_temp("apply/armor",800);
	set_temp("apply/damage",800);        

        //set("master_ob",5);
	setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void die()
{
	object ob,corpse;
	ob=this_object();
	message_vision("$N身体一闪 消失在了远处。\n",ob);
	destruct(ob);
	return;
}

int ask_me()
{
	int i;
        object fang ;
	object who = this_player();
	object where = environment(who);
	
        if( who->is_fighting())
        {
		message_vision("$N对$n说道： 你打玩再说吧！\n",this_object(),who);
		return 1;	
	}
fang = present("wudang gaoshou",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"你先打败武当派来的大师再说吧。\n",this_object(),who);
		return 1;
	}

 fang = present("shaolin gaoshou",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"你先打败少林派来的大师再说吧。\n",this_object(),who);
		return 1;
	}
 fang = present("feng tiannan",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"你尽然....来人，和他拼了! \n",this_object(),who);
		return 1;
	}

	
		  	if(((int)who->query("jinyong/book1")!=2))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	
	  	if(((int)who->query("jinyong/book1")>=3))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("sight " + who->query("id"));
	message_vision("$N对$n说道： 看来事情败露了。\n",this_object(),who);
	message_vision("$N对$n说道： 罢了,罢了。不知道田归农还能不能得手。\n",this_object(),who);


	
	i = 200+random(800);
	who->set("jinyong/book1",3);
	who->add("combat_exp",i+9880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*10)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	this_object()->kill_ob(who);
	return 1;
}