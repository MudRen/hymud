 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name(HIY"�����ʿ"NOR, ({ "golden soldier","soldier"}) );
        set("title",RED"��������"NOR);
        set("gender", "����" );
        set("age", 30+random(20));
        set("long",
                "�ɰ˵ĺ��ӣ��ֳ���ꪣ������ں�ձ���ԣ��ƹ�ӳ��ꪣ����������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("str",40);
        set("attitude", "friendly");
        set("class","shaolin");
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",110+random(50));
        set("mana",800);
        set("max_mana",800);
        
        set_skill("spear", 900);

        set_skill("dodge",200);
        set_skill("dodge",200);
        set_skill("force",200);

        
        set("resistance/gin",40+random(60));
        set("resistance/kee",40);
        set("resistance/sen",40);
        set("no_busy",10); 
        setup();
   
        carry_object(__DIR__"obj/g_armor")->wear();
        carry_object(__DIR__"obj/g_spear")->wield();
}     
