// bfighter.c

inherit NPC;

void create()
{
        set_name("������", ({ "tangzi shou" }) );
        set("gender", "����" );
        set("age", 38);
        set("str", 25);
        set("cor", 27);
        set("int", 23);
	set("max_kee",700);
        set("max_force", 300);
        set("force", 300);
        set("force_factor", 10);

        set("pursuer", 1);
        set("env/wimpy", 30);

        set("long",@LONG
����һλ�����ھֵ������֣������ھֵĻ�������
LONG);

        set("combat_exp", 40000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ֺ����������ھ�..., ʢ��Զ��...\n",
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "�����ֺ��������㳢���ҵ�������\n",
                "�����ֽе��������ھֿɲ��Ǻ��ǵģ�\n"
                "�����ִ�У���һ��Ҫɱ���㣬���ھ�������\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("blade", 50);
        set_skill("force", 20);
        set_skill("literate", 10);


        setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}