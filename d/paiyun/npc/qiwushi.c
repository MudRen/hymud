// zhao.c ��־��
// By Lgg,1998.10

inherit NPC;

void create()
{
        set_name("��־��", ({"qz dizi", "qzdizi"}));
        set("gender", "����");
        set("age", 26);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֡� \n"
                "����ò��������ü����ƺ�������һ˿�ƻ�����ɫ��\n"
		"����һ��������ˣ�������ȴ��Щɷ����\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianzhen" :),
                (: perform_action, "sword.jianqi" :),
        }));

        set("qi", 15500);
        set("max_qi", 15500);
        set("jing", 18000);
        set("max_jing", 18000);
        set("neili", 13000);
        set("max_neili", 13000);
        set("jiali", 60);

        set("combat_exp", 560000);
        set("score", 100000);
set_skill("qixing-jian",190);
set_skill("qixing-shou",190);
set_skill("qixing-array",180);
set_skill("hand", 199);
        set_skill("force", 80);
        set_skill("xiantian-qigong", 80);    //��������
        set_skill("sword", 80);
        set_skill("quanzhen-jian",180);  //ȫ�潣
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);   //���㹦
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 80);    //�����
        set_skill("literate",60);
        set_skill("taoism",60);
set_skill("array",190);
set_skill("qixing-array",190);
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );
          set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
               setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

