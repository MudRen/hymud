 // kuliman.c
inherit NPC; 
void create()
{
        set_name("���", ({ "huoji" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "������������æ���ҵ����ڳ���װ�ػ���. \n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set("chat_chance", 25);
        setup();
        add_money("coin", 1);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        
}    
