#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{
        set_name("伛偻老头",({"old bard","bard","oldman"}));
        set("title","说书的");
        set("long","伛偻老头今年已经七十多岁了，在边城以说书卖艺为生。岁月虽然已在他身上留下
了很多残酷的痕迹，这老人却没有低头，他的背虽已弯，行动己不太灵活，但是他
还是凭着自己的努力去赚取生活的费用。\n");
        set("gender","男性");
        set("age",72);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set_skill("unarmed",100);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",180);
        set_skill("move",200); 
        set_skill("music",300); 
        set_skill("magic",300); 
        
       map_skill("magic", "music");

        
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",90);
        set("max_atman",5000);
        set("atman",5000);
        set("max_mana",5000);
        set("mana",5000);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        set("death_msg",CYN"\n$N喉咙里咕咕几声，似乎想说什么，却终于没说出来。 \n"NOR);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n伛偻老头叫道：我这把老骨头跟你拼了！！！\n",
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                "伛偻老头拿起胡琴吱吱呀呀拉了几声唱道:“天皇皇，地皇皇。眼流血，月无光。
一入万马堂，刀断刃，人断肠！”\n",
                "伛偻老头接着唱道：“天皇皇，地皇皇。泪如血，人断肠。一入万马堂，休想回
故乡。”\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","fumostaff",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/erhu")->wield();  
    
}    
