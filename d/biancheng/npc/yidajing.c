#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("易大经",({"yi dajing","yi","dajing"}));
        set("title","铁手君子");
        set("long","阴暗的角落里，半趟着一个喘气不止的男人，阳光照不到他的脸，令他更显消沉。\n");
        set("gender","男性");
        set("age",42);
        set("reward_npc", 1);
        set("difficulty", 20);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
       set("class","wudang");
         set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_kee",50000);
        set("max_gin",99999);
        set("max_sen",99999);
        set("eff_qi",9999);
        set("qi",50000);

        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N喃喃自语说：“我是君子。。还是。。。永远是。。没人。。能改变。。。”\n"NOR);            
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
         set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.nianzijue" :),
             }) ); 
        set("chat_chance",1);
        set("chat_msg",({
//                "李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
        }) );                   
        
//           CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
      carry_object("/clone/weapon/gangjian")->wield();    
}   
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/易大经_ma", 1);
        }
        
        ::die(); 

}
