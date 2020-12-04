inherit NPC;
 
void create()
{
        set_name("年轻船夫", ({"shui shou",}));
        set("long", "一位肤色黝黑的青年男子,昂有挺胸，一副无所谓拒的样子。\n");
        set("gender","男性");
        set("title","靖海派弟子");
	set("chat_chance",1);
        set("chat_msg",({
        "船夫振臂高喊：一，二，一，二。\n"
}));

        set("age",25);
        set("con",30);
        set("str",30);
        set("max_qi",1200);
        set("max_jing",1200);
        set("max_sen",1200);

        set_skill("dodge",100);
        set_skill("demon-blade",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("chilian-shenzhang",200);
        set_skill("doomsword",200);
create_family("靖海派", 3, "水手");
        set("combat_exp",250000);
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

