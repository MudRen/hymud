// yun.c

inherit NPC;
#include <ansi.h>;
void create()
{

	set_name("云中鹤", ({ "yun zhonghe", "yun" }));
	set("gender", "男性");
	set("nickname", HIY"穷凶极恶"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "此人长得又高又瘦象一杆大竹竿，说话声音忽尖忽粗，十分难
听，穿着一身青衫，一副色迷迷模样。\n");
	set("combat_exp", 150000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 10000); 
	set("max_qi", 10000);
	set("max_neili", 10000);
	set("jiali", 50);

	set_skill("strike", 180);
	set_skill("claw", 180);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("chousui-zhang", 180);
	set_skill("huagong-dafa", 180);
	set_skill("shaolin-shenfa", 180);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("parry", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}                     