// modified by vikee
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;
inherit F_MASTER;
int ask_me();
int recruit_apprentice(object ob);
int attempt_apprentice(object me);
int do_report();

void create()
{
        set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","��ɽ�������ŵ���");
        set("long", 
"����ң��Ľ��ݣ�����Ũü���ۣ������Ѱ���\n");
        set("gender", "����");
        set("age", 18);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2800);
        set("max_kee", 2800);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 4800);
        set("max_force", 2400);
        set("mana", 4800);
        set("max_mana", 2400);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);


        set("inquiry", ([
                "�����" : "���ܰ���ȥ��������ҿɻᱨ����ģ�\n",
                "���ʿ" : "�þ�û��ʦ���ˣ�\n",


        ]));
        setup();
        create_family("��ɽ����", 5, "δ���ŵ���");
        carry_object("/clone/misc/cloth")->wear();
         carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

