#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    set("nickname", HIW "铁仙姑" NOR);
    set("gender", "女性");
    create_family("华山派", 16, "掌门");
    set("student_title","弟子");
    set("age", 59);  
    set("str", 25);
    set("int", 30);
    set("con", 25);
    set("qi", 50000);
    set("max_qi", 50000);
    set("jing", 2000);
    set("max_jing", 2000);
    set("neili", 9000);
    set("max_neili", 9000);
	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield(); 
} 
void init()
{
    object ob;
    ob=this_player();
   if ((int)ob->query("marks/killed_yuan")==1 )
       {
           ob->delete("marks/killed_yuan");
           kill_ob(ob);
       }
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("sword",1) < 100) {
         command("say  你对剑术所知甚少，竟然想来拜我！");
                return;
    }
    if ((int)ob->query_skill("dodge",1) < 100 ) {
        command("say 阁下的身法似乎不能学武啊！");
                return;
    }
    if( (int) ob->query("marks/杀楚留香") == 1 )
     { 
    command("smile");
    command("recruit " + ob->query("id"));
    ob->delete("marks/杀楚留香");
     }
     else   
     command("say 老身在此世上仇家倒不多，只有一人会坏我的大事...");
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}    
