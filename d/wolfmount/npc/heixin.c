#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("黑心狼", ({"heixin wolf","heixin"}) );
        set("gender", "男性" );
        set("nickname", HIB"夜狼"NOR);
        set("long", "黑衣、黑鞋、黑巾蒙面，在夜色下眼睛诡异地闪着绿色的光。。\n");
        set("attitude", "friendly");
/*      set("max_jing", 1100);
        set("max_qi", 1100);
        set("max_jing", 1100); */
    set("age", 35);
//    set("str", 30);
    set("cor", 25);
    set("cps", 25);
        set("combat_exp", 1100000);
    set_temp("apply/damage", 60);
    set_temp("apply/armor", 60);
    set("force", 1000);
    set("max_neili", 1000);
    set("force_factor", random(60));
        create_family("狼山", 1, "第四代弟子");
set("max_qi", 13500);
	set("max_jing", 11500);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 150);

	set("combat_exp", 5900000);
	set("score", 800000);
    set_skill("cuff", 300);
    set_skill("strike", 100);
    set_skill("qingfu-shenfa", 100);
    set_skill("hanbing-mianzhang", 100);
    set_skill("sougu", 100);
    	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("sword", 140);
	set_skill("blade", 140);
	set_skill("parry", 140);
	set_skill("cuff", 200);
	set_skill("blade", 140);
	set_skill("jinwu-daofa", 140);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 140);
    	set_skill("damo-jian", 140);
    	set_skill("qishang-quan", 380);
    	set_skill("hunyuan-zhang", 150);
    	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
		(: command("perform youyouhunduan") :),


	}) );
        set("chat_chance", 1);
        set("chat_msg", ({
        "黑心狼仰天长嚎：狼山武功甲天下，夜狼武功甲狼山！\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/langyabang")->wield();
        carry_object(__DIR__"obj/blkcloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "wolfmount")
        {
                message_vision("$N冷冷的看着你：“想上狼山，你没有机会了。”\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}    
