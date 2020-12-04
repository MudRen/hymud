#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("丁灵琳",({"ding linglin","ding","linglin"}));
        set("title","要命的");
        set("long","她穿着件轻飘飘的月白衫子，雪白的脖子上，戴着个金圈圈，金圈圈上还挂着两枚
金铃裆。她手上也戴着个金圈圈，上面有两枚金铃裆，风吹过的时候，全身的铃裆就“叮铃铃”
的响。。\n");
        set("gender","男性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
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
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
        set("chat_chance",1);
        set("chat_msg",({
                "丁灵琳笑得花枝招展，全身的铃裆也开始“叮铃铃”的直响。\n",
                "丁灵琳笑了。她笑起来的时候，身上的铃档又在“叮铃铃”的响，就像她的笑声一样清
悦动人。\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     
