//NPC /d/baituo/npc/ouyangke.c
#include <ansi.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。\n");
	set("title", "白驼山少庄主");
	set("nickname", HIM "玉面蛇心" NOR);
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 39000);
	set("max_qi", 39000);
	set("jing", 39800);
	set("max_jing", 39800);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 10);

	set("combat_exp", 3800000);
	set("score", 40000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: command("zhaoshe") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "sword.shan" :),                
                (: perform_action, "sword.yin" :),                
                (: perform_action, "sword.zhu" :),   
                (: perform_action, "hand.diaoshou" :),                
        }) );
	set_skill("unarmed", 100);
	set_skill("hand", 280);
	set_skill("strike", 280);
	set_skill("dodge", 120);
	set_skill("parry", 290);
	set_skill("force", 290);
	set_skill("staff", 280);
	set_skill("training", 50);
	set_skill("hamagong",190);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 200);
set_skill("qixian-wuxingjian", 300);
set_skill("xiyu-tiezheng", 300);
set_skill("shentuo-zhang", 300);
set_skill("cuff", 100);

set_skill("lingshe-quan", 300);
set_skill("zhaosheshu", 280);
set_skill("yangsheshu", 280);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "qixian-wuxingjian");
	map_skill("sword", "qixian-wuxingjian");

	//set("startroom","/d/city/beidajie1");

        //create_family("白驼山派",2,"弟子");

	set("chat_chance", 10);
	set("chat_msg", ({
		"欧阳克唱道: 漂亮姑娘你请留步￣￣让我多看你一眼￣￣\n",
		"欧阳克色迷迷地看着街边的小姑娘。\n",
		"欧阳克把纸扇一展，转过身去，深情地吟道：红颜知己最难得￣\n",
	}) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1250);
	setup();
	carry_object("/clone/weapon/changjian")->wear();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("gender")=="女性")
	{
	   switch(random(3))
	   {
		case 0:command("rose "+(string)ob->query("id"));break;
	  	case 1:command("kiss "+(string)ob->query("id"));break;
	   	case 2:command("love "+(string)ob->query("id"));break;
	   }
     
	}
	else
           say("欧阳克叹了一口气说：这位"+RANK_D->query_respect(ob)+
               ",你要是能给我弄一个女人来就好了。\n");
	return;
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book561",1);
		


	::die();
}


void leavet()
{
        object ob = this_object();
 message_vision("$N离开了这里！\n" NOR,this_object());
        destruct(this_object());
}