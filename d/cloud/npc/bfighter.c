
// bfighter.c

inherit NPC;

void create()
{
        set_name("������", ({ "bfighter" }) );
        set("gender", "����" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 100);
        set("force", 800);
        set("force_factor", 10);

        set("pursuer", 1);

        set("long",@LONG
����һλ�ھֵ������֣������ھֵĻ�������
LONG);

//        create_family("��Զ�ھ�", 2, "������");

        set("combat_exp", 200000);
        set("score", 200);

        set("chat_chance", 20);
        set("chat_msg", ({
                "�����ֺ�������Զ�ھ�..., ʢ��Զ��...\n",
                (:random_move :)
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                "�����ֺ��������㳢���ҵ�������\n",
                "�����ֽе��������ھֿɲ��Ǻ��ǵģ�\n"
                "�����ִ�У���һ��Ҫɱ���㣬���ھ�������\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("blade", 50);
        set_skill("force", 20);
        set_skill("literate", 10);



        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}
