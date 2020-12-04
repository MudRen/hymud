// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("���ʦ̫", ({ "miejue shitai", "miejue"}));
set("title", "��ü��");
	set("gender", "Ů��");
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
	set("combat_exp", 3000000);
	set("score", 10000);
	
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
	   set_skill("persuading", 300);
        set_skill("throwing", 250);
        set_skill("force", 200);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 200);
        set_skill("buddhism", 200);
        set_skill("jinding-zhang", 220);
        set_skill("tiangang-zhi", 220);
        set_skill("huifeng-jian", 220);
        set_skill("yanxing-dao", 220);
        set_skill("zhutian-bu", 220);
        set_skill("linji-zhuang", 220);
        set_skill("bagua-dao", 220);
        set_skill("bagua-zhang", 220);
set_skill("unarmed", 280);
        set_skill("huixin-strike", 220);
        set_skill("piaoxue-hand", 220);
        set_skill("yinlong-whip", 220);
        set_skill("yitian-jian", 220);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	//carry_object(__DIR__"wtgun")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1223",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}    