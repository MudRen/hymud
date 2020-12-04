#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 6500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_neili",4000);
        set("neili",4000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        

        set_name("司晨客",({"sichen"}));
           set("title",HIG"十二星象"NOR);
        set("long", "“十二星相“中的“鸡“。此人身长赫然在九尺开外，高大魁伟，黄衣黄
冠，那满脸全无表情的横肉，看来比铁还硬。\n");
        
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
}  
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}  
void greeting(object ob) {
        
        object *inv;
        int i, got_mask;
        
        if( !ob || environment(ob) != environment() ) return;
        
        inv =all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query("xianguo_mask") && inv[i]->query("equipped")=="worn") 
                got_mask=1;
        }
        
        if (got_mask)
                message_vision(CYN"$N说：老三，你到这儿来干什么？\n"NOR,this_object());
        else    message_vision(CYN"$N冷冷地说：自己滚出去，还是被抬出去？\n"NOR,this_object());
}  
