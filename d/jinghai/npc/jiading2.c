//jiading1.c from mool

inherit NPC;
 
void create()
{
        set_name("Ѳ�߼Ҷ�", ({"jia ding",}));
        set("long", "һλ���δ�,Ũü����.�����ɨ�������ܡ�\n");
        set("gender","����");
        set("title","����ɽׯ");

        set("chat_chance",5);
        set("chat_msg",({
        "�Ҷ�̾�˿�����:�Ҽ�����Ϊ����ֱ!�벻��ȴ�ܵ���������ų⡣\n"
}));
        set("age",45);
        set("con",30);
        set("str",50);
        set("max_qi",2200);
        set("max_jing",2200);
        set("max_sen",2200);

        set_skill("dodge",290);
        set_skill("demon-blade",290);
        set_skill("parry",290);
        set_skill("unarmed",290);
        set_skill("blade",290);
create_family("������", 3, "����");
        set("combat_exp",1000000+random(30000));

        setup();
        set("chat_chance", 20);
        set("chat_msg",({
        (: random_move :)
}) );

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

