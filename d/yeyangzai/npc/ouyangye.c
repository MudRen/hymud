#include <ansi.h>
inherit NPC;


void create()
{
  set_name("ŷ��Ұ", ({ "ouyang ye", "master","ouyang" }) );
	        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
        set("attitude", "peaceful");
        set("combat_exp", 9999999);
        set("score", 90000);
       set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 350);
		set_skill("fy-sword", 300);
		set_skill("cloudsforce", 300);
		set_skill("tie-steps", 350);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "cloudsforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.fengqiyunyong" :),
                (: perform_action, "unarmed.qiankun" :),
                (: perform_action, "dodge.chansi" :),
        }) );
                set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
	set("ziyuang","���");
	set("jizhi",100);
	set("kaifa",5);
	setup();
        carry_object("/d/yeyangzai/npc/obj/zijindao")->wield();
        carry_object("/d/yeyangzai/npc/obj/wujinfu")->wield();
        carry_object("/d/yeyangzai/npc/obj/jinsijia")->wear();
	add_money("gold",1);

}

