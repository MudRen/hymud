 //XXDER 菩提庵乃是神水宫的接引处麽 突见一条白影，就像是一片雪花般
//飘过来。 
//    夜凉如水，自山的那一边吹过来的晚风，轻柔得就如同天鹅的羽毛，淡淡的星光照在她 
//身上。她轻盈的身子彷佛溶於这温柔的秋夜中。     
inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h>
void create()
{
    set_name("宫南燕", ({ "gong nanyan"}) );
    
    set("gender", "女性");
    set("class", "shenshui");
    set("age", 21);
    set("long",
        "她是个很美丽的少女，穿着雪白的衣服，乌黑的长发和雪白的衣袂同
时在风中飘扬，看来是那麽超群绝俗。
");
    set("attitude", "peaceful");
    set("ill_boss",5);
    set("class", "shenshui");
    set("apprentice_available", 5);
    
    create_family("神水宫", 12, "接引使者");
    set("rank_nogen",1);
    set("ranks",({"第十三代弟子","侍女","小仙女","大仙女","神姬",RED"仙姬"NOR,RED"圣姬"NOR,
                      HIR"副掌门"NOR}));
    set("reward_npc", 1);
    set("difficulty", 5);
    set("inquiry", ([
        "leave" : (: leave :),
                ]));  
    set("int", 28);
    set("spi", 26);
    set("per", 35);
    set("cps", 30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.lianhuanbu" :),
            }) );
    set("force", 2200);
    set("max_neili", 2200);
    set("force_factor", 90); 
    set("combat_exp", 5000000);
    
    set("score", random(90000));
    set("env/wimpy", 25);
    set("env/savemyass", "perform suicidal");
    set_skill("unarmed", 120);
    set_skill("sword", 120);
    set_skill("force", 120);
    set_skill("parry", 120);
    set_skill("dodge", 120);
    set_skill("literate",120);

    set_skill("nine-moon-steps", 120);
    set_skill("nine-moon-claw", 120);
    set_skill("nine-moon-force", 120);
    set_skill("nine-moon-sword", 120); 
    map_skill("dodge", "nine-moon-steps");
    map_skill("unarmed", "nine-moon-claw");
    map_skill("force", "nine-moon-force");
    map_skill("sword", "nine-moon-sword"); 
    set_temp("apply/dodge", 100);
    set_temp("apply/attack", 100); 
    setup();
    carry_object(__DIR__"obj/white_cloth")->wear();
} 
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shenshui");
    add("apprentice_availavble", -1);
} 
void init()
{       
        ::init();
   add_action("do_killing", "kill");
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
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="shenshui") return 0;
        message_vision(CYN"$N冷笑了一声。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，但从此不能在江湖上使用九阴神功。\n"NOR,this_object(),this_player());
        return 1;
}    
