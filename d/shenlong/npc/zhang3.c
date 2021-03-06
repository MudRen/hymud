// zhang3.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("章老三", ({ "zhang laosan", "zhang" }));
	set("title", HIY"神龙教"NOR"小头目");
	set("gender", "男性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个干瘦老头,一双小眼睛贼闪发光。\n");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

set("max_qi", 28000);
	set("max_jing", 28000);
	set("neili", 28000);
	set("max_neili", 28000);
//	set("jiali", 100);
	set("combat_exp", 5500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 250);
	set_skill("xuanming-zhang", 250);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 200);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 150);
        set_skill("yangsheshu", 150);
	set_skill("shedao-qigong", 250);
	set_skill("literate", 190);

	create_family("神龙教",2,"弟子");
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");


	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu" :),
                (: perform_action, "parry.juehu" :),                
                (: perform_action, "parry.juehu	" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
	]) );
	set("chat_msg", ({
"章老三高声叫道:教主宝训,时刻在心,建功克敌,无事不成!\n",
"章老三高声叫道:众志齐心可成城,威震天下无比伦!\n",
"章老三高声叫道:神龙飞天齐仰望,教主声威盖八方!\n",
"章老三高声叫道:乘风破浪逞英豪,教主如同日月光!\n",
"章老三高声叫道:教主永享仙福,寿与天齐!\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") == HIY "神龙教" NOR)
	{
		message_vision("$N摇了摇头。\n",this_object());
	command("tell "+ob->query("id")+"你我素不相识，我赁什么要教你呢？ \n"); 
		return 0;
	}
	return 1;	
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book723",1);
	::die();
}

#include "/kungfu/class/shenlong/shenlong.h";
