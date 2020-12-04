// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("����", ({ "kong zhi", "kong"}));
set("title", "������");
	set("gender", "����");
	set("attitude","heroism");
	set("class", "bonze");

	set("age", 71);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 100);
	set("max_qi", 10000);
	set("max_jing", 12900);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali",290);

	set("score", 10000);

	set("combat_exp", 3000000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 300);
	set_skill("literate", 220);

	set_skill("unarmed", 220);
	set_skill("blade", 220);
	set_skill("claw", 220);
	set_skill("club", 220);
	set_skill("cuff", 220);
	set_skill("dodge", 220);
	set_skill("finger", 220);
	set_skill("force", 220);
	set_skill("hand", 220);
	set_skill("parry", 220);
	set_skill("staff", 220);
	set_skill("strike", 220);
	set_skill("sword", 220);
	set_skill("whip", 220);

set_skill("weituo-zhang", 220);
set_skill("shaolin-tantui", 220);
set_skill("jingang-zhang", 220);
set_skill("jimie-zhua", 220);
set_skill("duoluoye-zhi", 220);
set_skill("mohe-zhi", 220);
set_skill("boluomi-shou", 220);
	set_skill("banruo-zhang", 220);
	set_skill("cibei-dao", 220);
	set_skill("damo-jian", 220);
	set_skill("fengyun-shou", 220);
	set_skill("fumo-jian", 220);
	set_skill("hunyuan-yiqi", 220);
	set_skill("jingang-quan", 220);
	set_skill("longzhua-gong", 220);
	set_skill("luohan-quan", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("pudu-zhang", 220);
	set_skill("qianye-shou", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("riyue-bian", 220);
	set_skill("shaolin-shenfa", 220);
	set_skill("weituo-gun", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("yingzhua-gong", 220);
	set_skill("yijinjing", 220);
	set_skill("yizhi-chan", 220);
	set_skill("zui-gun", 220);
	set_skill("weituo-chu", 220);
	set_skill("ranmu-daofa", 220);
	set_skill("wuying-jian", 220);
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
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),		 			
        }) );
	//set_temp("apply/attack", 100);
	//set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	//carry_object(__DIR__"wtgun")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1221",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}      