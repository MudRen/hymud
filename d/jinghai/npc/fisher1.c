inherit NPC;
 
void create()
{
        set_name("����", ({"fisher man",}));
        set("long", "����һλ�����������õ�����ͷ�ӡ�\n");
        set("gender","����");

        set("chat_chance",2);
        set("chat_msg",({
        "����̾��������������Ϳ�����Ϊ����.....�뱲������\n"
}));
        set("age",59);
        set("con",30);
        set("str",20);
      
        set_skill("dodge",10);
        set_skill("parry",10);
        set_skill("unarmed",10);

        set("combat_exp",1000+random(1000));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}


