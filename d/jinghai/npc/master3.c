inherit NPC;
inherit F_MASTER;

string
*to_sleep = ({"southwest","southwest"}), /* 去睡觉的路径 */
*go_back = ({"northeast","northeast"}); /* 回去的路径 */

void create()
{
        set_name("邓彤", ({ "master tong", "master", "tong" }) );
        set("class","jinghai");
        create_family("靖海派", 2, "弟子");


        set("gender", "女性" );
        set("age", 25);
        set("attitude", "peaceful");

        set("long", "这是一位妖媚的年轻女子，她就是靖
海派的创始人夫妇的小女儿。\n");

        set("combat_exp", 1800000);
        set("str", 40);
        set("per", 21);
        set("max_qi",2000);
        set("qi",2000);
        set("max_jing",2000);
        set("jing",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 50);
       set("chat_chance",3);
        set("chat_msg",({
        "邓彤羞得满面通红道：这么多人看着，多不好意思！\n"
}));

        set_skill("jingyiforce",200);
        set_skill("demon-blade",200);
        set_skill("literate",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("doomsword",220);
        set_skill("chilian-shenzhang",220);
        set_skill("softsword",220);
        set_skill("nine-moon-sword",220);
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
	//call_out("do_setup",1);
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/jinghai/obj/key3")->wear();

}

void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "男性")
        {
                command("say 妾身不收男弟子，去问问我的师哥们吧。");
                return;
        }

        //command("shake");
        //return;


                command("smile");
                command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
                command("recruit " + ob->query("id") );

}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

void do_setup()
{
	int n;

	if(!clonep()
	|| !environment()
	|| (base_name(environment()) != query("startroom")))
		return;

	//n = 1440 - query_time();
	call_out("goto_sleep",30);
}

void goto_sleep()
{
	if(!environment())
		return;
	remove_call_out("goto_sleep");
	call_out("goto_sleep",1440);
	tell_room(environment(),sprintf("%s打了个哈嗤说道：“很晚了，我有点累了，要回去休息一下。\n”",
		name()));
	call_out("do_go",1,0,1);
}

void do_go(int step,int flag)
{
	remove_call_out("do_go");
	command(sprintf("go %s",(flag?to_sleep:go_back)[step]));
	if(++step < sizeof(flag?to_sleep:go_back))
	{
		call_out("do_go",1,step,flag);
		return;
	}
	else if(flag)
		command("sleep");
}

void have_wake_up()
{
	call_out("do_go",1,0,0);
}
