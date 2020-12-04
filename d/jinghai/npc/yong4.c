inherit NPC;
 
void create()
{
        set_name("紫衣侍卫", ({"zi yi"}));
        set("long", "一位面容娇秀的年轻姑娘，她持剑站立着。\n");
        set("gender","女性");
        set("title","靖海派");

        set("age",19);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",100);
        set_skill("demon-blade",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("blade",100);
 
        set("combat_exp",50000+random(10000));

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

