//long.c
#include <ansi.h>
inherit NPC;

int ask_zhou();

void create()
{
        set_name("多尔衮", ( { "duoer gun", "gun" }) );
        set("title", HIR"睿亲王"NOR);
        set("gender", "男性" );
        set("age", 60);
        set("long",
              "这是个看起来五十来岁的汉子，面眉全面，脸色红润，着一袭黄袍，昂然挺立。\n"
        );

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 1000);

        set("qi",84000);
        set("max_qi", 84000);
        set("jing", 82000);
        set("max_jing", 82000);
        set("neili", 82000);
        set("max_neili", 82000);
        set("jiali", 150);
        set("combat_exp", 9000000);
        set("score", 250000);

    
        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 570);
        set_skill("unarmed", 500);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("hand",570);
        set_skill("staff", 570);
        set_skill("taixuan-gong", 550);
set_skill("huanhe-dao", 550);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 580);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 550);
set_skill("cuff", 550);
set_skill("unarmed", 550);
set_skill("blade", 550);
set_skill("sword", 550);
set_skill("club", 580);
set_skill("bawang-qiang", 580);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 580);
set_skill("bawang-qiang", 580);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book2")>=4))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book2")==3))
{
		message_vision("$N说道：大清不会败的，不 不 不！\n" NOR,this_object());
		i = 900+random(5000);
		who->set("jinyong/book2",4);
		who->add("combat_exp",i+28000);
		who->add("potential",i*28);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+28000)+"点经验"+
		           chinese_number(i*28)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了雪山飞狐的所有任务!"NOR"\n", users());
		who->save();
}
        }
	::die();
}