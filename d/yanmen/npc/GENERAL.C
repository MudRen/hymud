// #pragma save_binary
// general.c

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("严廷殷", ({ "master general","master","general" }) );
	set("title", "镇国大将军");
	set("nickname", YEL "镇国大将军" NOR);
	set("gender", "男性");
	set("age", 45);
	set("long",
        	"容光焕发，左佩刀，右佩剑，威风里里，其高七尺六寸，虎背\n"
        	"熊腰，年轻时同和大天邪于兰天武同拜一师，武功\造诣不在大\n"
        	"天邪之下，但志向不同，后成了京师武功\第一、人人称羡的镇\n"
        	"国大将军。\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"黄石隘口" : "你眼睛脱窗啊，这里就是黄石隘口。\n",
		"后备兵" : "我不管这种事的，你别来烦我。\n",
		"兵器库" : "你找死啊！问这种问题，你想干麻啊。\n",
		"印鉴" : "你怎么知道的？帮我找找吧，找到了我送你礼物。\n",
	]) );
	set("neili", 51800);
	set("max_neili", 51800);
	set("force_factor", 20);
	set("max_jing", 31200);
	set("eff_jing", 31200);
	set("qi", 31200);
	set("max_qi", 31200);
	set("eff_sen", 200);
	set("sen", 200);

	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
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
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	//map_skill("dodge", "zhongyunti");


	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33m印鉴[0m") {
		command("say 真是谢谢你了。");
		command("smile");
		command("say 为了答谢你，这把古剑送你，当做报酬吧。");
		obj=new(__DIR__"obj/old_sword");

		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}

	if ( (string)ob->name() == "印鉴" ) {
		command("say 你拿给我的是什么东西啊!");
 		command("say 别想拿这种东西来骗我");
		command("say 给我滚出去");
 		who->set_temp("将军/kick", 1);
		//who->move(PATH);
		return 0;
	}

	if ( !ob->value() ) {
		command("say 谢了!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}

	command("say 啊，真是谢谢你了。");
	return 1;
}
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


if (who->query_temp("book941"))
{
		message_vision("$N身上掉下一张七族盟书。$n把七族盟书拿到了手上。\n",this_object(),who);
who->set_temp("book942",1);
}


	::die();

}
