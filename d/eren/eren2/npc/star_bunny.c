#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
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
                "��ҩʦ���������΢Ц�š�\n"
        }) );
        

        set_name("��ҩʦ",({"hu yaoshi"}));
//      set("title",HIG"ʮ������֮"NOR);
   set("long", "��ʮ�������еġ���ҩ��������׷��Բԣ�����º���ȴû�м�����һ˫�۾���
Բ�����������������޴�����顣����ͷ�󣬶�����󣬶����ִ��ּ⣬�����ӵ�
���伸����ȫһ��һ����ֻ��������������\n");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/spader")->wield();
}    
