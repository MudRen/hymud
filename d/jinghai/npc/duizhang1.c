inherit NPC;
 
void create()
{
        set_name("�����ӳ�", ({"duei zhang","duei"}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","������");

        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("demon-blade",100);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);
 
	map_skill("blade","longjiao-blade");

        set("combat_exp",500000+random(30000));
 
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

