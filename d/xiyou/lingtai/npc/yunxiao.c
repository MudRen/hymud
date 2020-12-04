// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云霄", ({"yun xiao", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long",
"方寸山三星洞第三代弟子中的杰出人物。
在场边转来转去发些牢骚。\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 3, "弟子");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
      
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "云霄打了个喷嚏．\n",
            "云霄上上下下打量了你几眼。\n",
	    "云霄哼了一声。\n"
        }) );
}

�
