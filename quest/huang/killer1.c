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
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.liuyun" :),
                (: perform_action, "strike.yixing" :),
         })); 
         set_skill("force", 100);
         set_skill("xuantian-wuji", 140);
         set_skill("dodge", 120 + random(30));
  
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );


        set_skill("kunlun-shenfa", 140);
        set_skill("strike", 120 + random(30));
        set_skill("kunlun-zhang", 120 + random(30));
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 320);
  	prepare_skill("strike", "kunlun-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "killer.h"
