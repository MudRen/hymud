// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"yun xiao", "yun"}));
        set("gender", "����" );
        set("age", 33);
        set("long",
"����ɽ���Ƕ������������еĽܳ����
�ڳ���ת��תȥ��Щ��ɧ��\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("����ɽ���Ƕ�", 3, "����");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
      
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "�������˸����磮\n",
            "�����������´������㼸�ۡ�\n",
	    "��������һ����\n"
        }) );
}

�
