
// b_header.c
//modified by ttf

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�½���", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "������");
        set("gender", "����" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "����ͷ");

		set("long",@LONG
    �½�����ʮ����ǰ��������Զ�ھ֣�ƾ��һ�ִ�����⵶����Զ��
����Щ��ͷ������ھֵ����⻹����ԡ�
LONG);

//        create_family("��Զ�ھ�", 1, "��ͷ");

        set("combat_exp", 600000);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 100);
        set_skill("dodge", 60);
        set_skill("blade", 100);
        set_skill("force", 20);
        set_skill("literate", 40);



        set("inquiry", ([
                "��Զ�ھ�" :
"�����������������Ʒ�ɽ�Ż�������Ҳ�������ԷƱ���\n",
				"name": "�����ճ£��˳�������\n",
				"������": "�����ϵĵ��ֿ��������¾���ô�п��ˣ�ʵ���ǲ�����\n",
				"������":
"Ŷ? ������ʦ��, �����˼��ھ���... ������? �Ȱ���"
"�����ǲݰ�? \n",
			"���ǲ�": "����������һ���ɣ� ���� �ǲ�������....\n",

		]) );

		setup();
        carry_object("/clone/misc/cloth")->wear();
		carry_object("/clone/weapon/gangdao")->wield();
}

