inherit NPC;
 
void create()
{
        set_name("����ĺ���", ({"fisher boy","boy"}));
        set("long", "����һλ������������С���ӡ�\n");
        set("gender","����");

        set("chat_chance",2);
        set("chat_msg",({
        "С����˵�����ҵ�������Ϳ�����Ϊ����.....��Ҳѧ���˵㡣\n"
}));
        set("age",15);
        set("con",30);
        set("str",20);
      
        set_skill("dodge",10);
        set_skill("parry",10);
        set_skill("unarmed",10);

        set("combat_exp",500+random(100));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}


