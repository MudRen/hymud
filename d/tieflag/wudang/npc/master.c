 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("石雁", ({ "master shi", "master", "shi" }) );
    set("nickname", "五行真人");
    set("gender", "男性");
    set("age", 62);
    set("long",
        "石雁乃当代武当掌门，他的太极心法和三才剑法已炼到了极高的境界。\n"
        "他尤其精通太极五行，五行身法已是当世无双，所以人称［五行真人］。\n");
    set("combat_exp", 90000000);
    set("score", random (20000)); 
    set("class", "wudang");
    set("reward_npc", 1);
    set("difficulty", 40); 
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("fly_target",1);        
    
        
    set("inquiry", ([
        "太极心法": "太极心法乃道家入门的基本心法，能够调和体内的阴阳二气。\n",
        "武当派":   "我武当派自张真人开山立派至今，世世代代皆以行侠仗义为己任。\n",
        "七星法" :  "七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
        "qixing" :  "七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
    "leave" : (: leave :),
         ]) ); 
set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
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
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
    create_family("武当派", 57, "掌门人");
    set("rank_nogen",1);
    set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副掌门"NOR,
                      HIY"掌门"NOR})); 
  
    setup(); 
    carry_object(__DIR__"obj/msword")->wield();
    carry_object(__DIR__"obj/mcloth")->wear();
    carry_object(__DIR__"obj/mhat")->wear();
} 

int accept_object(object who, object ob)
{
    object              book; 
    if((string)ob->name() != "顾云飞的秘函") return 0;
    command("say 多谢这位" + RANK_D->query_respect(who));
    command("say 这本书你留作记念吧。");
    book = new(__DIR__"obj/wubook");
    book->move(this_object());
    command("give book to " + who->get_id());
    return 1;
}  
void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if(ob) 
        ob->set_temp("killed_master_shi",1);
    ::die();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob)
{
        object *inv,letter, *sy_inv, things;
        int i,j;
        int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
/*        if (ob->query("once_menpai/shaolin") && !ob->query("marks/muren_time")
                && !ob->query("marks/bugout") && ob->query("class")=="wudang"
                && ob->query("betrayer")==0)
        {
                ob->set("marks/bugout",1);
                letter = new(__DIR__"obj/letter1");
           if(letter) letter->move(ob);
                message_vision(HIW"啪地一声，$N从怀中掏出一封信扔在$n手里。\n"NOR,this_object(),ob);
                message_vision(HIW"$N说：自己去看吧。\n"NOR,this_object());
                ob->add("betrayer",1);
        } */
        if(ob->short() == "武当老掌门(wudang master)") {
//Okey, we got a old wudang master here, fake or real?
        inv =all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) 
         if(inv[i]->query("fake_7sword") && inv[i]->query("equipped")=="wielded"
                && inv[i]->query_temp("marks/owner_name") == ob->query("id")) 
                got_sword = 1;
        if(got_sword) {
        for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("name")=="面具") destruct(inv[i]);
        command("say 天哪！这，这，这是，是，老，老帮主么？\n");
        message_vision("$N突然一口鲜血喷了出来，惊吓得六神出窍，脸色土黑。。。一头栽倒在地下。\n",
        this_object());
        ob->set_temp("killed_master_shi",1);
        
        sy_inv = all_inventory(this_object());
        for(j=0;j<sizeof(sy_inv);j++){
                things = sy_inv[j];
                destruct(things);
        }
        this_object()->die();
        tell_object(ob,"现在可以去通知老刀把子了，别忘了带上井里的那把真剑。\n");
        
        } else {
        command("say 大胆！竟敢化妆成老帮主来吓唬老夫！\n");
        kill_ob(ob);
        } 
        }
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
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "wudang"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="wudang") return 0;
        message_vision(CYN"$N怒道：不成器的家伙给我滚开！\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，这太极五行的武当秘技你就别想再用了。\n"NOR,this_object(),this_player());
        message_vision(CYN"$N说：以后也别再来见我！\n"NOR,this_object(),this_player());
        return 1;
}
