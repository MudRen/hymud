#include <ansi.h>
inherit NPC;
 
void create()
{
	set_name("����", ({ "tu fei","fei"}));
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -8000);
	set("str", 38);
	set("int", 30);
	set("con", 35);
	set("dex", 37);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 800000); 
         set_skill("force", 100);
         set_skill("xuantian-wuji", 140);
         set_skill("dodge", 120 + random(30));
  

        set_skill("huifeng-jian", 180);
        set_skill("kunlun-shenfa", 140);
        set_skill("strike", 120 + random(30));
        set_skill("kunlun-zhang", 120 + random(30));
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("linji-zhuang", 250);
        set_skill("literate", 80);
        set_temp("apply/attack", 50);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 220);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.jue" :),
                (: perform_action, "sword.liaoyuan" :),
                (: perform_action, "sword.juemie" :),                                
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );

        setup(); 
        carry_object("/clone/weapon/gangjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "killer.h"
