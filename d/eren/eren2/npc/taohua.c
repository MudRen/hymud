#include <ansi.h>
#include <command.h>

inherit NPC;
//inherit NPC;   
void create()
{ 
        set_name("桃花娘子",({"taohua","niangzi","taohua niangzi"}));
        set("title",YEL"梅花庵主持"NOR);
        set("long", "看不出她脸上的表情，可是她眼睛里那种仇恨怨毒之色，还是无论谁都能看得出的。。\n");
        set("age",39);
        set("gender", "女性");
        set("combat_exp", 12000000);
         set("attitude", "aggressive");
             set("reward_npc", 1);
        set("difficulty", 35); 
        set("no_busy",9);
        set("class", "mei"); 
         set_skill("literate", 150);
    set_skill("force", 200);
    set_skill("spells", 280);
    set_skill("move", 200);

    set_skill("unarmed", 150);

    set_skill("sword", 200);
    set_skill("iron-cloth", 180);
    set_skill("parry", 160);
    set_skill("dodge", 200);
    
    

        setup();
    set_temp("apply/dodge", 200);
    set_temp("apply/armor", 300); 
    add_temp("apply/iron-cloth", 180);
    
        set_temp("xuanxinaomiao",1);

        
        set("max_atman", 2000);
        set("atman", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   
         

        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "叹了口气，又成了一个苍老干枯的老尼。\n", environment(),
                this_object() );
        another = new(__DIR__"liaoyin");
        another->move(environment(this_object()));
        destruct(this_object());
}     

void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/桃花娘子_ma", 1);
        }
        
        ::die(); 
}