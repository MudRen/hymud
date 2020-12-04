#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("马夫",({"labor",}));
        set("long","驿站里的马夫，地位虽然低微，却是关系到驿站声誉的差使。\n");
        set("gender","男性");
        set("int",22);
        set("cor",30);
        set("cps",20);
        
        set("combat_exp",1500000);  
        set("attitude", "friendly");
        

        set_skill("parry",200);
        set_skill("dodge",200);
        
        set("inquiry", ([
                "饲料整理" :    "拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n\n",
                "饲料" :        "拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n\n",
                "整理饲料":     "拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n",
        ]));
        
        set("death_msg",CYN"\n$N说：你完了，等着杀头吧。。 \n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n马夫叫道：来人啊，杀人啦！！！\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "马夫手忙脚乱地打扫着马房，嘴里不情不愿地嘟囔着。\n",
                "马夫说：“谁能帮我把这些饲料整理一下呢？”\n",
                "“～～～～咴～～～～咴～～～～”\n",
                
        }) );                   
           
        
        setup();
        carry_object(__DIR__"obj/ycloth")->wear();      
        carry_object("/d/taiping/obj/brokenrake")->wield();
}     
