 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name(HIC"������ʿ"NOR, ({ "silver soldier","soldier"}) );
        set("title",RED"��������"NOR);
        set("gender", "����" );
        set("age", 30+random(20));
        set("long",
                "�ɰ˵ĺ��ӣ��ֳ���ꪣ������ں�ձ���ԣ��ƹ�ӳ��ꪣ����������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 3500000);
        set("attitude", "friendly");
        set("class","shaolin");
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",70);
        set("mana",800);
        set("max_mana",800);
        
        set_skill("spear", 150);
        set("force_factor",100+random(60));
        set_skill("dodge",150);
        set_skill("dodge",200);
        set_skill("force",200);

        set_skill("parry",150);
        

        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        set("no_busy",4); 
        setup();
        
   carry_object(__DIR__"obj/s_armor")->wear();
        carry_object(__DIR__"obj/s_spear")->wield();
} 
