// worker.c

inherit NPC;
void create()
{
        set_name("�Է�", ({ "qiao fu", "fu" }) );
        set("gender", "����" );
        set("age", 33);
        set("per", 30);
        set("long", "һλ��ɫ��ڣ�ϲ��������Է�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set_skill("axe", 20);
        set("chat_chance",15);
        set("chat_msg",({
                "ֻ���Է򳪵����Ƽ������Ͼ��֣����»Ĳ�·��Ѱ��\n",
                "�Է򳪵�����ɽ���������꣬�Ͻ���ʱ�ɴ��\n",
                "�Է򳪵���������ã���ľ�������Ʊ߹ȿ����У���н���ƣ���Ц�����顣\n",
                "�Է������������괦�����ɼ�������������ͥ��\n",
                (:random_move:)
        }));

        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "�Է�е���ɱ���ģ�ɱ���ģ�\n",
                "�Է�е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 50);
        set("inquiry", ([
                "name": "��Ҷ����Ұ�ţ��ƽ����ɽ�����ʱҲ��Щľ����\n",
                "here": "������̨����ɽ����˵ɽ���и������ɣ�\n",
                "������": "�����ɳ�����������ʦ������ʦ��ȥ��ͽ�ܣ���������Ӣ�ۣ�\n",
        ]) );
        carry_object("/d/xiyou/lingtai/obj/axe")->wield();
}

