inherit NPC;
void create()
{
        set_name("����ī��", ({ "wenren", "ren"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "����һλС�вŻ������ˣ�����׷����С�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
        set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������ſڣ��ֺ����ˡ�\n",
                "ī��������ȥ���ƺ����ڴ򸹸塣\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object("/clone/misc/cloth")->wear();
}        
