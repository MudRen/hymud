inherit NPC;

void create()
{
        set_name("����ˮ��", ({"bai yong","yong"}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","������");

        set("age",25);
        set("con",30);
        set("str",20);
        set("max_qi",500);
        set("max_jing",500);
        set("max_sen",500);

        set_skill("dodge",50);
        set_skill("demon-blade",50);
        set_skill("parry",50);
        set_skill("unarmed",50);
        set_skill("blade",50);
 
        set("combat_exp",100000+random(10000));
 
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

