 inherit NPC;
#include <ansi.h>  
void create()
{
        object armor;
        set_name("�ϻ���", ({ "old gardener","gardener"}) );
        set("gender", "����" );
        set("age", 60+random(10));
        set("long",
                "һ����̬���ӵĻ��������ڸ�����Ļ�����ľ��ˮ��֦��\n");
        set("attitude", "friendly");
        set("class","wudang");  
        set("combat_exp", 2700000);
        set("cor",40);
        set("cps",30);
        set("neili",800);
        set("max_neili",800);
        set("force_factor",50);
        
        set_temp("xinyoulingxi", 1);
        set("marks/�����Ϭ",1);       
        
        set_skill("dodge",150);
        set_skill("dodge",150);
        set_skill("force",120);

        set_skill("sword",150);
        set_skill("taiji-jian",160);
        set_skill("parry",170);

        

        map_skill("sword", "taiji-jian");
        map_skill("parry","taiji-jian");

        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
   setup();
        
        armor=new("/clone/misc/cloth");
        armor->set_name(RED"���۷�"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object(__DIR__"obj/b_scissor")->wield();
}     
