 // taolord.c
inherit NPC;
inherit F_MASTER;

#include <ansi.h> 
void create()
{
    set_name("丁乘风", ({ "master ding", "master", "ding chengfeng" }) );
    set("nickname", HIG"碧海乘风" NOR);
    set("gender", "男性");
    set("age", 47);
    set("long","丁乘风原本出身武林世家，但从小好学，擅长钻研心法，\n"
        "于是隐居于此精修成仙降魔之道。\n");
    
    set("combat_exp", 10000000);
    set("score", 20000); 
    set("class", "taoist"); 
    set("str", 60);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("reward_npc", 1);
        set("difficulty", 20); 
    set("force", 2000);
    set("max_neili", 1000);
    set("force_factor", 30);
//  set("fly_target",1);
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
    set("inquiry", ([
        "谷衣心法": 
        "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
        "三清宫": 
        "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
        ]) ); 
    set("apprentice_available", 3);
    create_family("三清宫", 5, "主持");
    set("rank_nogen",1);
    set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副主持"NOR,
                      HIY"主持"NOR})); 
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
			map_skill("strike", "yitian-zhang");
    
	setup();
    carry_object(__DIR__"obj/sword")->wield();
    carry_object(__DIR__"obj/robe")->wear();
    carry_object(__DIR__"obj/hat")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
} 

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
    add("apprentice_availavble", -1);
} 
void init()
{       
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing", "kill");
} 
void greeting(object me)
{
        object ob,*inv, ding;
        
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        
                
        if (me->query("class")=="taoist" 
                && me->query("gender")=="男性" && 
                me->query("combat_exp")>1000000)        {
                
                inv = all_inventory(me);
                
                if  ( sizeof(inv) >= 15) 
                        return;
        
                if (present("ding",me)) return;
                
                message_vision(CYN"$N对$n说：“你跟随为师多年，今日传你一宝鼎，望你能光大师门。”\n"NOR,ob,me);
                ding= new(__DIR__"obj/ding_baby");
                if (me->query("combat_exp")>5000000) {
                        ding->set("name",RED"红木宝鼎"NOR);
                        ding->set_max_encumbrance(200);
                } else if (me->query("combat_exp")>3000000) {
                   ding->set("name",YEL"黄木宝鼎"NOR);
                        ding->set_max_encumbrance(100);
                } else {
                        ding->set("name",HIC"青木宝鼎"NOR);
                        ding->set_max_encumbrance(50);
                }
                ding->move(me);
                message_vision("$N从怀里取出一口"+ding->name()+"递给$n。\n",ob,me);     
                return;
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
        if(id_class == "taoist" && userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="taoist") return 0;
   message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
        return 1;
}  
int marriage () {
        if (this_player()->query("once_menpai/sanqing")){
                message_vision(CYN"$N道，凡我门人，当养生修道，莫要儿女情长。\n"NOR,this_object());
                message_vision(CYN"$N又道：若你执意为此要下山我也不能勉强，只是俗念一生，回头就难，切记！\n"NOR, this_object());
                this_player()->delete("once_sanqing");
                return 1;
        }
        return 0;
}  
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/丁乘风_ma", 1);
        }
        
        ::die(); 

}
