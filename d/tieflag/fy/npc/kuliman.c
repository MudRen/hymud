 // kuliman.c
inherit NPC; 
void create()
{
        set_name("����", ({ "kuliman" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "��������Ϊ�¶ٷ�������. \n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set("chat_chance", 25);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
}    
