#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("焦老大",({"jiao laoda","jiao","laoda"}));
//      set("title","要命的");
        set("long","焦老大是马师中年纪最长的一个。他这一生，几乎全都是在万马堂度过的，他已
将这一生最宝贵的岁月，全都消磨在万马堂中的马背上。现在他双
腿已弯曲，背也已有些弯了，一双本来很锐利的眼睛已被劣酒泡得发红。
每当他睡在又冷又硬的木床上抚摸到自己大腿上的老茧时，他也会想到别
处去闯一闯。可是他已没有别的地方可去，因为他的根也生在万马堂。
。\n");
        set("gender","男性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
             
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}
