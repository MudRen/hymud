 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("卖菜的", ({ "caifan" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "老二哥");
        set("chat_chance", 3);
        set("chat_msg", ({
                "卖菜的笑道：那一着天外飞仙，七搏一赌叶孤城胜．．\n",
        }) ); 
        set("vendor_goods", ({
                __DIR__"obj/smallvege",
                __DIR__"obj/bigvege",
                __DIR__"obj/midvege",
                __DIR__"obj/tomato",
                __DIR__"obj/cucumber", 
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        add_action("do_buy", "buy");add_action("do_list", "list");
} 