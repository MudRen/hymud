 inherit NPC;
void create()
{
        set_name("������", ({ "tang", "tang zishou"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��̬��ӯ�������֡�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move",800);
        set_skill("changquan",100);
        map_skill("unarmed","changquan");
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˵��������������⵶ͷ����Ѫ�����ӡ���\n",
                "������˵�����⼸��·�ϲ�̫ƽ��ǧ��Ҫ���²źá���\n",
                "������˵�������ӱ�����ô���꣬��ûɱ�����ء���\n",
        }) );
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
}   
