inherit NPC;
 
void create()
{
        set_name("Ӥ��", ({"baby",}));
        set("long", "һ��ü��Ŀ���С���ӡ�\n");
        set("gender","����");

        set("age",6);
        set("con",30);
        set("str",10);
 
        set("combat_exp",100+random(100));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

