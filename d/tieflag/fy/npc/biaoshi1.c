 inherit NPC;
void create()
{
        set_name("������", ({ "tang", "zhi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��̬��ӯ�������֡�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
        set_skill("dodge", 100);
        set("chat_chance", 2);
        set("chat_msg", ({
                "����������һ�˶�ߵ�÷��׮����ϰ��һ�顣\n",
        }) );
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
}      
