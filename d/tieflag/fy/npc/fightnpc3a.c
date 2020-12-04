#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
void auto_smart_fight();
object *resort_enemy(); 
void ask_help();
void magic_fight();
void do_defense(int n);
void do_remove_defense(int n);
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{ 
         set_name("智能长老beta三代",({"fighter"}));
        set("title",YEL"探花楼"NOR);
        set("long", "这是探花楼用来愉悦客人的幻象，与一代相比，气血减少，力量降低，但技能
种类增加，能够在战斗中更换武器和技能，能够与同伴配合作战。\n");
        set("str",45);
        set("force_factor",100);
        set("age",30+random(20));
        set("combat_exp", 5500000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        
        
        set("no_fly",1);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi; 
        
        set("defense_type",random(4)+1);        
        set("zombie-killer",1);
   set("officer-killer",1); 
        setup();

        
        carry_object("/clone/misc/cloth")->wear();
} 
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N惨叫一声倒了下去，化作一阵轻烟消失了。\n"NOR,this_object());     
        destruct(this_object());        
}     
