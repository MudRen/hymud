 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("王胖子",({"seller","xiaofan"}));
        set("title","山西七义");
        set("long","一个笑意盈盈，肥头大耳的面贩子。\n");
        set("gender","男性");
        set("age",33);
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("per",30);
	set("vendor_goods", ({
                   __DIR__"obj/daomian", 
                   __DIR__"obj/bomian", 
                   __DIR__"obj/lamian", 
	}));
         set("class","beggar");
         
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",1);
                        
    
       // set("chat_chance_combat", 1);
        set("chat_chance",1);
        set("chat_msg",({
                "王胖子擦了擦手上的面粉，似乎从上面能刮下一层油。\n",
                //  (: random_move :),
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

void reset()
{
        set("vendor_goods", ([
            "/d/chenxiang/npc/obj/caomian":10, 
                "/d/chenxiang/npc/obj/miantiao":10, 
                "/d/biancheng/npc/obj/cow1":10, 
                __DIR__"obj/daomian":10, 
                   __DIR__"obj/bomian":10, 
                   __DIR__"obj/lamian":10, 
                 
        ]) );
} 