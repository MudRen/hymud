 // lady.c
inherit NPC; 
void create()
{
        set_name("ǧ��С��", ({ "lady" }) );
        set("long", "һ�����λ����ĸ��������������ϵ�Ĥ������\n");
        set("age", 32);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("chat_chance", 1);
        set("chat_msg", ({ 
        }) );
        setup();
        carry_object(__DIR__"obj/lady_dress")->wear();
        carry_object(__DIR__"obj/silver_clasp")->wear();
        add_money("coin", 10);
}       
