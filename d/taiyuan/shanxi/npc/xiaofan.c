 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("卖肉包子的小贩",({"waiter","xiaofan"}));
        set("title","山西七义");
        set("long","一个喜欢翻白眼、用包子打狗的小贩。\n");
        set("gender","男性");
        set("age",33);
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("per",30);
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
         set("class","beggar");
         

        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",1);
                        

       // set("chat_chance_combat", 1);
        set("chat_chance",1);
        set("chat_msg",({
                "小贩瞪眼道：“你知不知道肉包子本来就是用来打狗的。”\n",
                 // (: random_move :),
        }) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/biandan")->wield();  
} 
void init()
{       
   
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 

