// shinv.c from mool

inherit NPC;
 
void create()
{
        set_name("��ׯ�Ҷ�", ({"jia ding",}));
        set("long", "һλ���δ�,Ũü����.�����ɨ�������ܡ�\n");
        set("gender","����");
        set("title","����ɽׯ");

       set("chat_chance",2);
        set("chat_msg",({
        "�Ҷ�̾�˿�����:�Ҽ�����Ϊ����ֱ!�벻��ȴ�ܵ���������ų⡣\n"
}));
        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("demon-blade",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);
create_family("������", 3, "����");
        set("combat_exp",100000+random(30000));

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

