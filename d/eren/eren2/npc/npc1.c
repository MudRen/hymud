#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"��絶"NOR,({"guardian"}));
        set("title",YEL"���˿�����"NOR);
        set("long", "����һλ���˿�ר�ŵ���Ѳ��֮��ĵ��ӡ�\n");
        set("age",30+random(20));
//      set("attitude", "aggressive");
        set("combat_exp", 5000000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",60);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        

        setup();
        
        carry_object(__DIR__"obj/g_armor")->wear();
}         
