 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("冷青萍", ({ "leng qingping" }) );
        set("title",HIG "寒枫堡" NOR);
        set("gender", "女性");
        set("age", 22);
        set("long",
" 一个衣衫虽华丽神情却极狼狈的少女。语声娇柔，身子更仿佛
弱不胜衣，与她姐姐的倔强冷傲，完全不同\n"
);
        set("inquiry", ([
               
        ]) );
       
        set("chat_chance", 1);
        set("chat_msg", ({
                "冷青萍幽幽叹道：“他没有折磨我，他根本没有折磨过我。”\n",
        }) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 1); 
        
        set("combat_exp", 1400000);        
        set("int", 30);
        set("per",60);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("str",30); 
       	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
        
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
        
