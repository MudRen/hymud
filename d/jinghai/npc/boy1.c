inherit NPC;
 
void create()
{
        set_name("渔民的孩子", ({"fisher boy","boy"}));
        set("long", "这是一位衣着破破烂烂小孩子。\n");
        set("gender","男性");

        set("chat_chance",2);
        set("chat_msg",({
        "小孩子说道：我爹在这里就靠打渔为生，.....我也学会了点。\n"
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


