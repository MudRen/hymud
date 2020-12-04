#include <ansi.h>
 
inherit NPC;
 
void create()
{
	set_name("ǿ��", ({ "tu fei"}));

	set("gender", "����");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen", -15000);
	set("str", 35);
	set("int", 20);
      set("con", 35);
	set("dex", 37);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 10000); 
         set_skill("force", 180);
         set_skill("longxiang", 180);
         set_skill("dodge", 180);
         set_skill("shaolin-shenfa", 180);
         set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
         set_skill("parry", 170);
         set_skill("literate", 150);
        set_skill("xue-dao", 150);



        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("force", "longxiang");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
         set_temp("apply/attack", 50);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 220);
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.chi" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.resurrect" :),
                (: perform_action, "blade.shi" :),
                (: perform_action, "blade.xue" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.ying" :),
                (: perform_action, "cuff.jingang" :),
	}) );
 	prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "killer.h"
