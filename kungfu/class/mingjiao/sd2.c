// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("��Զ��", ({ "song yuanqiao", "song"}));
set("title", "�䵱");
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
	set("jiali", 50);
	set("combat_exp", 3500000);
	set("score", 60000);
        set_skill("taoism", 280);
	set_skill("force", 200);
	set_skill("taiji-shengong", 280);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 220);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 220);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 220);
	set_skill("wudang-jian", 220);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 220);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1222",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}  