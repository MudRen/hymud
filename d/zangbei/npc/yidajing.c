#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("易大经",({"yi dajing","yi","dajing"}));
        set("title","铁手君子");
        set("long","一个穿着孝服的男人。他哭得很伤心。他将桌上的纸人纸马纸刀拿下，点起了火，眼睛里还在流
泪。\n");
        set("gender","男性");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
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
         

        set("chat_chance",1);
        set("chat_msg",({
//              "李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
        }) );                   
         
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}
