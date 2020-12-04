 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("周仲英", ({ "zhou zhongying", "zhou"}) );
        set("nickname", HIR "铁胆庄庄主"NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 44);
        set("per", 25);
        set("int",28);
        set("str",40);
        set("attitude","friendly");
        
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor",90); 
        set("long",
                "铁胆庄庄主的主人，除了肚子微微有些发福外，别的看上去都不输\n给壮小伙们。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"一字一字沉声道：实在想不到这内奸原来就是你－百－里－长－青！！\n",
        }) );
        
        set("combat_exp", 4000000);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("no_busy",5);
        
       set("max_qi", 35000);
	set("max_jing", 35000);
	set("neili", 35000);
	set("max_neili", 35000);
	set("jiali",100);
	set("combat_exp", 8000000);
	set("score", 700000);

	set_skill("force", 300);
	set_skill("honghua-shengong", 380);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 380);
	set_skill("hand", 300);
	set_skill("benlei-shou", 380);
	set_skill("cuff", 200);
	set_skill("baihua-cuocuff", 380);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 380);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 380);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 380);
	set_skill("sword", 200);
	set_skill("luohua-jian", 380);
	set_skill("zhuihun-jian", 380);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("medicine", 380);
		set_skill("painting", 380);


 set_skill("bainiao-jian", 380);
	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuocuff");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	//map_skill("throwing", "wuying-feidao");
	map_skill("sword", "bainiao-jian");
	//map_skill("blade", "qiuge-dao");
	map_skill("parry", "baihua-cuocuff");
	prepare_skill("cuff", "baihua-cuocuff");
	prepare_skill("hand", "benlei-shou");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1500);
	set_temp("apply/damage",1500);


	set("no_get",1);
	set("chat_chance_combat", 90); 
	set("chat_msg_combat", ({
(: perform_action, "dodge.yunlong" :),				
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/flag");
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

                if ((int)who->query("jinyong/book9")==1)
{
                i = 500+random(2000);
		who->set("jinyong/book9",2);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		message_vision("$N对周围的人喊到，把文泰来放了，文泰来挥了挥手说道，我去回疆红花会总舵了。\n",this_object(),who);
		
		who->save();
}		
		
	::die();

}                         