 // zhtman.c
inherit NPC; 
void create()
{
        set_name("�����ϰ�", ({ "zhtman" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һ�������ϰ�\n"); 
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("sword",50);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
} 
