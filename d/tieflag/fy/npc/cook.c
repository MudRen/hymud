 // worker.c
inherit NPC; 
void create()
{
        set_name("��ʦ", ({ "cook" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һ�����ֵĵĳ�ʦ. \n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("sword",30);
        set("chat_chance", 35);
        set("chat_msg", ({
                (:random_move :)
        }) ); 
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
} 
