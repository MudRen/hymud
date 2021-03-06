 inherit NPC;
void create()
{
        set_name("陆小凤", ({ "lu", "lu xiaofeng" }) );
        set("gender", "男性");
        set("age", 34);
        set("title","心有灵犀一点通");
        set("long",
"四条眉毛的陆小凤\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        set("force", 1000);
        set("max_neili", 1000);
        set("force_factor", 50);
        set("no_arrest",1);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("int",51);
        set("cor",50);
        set("cps",60);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("skill_public",1);
        set("marks/悟出灵犀",1);
        
	set("qi", 14000);
	set("max_qi", 14000);
	set("jing", 11000);
	set("max_jing", 10100);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 50);
	set("combat_exp", 7500000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 280);
	set_skill("sword", 200);
	set_skill("tiannan-step", 280);
	set_skill("kurong-changong", 380);
	set_skill("duanjia-sword", 280);
	set_skill("six-finger", 380);
	set_skill("sun-finger", 380);
	set_skill("buddhism", 380);
	set_skill("literate", 100);
	set("book_give", 1);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("unarmed", "six-finger");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
(: perform_action, "unarmed.liumaijingshen" :),
	(: perform_action, "unarmed.qi" :),
		(: perform_action, "unarmed.zongheng" :),
                  (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

        
        set_temp("xinyoulingxi", 1); 
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
        if (this_player()->query("marks/救鹰眼")){
                command("say 多谢相救鹰眼老七.");
                if (!this_player()->query_skill("doomsword",1)){
                command ("say 无以为报，如不嫌弃，教你些功夫吧。");
                message_vision("$N看了看你道：“只是我的武功非极有恒心及天赋者不能练成。“\n",this_object());
                command ("say 你还是好好想一想吧，比我强的名师还有很多。\n");
                this_player()->set("marks/lu_teach",1);
                this_player()->delete("marks/救鹰眼");
                } else command ("say 可惜你是西门的传人,否则就传你点功夫了.");
        }
        if (this_player()->query("marks/kill_ximen") && this_player()->query_skill("lingxi-zhi")){
                command ("say 你竟然胜过了西门吹雪,来日定大有作为!!!");
                command ("say 我的绝技[心有灵犀]就传给你吧。");
                this_player()->set("marks/悟出灵犀",1);
                this_player()->delete("marks/kill_ximen");
                this_player()->delete("marks/won_lu");
        }
        add_action("do_killing", "kill");
                                                
} 
int recognize_apprentice(object ob){
        if ( (int)this_player()->query("marks/lu_teach")) {
                        return 1;
                }       
        return 0;
}  
void win_enemy(object loser)
{
    command("say 不成,不成！\n");
} 
void lose_enemy(object winner)
{
    if (this_player()->query_skill("lingxi-zhi")) {
    command("say 好!好!你的功夫快胜过我了,所欠只是火候而已。");
    winner->set("marks/won_lu",1);
    } else command ("say 阁下好身手!");
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(victim->query("id")=="lu" || victim->query("id")=="lu xiaofeng")
        {
            this_object()->remove_all_enemy();
            command ("say 好，我先对付你!");
            return 0;
        } 
    }
    return 0;
} 
int accept_fight(object me)
{
        object skinmask;
        object who;
        
        if (this_object()->is_fighting() || this_object()->is_busy())
                return notify_fail("陆小凤正在忙着呢，没空和你搭话！\n");
        who=this_object();
                
        if (who->query("qi")<who->query("max_qi") || who->query("eff_qi")<who->query("max_qi")
        || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing")
        || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing"))
                {
                        return notify_fail("陆小凤正在疗伤,没空理你.\n");
                } 
        return 1;
}    
