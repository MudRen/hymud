 inherit NPC;
void create()
{
        set_name("½С��", ({ "lu", "lu xiaofeng" }) );
        set("gender", "����");
        set("age", 34);
        set("title","������Ϭһ��ͨ");
        set("long",
"����üë��½С��\n"
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
        set("marks/�����Ϭ",1);
        
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
        if (this_player()->query("marks/��ӥ��")){
                command("say ��л���ӥ������.");
                if (!this_player()->query_skill("doomsword",1)){
                command ("say ����Ϊ�����粻����������Щ����ɡ�");
                message_vision("$N���˿��������ֻ���ҵ��书�Ǽ��к��ļ��츳�߲������ɡ���\n",this_object());
                command ("say �㻹�Ǻú���һ��ɣ�����ǿ����ʦ���кܶࡣ\n");
                this_player()->set("marks/lu_teach",1);
                this_player()->delete("marks/��ӥ��");
                } else command ("say ��ϧ�������ŵĴ���,����ʹ���㹦����.");
        }
        if (this_player()->query("marks/kill_ximen") && this_player()->query_skill("lingxi-zhi")){
                command ("say �㾹Ȼʤ�������Ŵ�ѩ,���ն�������Ϊ!!!");
                command ("say �ҵľ���[������Ϭ]�ʹ�����ɡ�");
                this_player()->set("marks/�����Ϭ",1);
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
    command("say ����,���ɣ�\n");
} 
void lose_enemy(object winner)
{
    if (this_player()->query_skill("lingxi-zhi")) {
    command("say ��!��!��Ĺ����ʤ������,��Ƿֻ�ǻ����ѡ�");
    winner->set("marks/won_lu",1);
    } else command ("say ���º�����!");
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(victim->query("id")=="lu" || victim->query("id")=="lu xiaofeng")
        {
            this_object()->remove_all_enemy();
            command ("say �ã����ȶԸ���!");
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
                return notify_fail("½С������æ���أ�û�պ�����\n");
        who=this_object();
                
        if (who->query("qi")<who->query("max_qi") || who->query("eff_qi")<who->query("max_qi")
        || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing")
        || who->query("jing")<who->query("max_jing") || who->query("eff_jing")<who->query("max_jing"))
                {
                        return notify_fail("½С����������,û������.\n");
                } 
        return 1;
}    
