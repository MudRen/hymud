 // wander.c
inherit NPC; 
void create()
{
        set_name("��å", ({ "wander" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����å�½�볨�������һ��ձñ������һ˫�Ʋ�Ь����������\n"
        "���´�������ü���ۣ��������⡣\n"); 
        set("combat_exp", 5000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
} 
