inherit NPC;
 
void create()
{
        set_name("��Ů", ({"shi nv",}));
        set("long", "����һλ�������ش��˼ҵ�Ѿ�ߡ�\n");
        set("gender","Ů��");
        set("title","��ȸ��");

        set("chat_chance",5);
        set("chat_msg",({
        "��Ů���������ô�ɨ�ŷ��䡣\n"
}));
        set("age",19);
        set("con",30);
        set("str",20);
        set("max_qi",500);
        set("max_jing",400);
        set("max_sen",500);

        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",50);
        set_skill("literate",10);

        set("combat_exp",50000+random(20000));

        setup();
        carry_object(__DIR__"obj/saozhu")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

