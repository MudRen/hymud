inherit NPC;
 
void create()
{
        set_name("����", ({"pu ren",}));
        set("long", "һλ��������������,����ͷ������վ�����\n");
        set("gender","����");
        set("title","����ɽׯ");

        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",100);
        set_skill("demon-blade",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("blade",100);
create_family("������", 3, "����");
        set("combat_exp",10000+random(10000));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

