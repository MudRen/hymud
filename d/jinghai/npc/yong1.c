// yong.c from mool

inherit NPC;
 
void create()
{
        set_name("���ˮ��", ({"shui yong",}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","����կ");

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

        set("combat_exp",100000+random(30000));

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

