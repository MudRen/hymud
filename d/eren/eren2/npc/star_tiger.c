#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 5000000);
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
        

        set_name("白山君",({"yunliang"}));
           set("title",HIG"十二星象"NOR);
        set("long", "“十二星相“中的“虎“，身上穿着件五色斑斓的锦衣，面色黝黑，满脸
虹须如铁，一双眼睛更是神光炯炯，令人不敢逼视。。\n");
        set("gender","男性");
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
}     
