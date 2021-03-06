inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("赵之玄", ({ "master zhao", "master", "zhao" }) );
        set("class","jinghai");
        create_family("靖海派", 2, "弟子青龙堂堂主");


        set("gender", "男性" );
        set("age", 30);
        set("attitude", "peaceful");

        set("long", "皮盔竹甲，身形高大，一副武将打扮。
他就是靖海派祖师的三弟子。\n");

        set("combat_exp", 2000000);
        set("str", 50);
        set("per", 29);
        set("max_qi",2200);
        set("qi",2200);
        set("max_jing",2200);
        set("jing",2200);
        set("max_sen",2200);
        set("sen",2200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("atman", 2800);
        set("max_atman", 2800);
        set("mana", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);


        set_skill("jingyiforce",200);
        set_skill("demon-blade",200);
        set_skill("literate",255);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("doomsword",220);
        set_skill("chilian-shenzhang",240);
        set_skill("softsword",220);
        set_skill("nine-moon-sword",205);
        set_skill("luohua-jian",200);
        set_skill("sword",200);
        set_skill("feixian-sword",200);
        set_skill("bat-blade",200);
        set_skill("fengyu-piaoxiang",220);

        map_skill("force","jingyiforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","nine-moon-sword");
        map_skill("sword","nine-moon-sword");

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
 
}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "女性")
        {
                command("say 我不收女弟子，你去问问我的师姐们吧。");
                command("say 我在忙着操练水勇，没空授徒。");
                return;
        }




                command("smile");
                command("say 不错，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
                command("recruit " + ob->query("id") );

}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

