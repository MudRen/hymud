 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("叶孤城", ({ "master ye", "master" }) );
        set("nickname", HIC"一剑东来"NOR+HIR" 天外飞仙"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 100);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
       set("per", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "sword.feixian" :),
        }) );
        set("pubmaster",1);
        set("attitude","friendly");
        set("neili", 35000);
        set("max_neili", 35000);
        //set("force", 15000);
        //set("force_factor", 100);
        set("max_qi",99999);
        set("max_jing",99999);
        set("max_jing",99999);
        set("eff_qi",9999);
        set("qi",99999);
        set("chat_chance", 1);
        set("chat_msg", ({
                "叶孤城从点点血斑的白袍撕下一条布条。\n叶孤城用从点点血斑的白袍撕下的布条替自己裹伤。\n",
        }) ); 
        set("long",
"
一个白面微须，穿著身雪白长袍的人。他的脸很白，既不是苍白，也不是惨白，
而是一种白玉般晶莹泽润的颜色。他的眼睛并不是漆黑的，但却亮得可怕，就
像是两颗寒星。他漆黑的头发上，戴著顶檀香木座的珠冠，身上的衣服也洁白
如雪，仿佛是天上的仙人一般。
\n"
        );
        create_family("白云城",1, "城主");
        set("rank_nogen",1);
        set("ranks",({"剑童","小剑士","剑士","小剑客","剑客",
                      "小剑侠","剑侠","剑师",CYN"大剑师"NOR,
                      CYN"剑仙"NOR,CYN"剑神"NOR,HIC"剑圣"NOR}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
        set("combat_exp", 8000000);
        set("score", 200000);
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",500);
	set_skill("feixian-steps",500);
	set_skill("feixian-sword",550);
	set_skill("jingyiforce",500);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
   carry_object(__DIR__"obj/bcloth")->wear(); 
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
        if(id_class == "baiyun"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N冷冷道：接天楼岂能容你放肆！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(WHT"$N袍袖一拂冷冷道：白云弟子向来忠心不二，若你有了异心，还是趁早走吧！\n"NOR, this_object());
        message_vision(CYN"$N嘿然道：白云岛的琴棋书画岂是逆徒之辈所能领悟？\n"NOR,this_object());
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
