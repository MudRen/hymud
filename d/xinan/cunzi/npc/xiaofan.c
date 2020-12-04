
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小贩", ({ "xiao fan","fan" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long",
          "这是个临近山上的小贩，到各个村子叫卖些山货和生活用品。\n"
        );
        set("combat_exp", 4000);

        set("chat_chance", 1);
        set("chat_msg",({
"我这里有各种药材，都是新鲜的。买一点吧\n",
"我这里您想要的各种生活用品全有，买点什么?\n",
        }) );
        set("talk_limit",([
            "social_exp" : 200,
            "age"        : 15,
        ]));
        set("talk_msg",({
"山里多雨，爱潮，您买点姜加上糖熬成姜汤可以去寒.\n",
"姜如果和萝卜一块煮可以大补呢.\n",
        }));
	set("vendor_goods", ({
		 __DIR__ "obj/jiang",
		__DIR__ "obj/chaidao",
		__DIR__ "obj/lajiao",
		__DIR__ "obj/gouqi",
		__DIR__ "obj/wine",
		__DIR__ "obj/yougao",
		__DIR__ "obj/bag",  
		"/d/city/npc/obj/baozi",								
	}));


        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}
void init()
{
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

