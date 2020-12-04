// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("������", ({ "tang wenliang", "tang"}));
set("title", "�����");
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
	set("combat_exp", 3000000);
	set("score", 10000);
	 set_skill("literate",220);
        set_skill("unarmed",220);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",220);
	set_skill("strike",220);
	set_skill("literate",220);	
	set_skill("cuff",220);	
	set_skill("changquan",220);
        set_skill("luohua-jian",220);
        set_skill("sword",220);
set_skill("ill-quan",220);
set_skill("luoriquan",220);
set_skill("qinnashou",220);
	set_skill("array",300);
	set_skill("taoism", 300);
set_skill("shizi-zhan",220);
set_skill("dahong-quan",220);
set_skill("qishang-cuff",220);
set_skill("kongling-jian",220);
set_skill("luofeng",220);
set_skill("taiyi",300);
set_skill("sanqing-jian",220);
set_skill("kongdong-xinfa",220);

        //set_skill("doomsword",220);
        //set_skill("chilian-shenzhang",220);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",220);

        map_skill("unarmed","qishang-cuff");
        map_skill("sword","sanqing-jian");
        map_skill("force","kongdong-xinfa");
        map_skill("dodge","luofeng");
        map_skill("parry","qishang-cuff");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "roar" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.huan" :),
                (: perform_action, "sword.jianmang" :),
                (: perform_action, "sword.sanlianji" :),	
                (: perform_action, "sword.wanxiang" :),	
    (: perform_action, "dodge.bagua" :),	                	
                (: perform_action, "parry.hunpofeiyang" :),
                (: perform_action, "parry.qishang" :),
            (: exert_function, "zhenhuo" :),
            (: exert_function, "dingshen" :),
            (: exert_function, "sanqing" :),
            (: exert_function, "wuxing" :),			


        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	//carry_object(__DIR__"wtgun")->wield();
	//carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1225",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}  