#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 5000000);
        set("dungeon_npc","eren2");
        set("no_shown",1);      
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
        

        set_name(HIW"��צ"NOR,({"jizhua","��צ"}));
//         set("title",HIG"ʮ������"NOR);
        set("long", "��ʮ�����ࡰ�С��������������ࡣ\n");
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}      
