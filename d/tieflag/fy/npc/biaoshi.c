 inherit NPC;
void create()
{
        set_name("��ʦ", ({ "biaoshi", "bian"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�ߴ����ߵ���ʦ��\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
        set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ʦ�ֽ����е�ʯ��һ�����������߰�ʮ�¡�\n",
                "��ʦ�������Լ���׳�ĸ첲�����������£�����¶������֮ɫ��\n",
        }) );
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object(__DIR__"obj/stonehammer")->wield();
}       
