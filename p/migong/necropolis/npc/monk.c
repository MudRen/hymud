#include <ansi.h> 
inherit "/p/migong/necropolis/necropolis_npc";

void create()
{
        set_name("����", ({ "xing wu","xing"}) );
        set("gender", "����" );

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("class","shaolin");     
        set("long",
        ""
        );
        //set("force_factor", 150);
        set("auto_perform", 2); 
        set("max_qi", 8000000);
	set("eff_qi", 480000);        
        set("max_jing", 8500000);
        set("eff_jing",850000);
        set("neili", 8000000);
        set("max_neili", 4500000);
        set("max_jingli", 500000);
        set("combat_exp", 500000000);

 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 500);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set_skill("unarmed", 500);
	set_skill("blade", 500);
	set_skill("claw", 500);
	set_skill("club", 500);
	set_skill("cuff", 500);
	set_skill("dodge", 500);
	set_skill("finger", 500);
	set_skill("force", 500);
	set_skill("hand", 500);
	set_skill("parry", 500);
	set_skill("staff", 500);
	set_skill("strike", 500);
	set_skill("sword", 500);
	set_skill("whip", 500);

set_skill("weituo-zhang", 680);
set_skill("shaolin-tantui", 680);
set_skill("jingang-zhang", 680);
set_skill("jimie-zhua", 680);
set_skill("duoluoye-zhi", 680);
set_skill("mohe-zhi", 680);
set_skill("boluomi-shou", 680);
	set_skill("banruo-zhang", 680);
	set_skill("cibei-dao", 680);
	set_skill("damo-jian", 680);
	set_skill("fengyun-shou", 680);
	set_skill("fumo-jian", 680);
	set_skill("hunyuan-yiqi", 680);
	set_skill("jingang-quan", 680);
	set_skill("longzhua-gong", 680);
	set_skill("luohan-quan", 680);
	set_skill("nianhua-zhi", 680);
	set_skill("pudu-zhang", 680);
	set_skill("qianye-shou", 680);
	set_skill("sanhua-zhang", 680);
	set_skill("riyue-bian", 680);
	set_skill("shaolin-shenfa", 680);
	set_skill("weituo-gun", 680);
	set_skill("wuchang-zhang", 680);
	set_skill("xiuluo-dao", 680);
	set_skill("yingzhua-gong", 680);
	set_skill("yijinjing", 680);
	set_skill("yizhi-chan", 680);
	set_skill("zui-gun", 680);
	set_skill("weituo-chu", 680);
	set_skill("ranmu-daofa", 680);
	set_skill("wuying-jian", 680);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.lidichenfo" :),
                (: perform_action, "sword.ruying" :),
                 (: perform_action, "sword.foxing" :),	
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);

        set_temp("apply/attack", 5000);
        set_temp("apply/defense", 5000);
        set_temp("apply/damage", 1500);
        set_temp("apply/unarmed_damage", 1500);

        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        carry_object("/clone/weapon/sword")->wield();
        carry_object(__DIR__"obj/spirit_tower");
}  


int is_undead() {
	return 0;
}
