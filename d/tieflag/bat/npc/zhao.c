 // zhao.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�Ը�", ({ "zhao", "zhao gang" }) );
        set("title", HIY "���ƿ���" NOR);
        set("gender", "����" );
        set("class", "wudang");
        set("age", 42);
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set("str",40);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",110);
        
        set("long",
"
���������ƿ����Ըգ��书֮ǿ���ѿ����ǽ����е�һ������,
����Ӳ������ǿ�Ĵ�ˤ���֡�
\n"
    ); 
        set("attitude", "peaceful");
        set_skill("unarmed", 200);

        set_skill("dodge",200);
        set_skill("parry",200);

        set_skill("dodge",200);
        

        
        set("resistance/gin",40+random(60));
        set("resistance/kee",40);
        set("resistance/sen",40);
        
   set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.bazhentu" :),
                }) ); 
                        
        set("combat_exp", 4800000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        if (!random(10)) carry_object(__DIR__"obj/unarmedbook");
}     
