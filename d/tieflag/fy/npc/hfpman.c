 // hfpman.c
inherit NPC; 
void create()
{
        set_name("���", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "�����̻��\n"); 
        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
}     
