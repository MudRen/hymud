inherit NPC;
 
void create()
{
        set_name("����Ů��", ({"girl"}));
        set("long", "һ��������ɫ���µ�����Ů�ӡ�\n");
        set("gender","Ů��");

        set("age",26);
        set("con",30);
        set("str",25);
        set("per",25);
        set("kar",25);
 
        set("combat_exp",10000+random(1000));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

