#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",80);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "胡药师心满意足地微笑着。\n"
        }) );
        

        set_name("胡药师",({"hu yaoshi"}));
//      set("title",HIG"十二星象之"NOR);
   set("long", "“十二星象“中的“捣药神君“，白发苍苍，但颔下胡子却没有几根，一双眼睛又
圆又亮，就像是两粒巨大的珍珠。不但头大，耳朵更大，而且又大又尖，和兔子的
耳朵几乎完全一摸一样，只不过大了两倍。\n");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/spader")->wield();
}    
