 // horseman.c
inherit NPC; 
void create()
{
        set_name("������ϰ�", ({ "horseman" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "������ϰ�\n"); 
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("sword",80);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 2);
        carry_object("/clone/misc/cloth")->wear();
        
} 
