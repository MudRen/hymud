 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("药店小伙计", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 15);
        set("long",
"这小伙计个子不高，脸色红红的，一笑的时候就露出一排洁白的牙齿。
\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("per",23);
	set("vendor_goods", ({
                __DIR__"obj/astragalt",
                __DIR__"obj/dioscoreae",
                __DIR__"obj/codonopsis",
                __DIR__"obj/pilosulae",
                __DIR__"obj/lycii",
	}));
        set("inquiry", ([
                "当归补血鱼汤" : "哟，这你可要问老板了。\n",
                "soup" : "哟，这你可要问老板了。\n",
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
		add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
command("say 哟，你受伤了！没钱买药么？\n");    
                        break;
        }
} 
int accept_object(object me, object obj)
{
        command("say 多谢这位" + RANK_D->query_respect(me) + "\n");     
        return 1;
} 
