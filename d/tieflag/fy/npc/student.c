 inherit NPC;
void create()
{
        set_name("����", ({ "student", "sheng"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "����һλ���ڿ��ԵĿ�����\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
        set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����̧��ͷ����������һ�ۣ�����\n",
        }) );
        
        setup();
        add_money("coin", 1);
        carry_object(__DIR__"obj/fycloth")->wear();
}   
