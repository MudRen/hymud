// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

string ask_me();
int ask_wldh();
void create()
{
	set_name("宋远桥", ({ "song yuanqiao", "song" }));
	set("nickname", "武当首侠");
	set("long", 
		"他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
		"身穿一件干干净净的灰色道袍。\n"
		"他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 7000);
	set("max_jing", 7000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 60000);
        set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 180);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 180);
	set_skill("wudang-jian", 180);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 180);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");
	create_family("武当派", 2, "弟子");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set("inquiry", ([
		"秘籍" : (: ask_me :),
		"张翠山夫妇" : (: ask_wldh() :),
	        "谢逊" : (: ask_wldh() :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 100){
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到太极十三式啦。\n");
	return "好吧，这本「太极十三式」你拿回去好好钻研。";
}



int ask_wldh()
{

        object me = this_player();
        object ob,where,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
	
        int i, skill = 0;
	
        ob=this_object();
        who=me;
        where = environment(who);
        if(((int)me->query("jinyong/book12")!=1))
           {
                      message_vision("$N对着$n说道。暂时没有我五弟的消息。\n", this_object(), me);
	                      return 1;
            }



                command("bow " + me->query("id"));
                message_vision("$N对着$n说道。五弟已经回来了，但五大派上门来讨要谢逊的下落！\n", this_object(), me);
                message_vision("$N对着$n说道。我们合力打败他们吧！\n", this_object(), me);
                //command("say " + me->query("id") + "我五弟已经回来了，但五大派上门来讨要谢逊的下落！" NOR);
                //command("say " + me->query("id") + "我们合力打败他们吧！" NOR);
                call_out("leavet",1);

                return 1;
                             
}
void leavet()
{
        object ob = this_player();
 ob->move("/d/wudang/yttl");
 //message_vision("$N飞身向外逃去！\n" NOR,this_object());
 //       destruct(this_object());
}  