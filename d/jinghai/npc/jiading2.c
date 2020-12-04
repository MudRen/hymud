//jiading1.c from mool

inherit NPC;
 
void create()
{
        set_name("巡逻家丁", ({"jia ding",}));
        set("long", "一位彪形大汉,浓眉大眼.警惕的扫视这四周。\n");
        set("gender","男性");
        set("title","靖海山庄");

        set("chat_chance",5);
        set("chat_msg",({
        "家丁叹了口气道:我家主人为人正直!想不到却受到门派里的排斥。\n"
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
create_family("靖海派", 3, "弟子");
        set("combat_exp",1000000+random(30000));

        setup();
        set("chat_chance", 20);
        set("chat_msg",({
        (: random_move :)
}) );

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

