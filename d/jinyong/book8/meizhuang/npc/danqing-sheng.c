// danqing-sheng.c 
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("丹青生", ({ "danqing sheng", "sheng" }));
        set("title", "梅庄四庄主");
        set("long",
                "他就是梅庄四位庄主排行第四的丹青生。\n"
                "身穿一件干干净净的青色长袍。\n"
                "他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("gender", "男性");
        set("age", 40);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50);
        set("combat_exp", 6000000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("painting", 300);
        set_skill("force", 400);
        set_skill("wuzheng-xinfa", 400);
        set_skill("dodge", 400);
        set_skill("piaoyibu", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("wuyun-jian", 400);
        set_skill("literate", 130);
	set_skill("kuihua-xinfa", 400);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "wuyun-jian");
        map_skill("sword", "wuyun-jian");
        set_skill("pomopima-jian",400);
	map_skill("force", "pomopima-jian");
	map_skill("sword", "pomopima-jian");
        create_family("梅庄", 1, "庄主");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

        setup();
        carry_object("/clone/weapon/changjian")->wield();

}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
        if(who) {
		message_vision("$N叹道：江湖上真是长江后浪推前浪，我老了，老了，江湖中的事我也不再插手了。\n" NOR,this_object());
	}
	destruct(this_object());
}