 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 

int leave(); 
void create()
{
set_name(YEL"葛伦"NOR, ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
	set("dex", 99);
	set("str", 90);
        set("apprentice_available", 20);

	set("long",
		"葛伦高僧已在大昭寺主持多年。男女弟子遍布关外。\n"
		);
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大昭寺的木屋里。",
	]) );
	        create_family("大昭寺", 20, "主持");
    set("rank_nogen",1);
    set("ranks",({"弟子","罗汉","高僧","大师","圣僧",YEL"法王"NOR,YEL"活佛"NOR,HIY"主持"NOR}));
        set("combat_exp", 9000000);
        set("score", 90000);
         set("max_neili", 93500);
        set("neili", 93500);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",92999);
	set("eff_qi",92999);
	set("qi",92999);
	set("eff_jing",92999);
	set("jing",92999);
       set_skill("unarmed", 50);
	set_skill("staff", 300);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 80);
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 500);
	set_skill("cloudstaff", 500);
	set_skill("bolomiduo", 500);
	set_skill("buddhism", 500);
        set_skill("jin-gang", 550);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
set("pubmaster",1);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 5500);
        set_temp("apply/damage", 5600);              
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
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
